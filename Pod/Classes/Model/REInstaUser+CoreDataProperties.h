//
//  REInstaUser+CoreDataProperties.h
//  Pods
//
//  Created by Rinat Enikeev on 17/11/15.
//
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "REInstaUser.h"

NS_ASSUME_NONNULL_BEGIN

@interface REInstaUser (CoreDataProperties)

@property (nullable, nonatomic, retain) NSString *identifier;
@property (nullable, nonatomic, retain) NSString *username;
@property (nullable, nonatomic, retain) NSString *fullName;
@property (nullable, nonatomic, retain) NSString *bio;
@property (nullable, nonatomic, retain) NSString *profilePictureUrl;
@property (nullable, nonatomic, retain) NSString *profilePictureLocalPath;
@property (nullable, nonatomic, retain) NSString *website;
@property (nullable, nonatomic, retain) NSNumber *followsCount;
@property (nullable, nonatomic, retain) NSNumber *followedByCount;
@property (nullable, nonatomic, retain) NSNumber *mediaCount;
@property (nullable, nonatomic, retain) NSString *firstName;
@property (nullable, nonatomic, retain) NSString *lastName;
@property (nullable, nonatomic, retain) NSSet<REInstaCaption *> *captions;
@property (nullable, nonatomic, retain) NSSet<REInstaComment *> *comments;
@property (nullable, nonatomic, retain) NSSet<REInstaPost *> *likes;
@property (nullable, nonatomic, retain) NSSet<REInstaPost *> *posts;
@property (nullable, nonatomic, retain) NSSet<REInstaRelationship *> *relationships;
@property (nullable, nonatomic, retain) NSSet<REInstaRelationship *> *relationshipRequests;
@property (nullable, nonatomic, retain) NSSet<REInstaUserOnPost *> *onPostPhotos;

@end

@interface REInstaUser (CoreDataGeneratedAccessors)

- (void)addCaptionsObject:(REInstaCaption *)value;
- (void)removeCaptionsObject:(REInstaCaption *)value;
- (void)addCaptions:(NSSet<REInstaCaption *> *)values;
- (void)removeCaptions:(NSSet<REInstaCaption *> *)values;

- (void)addCommentsObject:(REInstaComment *)value;
- (void)removeCommentsObject:(REInstaComment *)value;
- (void)addComments:(NSSet<REInstaComment *> *)values;
- (void)removeComments:(NSSet<REInstaComment *> *)values;

- (void)addLikesObject:(REInstaPost *)value;
- (void)removeLikesObject:(REInstaPost *)value;
- (void)addLikes:(NSSet<REInstaPost *> *)values;
- (void)removeLikes:(NSSet<REInstaPost *> *)values;

- (void)addPostsObject:(REInstaPost *)value;
- (void)removePostsObject:(REInstaPost *)value;
- (void)addPosts:(NSSet<REInstaPost *> *)values;
- (void)removePosts:(NSSet<REInstaPost *> *)values;

- (void)addRelationshipsObject:(REInstaRelationship *)value;
- (void)removeRelationshipsObject:(REInstaRelationship *)value;
- (void)addRelationships:(NSSet<REInstaRelationship *> *)values;
- (void)removeRelationships:(NSSet<REInstaRelationship *> *)values;

- (void)addRelationshipRequestsObject:(REInstaRelationship *)value;
- (void)removeRelationshipRequestsObject:(REInstaRelationship *)value;
- (void)addRelationshipRequests:(NSSet<REInstaRelationship *> *)values;
- (void)removeRelationshipRequests:(NSSet<REInstaRelationship *> *)values;

- (void)addOnPostPhotosObject:(REInstaUserOnPost *)value;
- (void)removeOnPostPhotosObject:(REInstaUserOnPost *)value;
- (void)addOnPostPhotos:(NSSet<REInstaUserOnPost *> *)values;
- (void)removeOnPostPhotos:(NSSet<REInstaUserOnPost *> *)values;

@end

NS_ASSUME_NONNULL_END
