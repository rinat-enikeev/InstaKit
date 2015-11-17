//
//  REInstaTag+CoreDataProperties.h
//  Pods
//
//  Created by Rinat Enikeev on 17/11/15.
//
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "REInstaTag.h"

NS_ASSUME_NONNULL_BEGIN

@interface REInstaTag (CoreDataProperties)

@property (nullable, nonatomic, retain) NSString *name;
@property (nullable, nonatomic, retain) NSSet<REInstaPost *> *posts;

@end

@interface REInstaTag (CoreDataGeneratedAccessors)

- (void)addPostsObject:(REInstaPost *)value;
- (void)removePostsObject:(REInstaPost *)value;
- (void)addPosts:(NSSet<REInstaPost *> *)values;
- (void)removePosts:(NSSet<REInstaPost *> *)values;

@end

NS_ASSUME_NONNULL_END
