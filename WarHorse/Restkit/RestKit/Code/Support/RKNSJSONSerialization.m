//
//  RKNSJSONSerialization.m
//  RestKit
//
//  Created by Blake Watters on 8/31/12.
//  Copyright (c) 2012 RestKit. All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import "RKNSJSONSerialization.h"

@implementation RKNSJSONSerialization

+ (id)objectFromData:(NSData *)data error:(NSError **)error
{
    NSString* newStr = [[NSString alloc] initWithData:data
                                              encoding:NSUTF8StringEncoding];
    

    newStr = [newStr stringByReplacingOccurrencesOfString:@"@" withString:@""];
    data = [newStr dataUsingEncoding:NSUTF8StringEncoding];
    return [NSJSONSerialization JSONObjectWithData:data options:0 error:error];
}

+ (NSData *)dataFromObject:(id)object error:(NSError **)error
{
    return [NSJSONSerialization dataWithJSONObject:object options:0 error:error];
}

@end
