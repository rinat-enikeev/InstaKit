//
//  STXViewController.m
//  STXInstagramFeedView
//
//  Created by Rinat Enikeev on 11/16/2015.
//  Copyright (c) 2015 Rinat Enikeev. All rights reserved.
//

#import "STXFeedViewController.h"
#import <STXInstagramFeedView/STXDynamicTableView.h>
#import <InstaKit/InstaKit.h>
#import <InstaModel/InstaModel.h>
#import <Reachability/Reachability.h>
#import <TSMessages/TSMessage.h>
#import "UIViewController+InformUser.h"

NSString *const kInstagramBaseUrl = @"instagram.com";

@interface STXFeedViewController () <STXFeedPhotoCellDelegate, STXLikesCellDelegate, STXCaptionCellDelegate, STXCommentCellDelegate, STXUserActionDelegate>

// views
@property (strong, nonatomic) UIActivityIndicatorView *activityIndicatorView;

// services
@property (strong, nonatomic) InstaKit* instaKit;

// instagram-like feed support
@property (strong, nonatomic) STXFeedTableViewDataSource *tableViewDataSource;
@property (strong, nonatomic) STXFeedTableViewDelegate *tableViewDelegate;

// configuration
@property (strong, nonatomic) NSNumber* fetchedPostsLimit;

@end

@implementation STXFeedViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.instaKit = [[InstaKit alloc] initWithClientId:@"24fc1af302d3442c86e5e3c1e8708015" dbFileName:@"dbFile"];
    self.fetchedPostsLimit = @10;
    
    self.title = NSLocalizedString(@"Feed", nil);
    self.tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
    
    // 1. Delegate UITableView datasource and delegate to STX.
    STXFeedTableViewDataSource *dataSource = [[STXFeedTableViewDataSource alloc] initWithController:self tableView:self.tableView];
    self.tableView.dataSource = dataSource;
    self.tableViewDataSource = dataSource;
    
    STXFeedTableViewDelegate *delegate = [[STXFeedTableViewDelegate alloc] initWithController:self];
    self.tableView.delegate = delegate;
    self.tableViewDelegate = delegate;
    
    // 2. Centered in table view screen activity indicator
    self.activityIndicatorView = [self activityIndicatorViewOnView:self.view];
    
    // 3. Refresh Control
    self.refreshControl = [[UIRefreshControl alloc] init];
    [self.refreshControl addTarget:self action:@selector(updateFeed) forControlEvents:UIControlEventValueChanged];

    
}

- (void)dealloc
{
    // To prevent crash when popping this from navigation controller
    self.tableView.delegate = nil;
    self.tableView.dataSource = nil;
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    // This will be notified when the Dynamic Type user setting changes (from the system Settings app)
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(contentSizeCategoryChanged:) name:UIContentSizeCategoryDidChangeNotification object:nil];
    
    if ([self.tableViewDataSource.posts count] == 0) {
        [self.activityIndicatorView startAnimating];
        NSUInteger fetchedPostsCount = [self fetchFeed:[_fetchedPostsLimit integerValue]];
        
        if (fetchedPostsCount < 1) {
            [self.activityIndicatorView startAnimating];
            [self updateFeed];
        }
    }
    
    
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIContentSizeCategoryDidChangeNotification object:nil];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

- (void)contentSizeCategoryChanged:(NSNotification *)notification
{
    [self.tableView reloadData];
}

#pragma mark - STXFeedPhotoCellDelegate
- (void)feedCellWillBeDisplayed:(STXFeedPhotoCell *)cell
{

    NSObject<InstaImage>* imgStd = cell.postItem.imageStd;
    if (imgStd.localPath == nil) {
        
        if ([[Reachability reachabilityForInternetConnection] isReachable]) {
            [[_instaKit blobService] renewImageBlobFor:imgStd withProgress:nil success:^(NSObject<InstaImage> *image) {
                [self updateStdImageInPost:cell];
            } failure:^(NSError *error) {
                NSLog(@"%@", error.localizedDescription);
            }];
        } else {
            cell.postImageView.image = [UIImage imageNamed:@"InstagramPhotoPostPlaceholderImage"];
        }
    } else {
        [self updateStdImageInPost:cell];
    }
    
    NSObject<InstaUser>* author = cell.postItem.author;
    if (author.profilePictureLocalPath == nil) {
        if ([[Reachability reachabilityForInternetConnection] isReachable]) {
            [[_instaKit blobService] renewProfileImageBlobFor:author withProgress:nil success:^(NSObject<InstaUser> *user) {
                [self updateProfilePictureIn:cell];
            } failure:^(NSError *error) {
                NSLog(@"%@", error.localizedDescription);
            }];
        } else {
            [cell.profileImageView setCircledImageFrom:[UIImage imageNamed:@"InstagramPhotoPostPlaceholderImage"] placeholderImage:[UIImage imageNamed:@"InstagramPhotoPostPlaceholderImage"] borderWidth:2];
        }
        
    } else {
        [self updateProfilePictureIn:cell];
    }
}

/**
 *  @brief  Assume thatcell.postItem.imageStd.localPath is not null.
 */
-(void)updateStdImageInPost:(STXFeedPhotoCell *)cell {
    NSObject<InstaImage>* imgStd = cell.postItem.imageStd;
    dispatch_async(dispatch_get_global_queue( DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        UIImage* postStdImage = [UIImage imageWithContentsOfFile:[self documentsPathForFileName:imgStd.localPath]];
        dispatch_async(dispatch_get_main_queue(), ^(void){
            cell.postImageView.image = postStdImage;
        });
    });
}

/**
 *  @brief  Assume that cell.postItem.author.profilePictureLocalPath is not null.
 */
-(void)updateProfilePictureIn:(STXFeedPhotoCell *)cell {
    NSObject<InstaUser>* author = cell.postItem.author;
    dispatch_async(dispatch_get_global_queue( DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        UIImage* authorImage = [UIImage imageWithContentsOfFile:[self documentsPathForFileName:author.profilePictureLocalPath]];
        dispatch_async(dispatch_get_main_queue(), ^(void){
            [cell.profileImageView setCircledImageFrom:authorImage placeholderImage:[UIImage imageNamed:@"InstagramPhotoPostPlaceholderImage"] borderWidth:2];
        });
    });
}


#pragma mark - Data updates

/**
 *  @brief  Updates feed based on internet reachability and inform user appropriately.
 */
-(void)updateFeed {
    
    if ([[Reachability reachabilityForInternetConnection] isReachable]) {
        [self renewFeed];
    } else {
        [self informUserWithWarnMessage:NSLocalizedString(@"Internet connection unavaliable. ", @"Internet connection unavaliable. ") withTitle:NSLocalizedString(@"Warning", @"Warning")];
        
        [self fetchFeed:self.fetchedPostsLimit.integerValue];
    }
}

/**
 *  @brief  Fetches posts from persistence.
 *
 *  @param limit maximum number of posts to fetch.
 *
 *  @return number of posts fetched.
 */
-(NSUInteger)fetchFeed:(NSUInteger)limit {

    NSArray<NSSortDescriptor *>* sds = @[[[NSSortDescriptor alloc] initWithKey:@"likesCount" ascending:false]];

    NSError* error = nil;
    NSArray* posts = [[_instaKit postService] fetchPostsWithPredicate:nil sortDescriptors:sds limit:limit error:&error];
    
    if (error != nil) {
        [self informUserWithErrorMessage:error.localizedDescription withTitle:NSLocalizedString(@"Error", @"Error")];
    } else {
        self.tableViewDataSource.posts = [posts copy];
        [self.tableView reloadData];
    }

    [self.activityIndicatorView stopAnimating];
    [self.refreshControl endRefreshing];
    
    return [posts count];
}

/**
 *  @brief  Downloads last popular posts from Instagram.
 */
- (void)renewFeed
{
    [[_instaKit postService] renewMediaPopularWithProgress:nil success:^(NSArray *objects) {
        self.tableViewDataSource.posts = [objects copy];
        [self.tableView reloadData];
        [self.activityIndicatorView stopAnimating];
        [self.refreshControl endRefreshing];
    } failure:^(NSError *error) {
        [self.activityIndicatorView stopAnimating];
        [self.refreshControl endRefreshing];
        NSLog(@"%@", error);
    }];
}

#pragma mark - User Action Cell

- (void)userDidLike:(STXUserActionCell *)userActionCell
{
    
}

- (void)userDidUnlike:(STXUserActionCell *)userActionCell
{
    
}

- (void)userWillComment:(STXUserActionCell *)userActionCell
{
    
}

- (void)userWillShare:(STXUserActionCell *)userActionCell
{
    
}

// todo MOVE somewhere
- (NSString *)documentsPathForFileName:(NSString *)name
{
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask, YES);
    NSString *documentsPath = [paths objectAtIndex:0];
    
    return [documentsPath stringByAppendingPathComponent:name];
}

@end
