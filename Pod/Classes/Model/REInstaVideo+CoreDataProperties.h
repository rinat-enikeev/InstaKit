//
//  REInstaVideo+CoreDataProperties.h
//  Pods
//
//  Created by Rinat Enikeev on 17/11/15.
//
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "REInstaVideo.h"

NS_ASSUME_NONNULL_BEGIN

@interface REInstaVideo (CoreDataProperties)

@property (nullable, nonatomic, retain) NSNumber *height;
@property (nullable, nonatomic, retain) NSString *localPath;
@property (nullable, nonatomic, retain) NSString *url;
@property (nullable, nonatomic, retain) NSNumber *width;
@property (nullable, nonatomic, retain) NSSet<REInstaPost *> *postLowBand;
@property (nullable, nonatomic, retain) NSSet<REInstaPost *> *postLowRes;
@property (nullable, nonatomic, retain) NSSet<REInstaPost *> *postStdRes;

@end

@interface REInstaVideo (CoreDataGeneratedAccessors)

- (void)addPostLowBandObject:(REInstaPost *)value;
- (void)removePostLowBandObject:(REInstaPost *)value;
- (void)addPostLowBand:(NSSet<REInstaPost *> *)values;
- (void)removePostLowBand:(NSSet<REInstaPost *> *)values;

- (void)addPostLowResObject:(REInstaPost *)value;
- (void)removePostLowResObject:(REInstaPost *)value;
- (void)addPostLowRes:(NSSet<REInstaPost *> *)values;
- (void)removePostLowRes:(NSSet<REInstaPost *> *)values;

- (void)addPostStdResObject:(REInstaPost *)value;
- (void)removePostStdResObject:(REInstaPost *)value;
- (void)addPostStdRes:(NSSet<REInstaPost *> *)values;
- (void)removePostStdRes:(NSSet<REInstaPost *> *)values;

@end

NS_ASSUME_NONNULL_END
