//
//  InstaKit.h
//  Pods
//
//  Created by Rinat Enikeev on 17/11/15.
//
//

#import <Foundation/Foundation.h>
#import "REInstaPostService.h"

@interface InstaKit : NSObject

@property (strong, nonatomic, readonly) REInstaPostService* postService;

-(id)initWithClientId:(NSString* )clientId dbFileName:(NSString *)dbFileName;

@end
