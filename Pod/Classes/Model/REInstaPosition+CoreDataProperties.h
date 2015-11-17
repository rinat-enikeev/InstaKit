//
//  REInstaPosition+CoreDataProperties.h
//  Pods
//
//  Created by Rinat Enikeev on 17/11/15.
//
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "REInstaPosition.h"

NS_ASSUME_NONNULL_BEGIN

@interface REInstaPosition (CoreDataProperties)

@property (nullable, nonatomic, retain) NSNumber *x;
@property (nullable, nonatomic, retain) NSNumber *y;
@property (nullable, nonatomic, retain) REInstaUserOnPost *userOnPost;

@end

NS_ASSUME_NONNULL_END
