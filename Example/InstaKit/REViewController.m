//
//  REViewController.m
//  InstaKit
//
//  Created by Rinat Enikeev on 11/17/2015.
//  Copyright (c) 2015 Rinat Enikeev. All rights reserved.
//

#import "REViewController.h"
#import <InstaKit/InstaKit.h>
#import <InstaModel/InstaModel.h>
@interface REViewController ()

@end

@implementation REViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    InstaKit* kit = [[InstaKit alloc] initWithClientId:@"24fc1af302d3442c86e5e3c1e8708015" dbFileName:@"dbFile"];
    [[kit postService] renewMediaPopularWithProgress:nil success:^(NSArray *objects) {
        for (NSObject<InstaPost> *post in objects) {
//            NSLog(@"id: %@", post.identifier);
//            NSLog(@"comments count: %@", post.commentsCount);
//            NSLog(@"likes count: %@", post.likesCount);
//            NSLog(@"filter: %@", post.filter);
//            NSLog(@"type: %@", post.type);
//            NSObject<InstaUser> * user = post.author;
//            NSLog(@"username: %@", user.username);
//            NSOrderedSet<NSObject<InstaComment> *>* comments = post.comments;
//            for (NSObject<InstaComment> * comment in comments) {
//                NSLog(@"liker: %@", comment.text);
//            }
//            NSObject<InstaImage>* image = post.imageStd;
//            [[kit blobService] renewImageBlobFor:image withProgress:^(NSUInteger bytes, long long totalBytes, long long totalBytesExpected) {
//                NSLog(@"Progress: %tu / %lld", bytes, totalBytes);
//            } success:^(NSObject<InstaImage> *img) {
//                NSLog(@"%@", img.localPath);
//                UIImage* image = [UIImage imageWithContentsOfFile:img.localPath];
//                NSAssert(image != nil, @"Image downloaded");
//            } failure:^(NSError *error) {
//                NSLog(@"%@", error.localizedDescription);
//            }];
            
            
            NSObject<InstaUser>* user = post.author;
            [[kit blobService] renewProfileImageBlobFor:user withProgress:^(NSUInteger bytes, long long totalBytes, long long totalBytesExpected) {
                NSLog(@"Progress: %tu / %lld", bytes, totalBytes);
            } success:^(NSObject<InstaUser> *user) {
                NSLog(@"%@", user.profilePictureLocalPath);
                UIImage* image = [UIImage imageWithContentsOfFile:user.profilePictureLocalPath];
                NSAssert(image != nil, @"Image downloaded");
            } failure:^(NSError *error) {
                NSLog(@"%@", error.localizedDescription);
            }];
            
        }
    } failure:^(NSError *error) {
        NSLog(@"%@", error.localizedDescription);
    }];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
