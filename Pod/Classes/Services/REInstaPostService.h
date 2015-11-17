//
//  REInstaPostService.h
//  Pods
//
//  Created by Rinat Enikeev on 17/11/15.
//
//

#import <Foundation/Foundation.h>
#import "REBlockDefinitions.h"

@interface REInstaPostService : NSObject

/**
 *  @brief  Loads most recent media popular posts from Instagram.
 *
 *  @param progress download progress (in bytes).
 *  @param success  returns an array of popular REInstaPost's.
 *  @param failure  returns a error, if present. 
 */
- (void)renewMediaPopularWithProgress:(REProgressBlock)progress success:(RESuccessBlock)success failure:(REFailureBlock)failure;

@end
