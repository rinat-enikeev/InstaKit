//
//  REInstaImage+CoreDataProperties.h
//  Pods
//
//  Created by Rinat Enikeev on 17/11/15.
//
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "REInstaImage.h"

NS_ASSUME_NONNULL_BEGIN

@interface REInstaImage (CoreDataProperties)

@property (nullable, nonatomic, retain) NSNumber *height;
@property (nullable, nonatomic, retain) NSString *localPath;
@property (nullable, nonatomic, retain) NSString *url;
@property (nullable, nonatomic, retain) NSNumber *width;
@property (nullable, nonatomic, retain) NSSet<REInstaPost *> *postLow;
@property (nullable, nonatomic, retain) NSSet<REInstaPost *> *postStd;
@property (nullable, nonatomic, retain) NSSet<REInstaPost *> *postThumb;

@end

@interface REInstaImage (CoreDataGeneratedAccessors)

- (void)addPostLowObject:(REInstaPost *)value;
- (void)removePostLowObject:(REInstaPost *)value;
- (void)addPostLow:(NSSet<REInstaPost *> *)values;
- (void)removePostLow:(NSSet<REInstaPost *> *)values;

- (void)addPostStdObject:(REInstaPost *)value;
- (void)removePostStdObject:(REInstaPost *)value;
- (void)addPostStd:(NSSet<REInstaPost *> *)values;
- (void)removePostStd:(NSSet<REInstaPost *> *)values;

- (void)addPostThumbObject:(REInstaPost *)value;
- (void)removePostThumbObject:(REInstaPost *)value;
- (void)addPostThumb:(NSSet<REInstaPost *> *)values;
- (void)removePostThumb:(NSSet<REInstaPost *> *)values;

@end

NS_ASSUME_NONNULL_END
