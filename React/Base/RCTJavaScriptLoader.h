/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <UIKit/UIKit.h>

extern uint32_t const RCTRAMBundleMagicNumber;

extern NSString *const RCTJavaScriptLoaderErrorDomain;

NS_ENUM(NSInteger) {
  RCTJavaScriptLoaderErrorNoScriptURL = 1,
  RCTJavaScriptLoaderErrorFailedOpeningFile = 2,
  RCTJavaScriptLoaderErrorFailedReadingFile = 3,
  RCTJavaScriptLoaderErrorFailedStatingFile = 3,
  RCTJavaScriptLoaderErrorURLLoadFailed = 3,

  RCTJavaScriptLoaderErrorCannotBeLoadedSynchronously = 1000,
};

typedef void (^RCTSourceLoadBlock)(NSError *error, NSData *source, int64_t sourceLength);

@interface RCTJavaScriptLoader : NSObject

+ (void)loadBundleAtURL:(NSURL *)scriptURL onComplete:(RCTSourceLoadBlock)onComplete;

/**
 * @experimental
 * Attempts to synchronously load the script at the given URL. The following two conditions must be met:
 *   1. It must be a file URL.
 *   2. It must point to a RAM bundle.
 * If the URL does not meet those conditions, this method will return nil and supply an error with the domain
 * RCTJavaScriptLoaderErrorDomain and the code RCTJavaScriptLoaderErrorCannotBeLoadedSynchronously.
 */
+ (NSData *)attemptSynchronousLoadOfBundleAtURL:(NSURL *)scriptURL
                                   sourceLength:(int64_t *)sourceLength
                                          error:(NSError **)error;

@end
