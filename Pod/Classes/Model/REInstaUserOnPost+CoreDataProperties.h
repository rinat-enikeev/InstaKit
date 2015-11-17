//
//  REInstaUserOnPost+CoreDataProperties.h
//  Pods
//
//  Created by Rinat Enikeev on 17/11/15.
//
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "REInstaUserOnPost.h"

NS_ASSUME_NONNULL_BEGIN

@interface REInstaUserOnPost (CoreDataProperties)

@property (nullable, nonatomic, retain) REInstaUser *user;
@property (nullable, nonatomic, retain) REInstaPost *post;
@property (nullable, nonatomic, retain) NSManagedObject *position;

@end

NS_ASSUME_NONNULL_END
