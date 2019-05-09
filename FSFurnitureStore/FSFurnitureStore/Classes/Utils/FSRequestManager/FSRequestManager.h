//
//  FSRequestManager.h
//  FSFurnitureStore
//
//  Created by TAN on 16/10/26.
//  Copyright © 2016年 TAN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FSHttpResult.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^Success)(id _Nullable responseObj);
typedef void(^Failure)(NSError * _Nonnull error);
typedef void(^Progress)(NSProgress * _Nonnull progress);

@interface FSRequestManager : NSObject

+ (instancetype)manager;

- (NSURLSessionDataTask *)GET:(NSString * )URLString
                   parameters:(nullable id)parameters
                      success:(Success)success
                      failure:(Failure)failure;

- (nullable NSURLSessionDataTask *)POST:(NSString *)URLString
                             parameters:(nullable id)parameters
                                success:(Success)success
                                failure:(Failure)failure;


- (NSURLSessionDataTask *)GET:(NSString *)URLString
                   parameters:(nullable id)parameters
                     progress:(nullable Progress)downloadProgress
                      success:(Success)success
                      failure:(Failure)failure;

- (nullable NSURLSessionDataTask *)POST:(NSString *)URLString
                             parameters:(nullable id)parameters
                               progress:(nullable Progress)uploadProgress
                                success:(Success)success
                                failure:(Failure)failure;

- (void)startGET:(NSString *)URLString
      parameters:(nullable id)parameters
        progress:(nullable Progress)progress
         success:(void(^)(_Nonnull id response))success
         failure:(void(^)(NSError *error))failure;

- (void)startPOST:(NSString *)URLString
       parameters:(nullable id)parameters
         progress:(nullable Progress)progress
          success:(void(^)(_Nonnull id response))success
          failure:(void(^)(NSError *error))failure;


@end

NS_ASSUME_NONNULL_END
