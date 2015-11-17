//
//  REInstaCaption+CoreDataProperties.h
//  Pods
//
//  Created by Rinat Enikeev on 17/11/15.
//
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "REInstaCaption.h"

NS_ASSUME_NONNULL_BEGIN

@interface REInstaCaption (CoreDataProperties)

@property (nullable, nonatomic, retain) NSNumber *createdTimestamp;
@property (nullable, nonatomic, retain) NSString *identifier;
@property (nullable, nonatomic, retain) NSString *text;
@property (nullable, nonatomic, retain) REInstaUser *from;

@end

NS_ASSUME_NONNULL_END