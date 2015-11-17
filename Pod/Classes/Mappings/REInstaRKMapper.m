//
//  REInstaRKMapper.m
//  Pods
//
//  Created by Rinat Enikeev on 17/11/15.
//
//

#import "REInstaRKMapper.h"
#import "REInstaPost.h"
#import <RestKit/RestKit.h>

@implementation REInstaRKMapper

-(void)mapPostDeep {
    RKObjectMapping* articleMapping = [RKObjectMapping mappingForClass:[REInstaPost class]];
    [articleMapping addAttributeMappingsFromDictionary:@{
                                                         @"title": @"title",
                                                         @"body": @"body",
                                                         @"author": @"author",
                                                         @"publication_date": @"publicationDate"
                                                         }];
    
    RKResponseDescriptor *responseDescriptor = [RKResponseDescriptor responseDescriptorWithMapping:articleMapping method:RKRequestMethodAny pathPattern:nil keyPath:@"articles" statusCodes:RKStatusCodeIndexSetForClass(RKStatusCodeClassSuccessful)];
}

@end
