//
//  InstaKit.h
//  Pods
//
//  Created by Rinat Enikeev on 17/11/15.
//
//

#import "REInstaAttribution.h"
#import "REInstaAttribution+CoreDataProperties.h"
#import "REInstaCaption.h"
#import "REInstaCaption+CoreDataProperties.h"
#import "REInstaComment.h"
#import "REInstaComment+CoreDataProperties.h"
#import "REInstaImage.h"
#import "REInstaImage+CoreDataProperties.h"
#import "REInstaLocation.h"
#import "REInstaLocation+CoreDataProperties.h"
#import "REInstaPost.h"
#import "REInstaPost+CoreDataProperties.h"
#import "REInstaRelationship.h"
#import "REInstaRelationship+CoreDataProperties.h"
#import "REInstaTag.h"
#import "REInstaTag+CoreDataProperties.h"
#import "REInstaUser.h"
#import "REInstaUser+CoreDataProperties.h"
#import "REInstaUserOnPost.h"
#import "REInstaUserOnPost+CoreDataProperties.h"
#import "REInstaVideo.h"
#import "REInstaVideo+CoreDataProperties.h"

#import <Foundation/Foundation.h>
#import "REInstaPostService.h"

@interface InstaKit : NSObject

@property (strong, nonatomic, readonly) REInstaPostService* postService;

-(id)initWithClientId:(NSString* )clientId dbFileName:(NSString *)dbFileName;

@end
