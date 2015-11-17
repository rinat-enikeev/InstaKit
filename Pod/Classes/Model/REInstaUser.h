//
//  REInstaUser.h
//  Pods
//
//  Created by Rinat Enikeev on 17/11/15.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class REInstaCaption, REInstaComment, REInstaPost, REInstaRelationship, REInstaUserOnPost;

NS_ASSUME_NONNULL_BEGIN

@interface REInstaUser : NSManagedObject

// Insert code here to declare functionality of your managed object subclass

@end

NS_ASSUME_NONNULL_END

#import "REInstaUser+CoreDataProperties.h"
