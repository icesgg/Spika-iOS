/*
 The MIT License (MIT)
 
 Copyright (c) 2013 Clover Studio Ltd. All rights reserved.
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

#import <Foundation/Foundation.h>
#import "AFHTTPClient.h"

@interface HUHTTPClient : AFHTTPClient{
    NSString *_baseURL;
    NSMutableArray *_downloadingImageURL;
}

+ (HUHTTPClient *)sharedClient;
+ (HUHTTPClient *)refreshClient;

- (void) setBaseUrl:(NSString *)url;

- (void) imageFromURL:(NSURL*) imageURL
           completion:(CSImageDownloadBlock) imageRequestBlock;

- (UIImage *) imageWithUrl:(NSURL *) imageURL;

- (void) fileFromURL:(NSURL*) imageURL
           completion:(CSFileDownloadBlock) fileRequestBlock;

- (NSString *) doGetSynchronous:(NSURL *) url;

- (AFHTTPRequestOperation *) doPost:(NSString *) apiPath
                      operationType:(AFHTTPClientParameterEncoding) operationType
                             params:(NSDictionary *) params
                        resultBlock:(CSResultBlock) resultBlock
                       failureBlock:(CSErrorBlock) errorBlock
                uploadProgressBlock:(CSProgressBlock)uploadProgressBlock
              downloadProgressBlock:(CSProgressBlock)downloadProgressBlock;

- (AFHTTPRequestOperation *) doGet:(NSString *) apiPath
                     operationType:(AFHTTPClientParameterEncoding) operationType
                       resultBlock:(CSResultBlock) resultBlock
                      failureBlock:(CSErrorBlock) errorBlock
               uploadProgressBlock:(CSProgressBlock)uploadProgressBlock
             downloadProgressBlock:(CSProgressBlock)downloadProgressBlock;


- (AFHTTPRequestOperation *) doPut:(NSString *) apiPath
                     operationType:(AFHTTPClientParameterEncoding) operationType
                            params:(NSDictionary *) params
                       resultBlock:(CSResultBlock) resultBlock
                      failureBlock:(CSErrorBlock) errorBlock
               uploadProgressBlock:(CSProgressBlock)uploadProgressBlock
             downloadProgressBlock:(CSProgressBlock)downloadProgressBlock;

- (AFHTTPRequestOperation *) doDelete:(NSString *) apiPath
                               params:(NSDictionary *) params
                        operationType:(AFHTTPClientParameterEncoding) operationType
                          resultBlock:(CSResultBlock) resultBlock
                         failureBlock:(CSErrorBlock) errorBlock
                  uploadProgressBlock:(CSProgressBlock)uploadProgressBlock
                downloadProgressBlock:(CSProgressBlock)downloadProgressBlock;

- (void) handleCriticalError;

@end
