//
//  REBlockDefinitions.h
//  Pods
//
//  Created by Rinat Enikeev on 17/11/15.
//
//

#ifndef REBlockDefinitions_h
#define REBlockDefinitions_h


typedef void (^REProgressBlock)(NSUInteger bytes, long long totalBytes, long long totalBytesExpected);
typedef void (^RESuccessBlock)(NSArray* objects);
typedef void (^REFailureBlock)(NSError* error);


#endif /* REBlockDefinitions_h */
