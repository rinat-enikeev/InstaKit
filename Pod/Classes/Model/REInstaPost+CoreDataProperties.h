//
//  REInstaPost+CoreDataProperties.h
//  Pods
//
//  Created by Rinat Enikeev on 17/11/15.
//
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "REInstaPost.h"

NS_ASSUME_NONNULL_BEGIN

@interface REInstaPost (CoreDataProperties)

@property (nullable, nonatomic, retain) NSNumber *commentsCount;
@property (nullable, nonatomic, retain) NSNumber *createdTimestamp;
@property (nullable, nonatomic, retain) NSString *filter;
@property (nullable, nonatomic, retain) NSString *identifier;
@property (nullable, nonatomic, retain) NSNumber *likesCount;
@property (nullable, nonatomic, retain) NSString *link;
@property (nullable, nonatomic, retain) NSString *type;
@property (nullable, nonatomic, retain) NSNumber *userHasLiked;
@property (nullable, nonatomic, retain) NSNumber *distance;
@property (nullable, nonatomic, retain) REInstaUser *author;
@property (nullable, nonatomic, retain) REInstaCaption *caption;
@property (nullable, nonatomic, retain) REInstaImage *imageLow;
@property (nullable, nonatomic, retain) REInstaImage *imageStd;
@property (nullable, nonatomic, retain) REInstaImage *imageThumb;
@property (nullable, nonatomic, retain) NSSet<REInstaUser *> *likers;
@property (nullable, nonatomic, retain) NSSet<REInstaTag *> *tags;
@property (nullable, nonatomic, retain) REInstaVideo *videoLowBand;
@property (nullable, nonatomic, retain) REInstaVideo *videoLowRes;
@property (nullable, nonatomic, retain) REInstaVideo *videoStdRes;
@property (nullable, nonatomic, retain) REInstaAttribution *attribution;
@property (nullable, nonatomic, retain) NSSet<REInstaUserOnPost *> *usersOnPost;

@end

@interface REInstaPost (CoreDataGeneratedAccessors)

- (void)addLikersObject:(REInstaUser *)value;
- (void)removeLikersObject:(REInstaUser *)value;
- (void)addLikers:(NSSet<REInstaUser *> *)values;
- (void)removeLikers:(NSSet<REInstaUser *> *)values;

- (void)addTagsObject:(REInstaTag *)value;
- (void)removeTagsObject:(REInstaTag *)value;
- (void)addTags:(NSSet<REInstaTag *> *)values;
- (void)removeTags:(NSSet<REInstaTag *> *)values;

- (void)addUsersOnPostObject:(REInstaUserOnPost *)value;
- (void)removeUsersOnPostObject:(REInstaUserOnPost *)value;
- (void)addUsersOnPost:(NSSet<REInstaUserOnPost *> *)values;
- (void)removeUsersOnPost:(NSSet<REInstaUserOnPost *> *)values;

@end

NS_ASSUME_NONNULL_END
