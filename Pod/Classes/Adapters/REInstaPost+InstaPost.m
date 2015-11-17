//
//  REInstaPost+InstaPost.m
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#import "REInstaPost+InstaPost.h"

@implementation REInstaPost (InstaPostAdapter)

-(NSDate*)created {
    // checkme instagram timestamp in sec or ms? if ms - divide by 1000
    return [NSDate dateWithTimeIntervalSince1970:[[self createdTimestamp] doubleValue]];
}

@end
