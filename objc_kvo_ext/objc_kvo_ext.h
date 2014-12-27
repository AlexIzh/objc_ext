// objc_kvo_ext.h
//
//  Created by Alex Severyanov on 22/12/14.
//
//  The MIT License (MIT)
//
//  Copyright (c) 2014 Alex Severyanov
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of
//  this software and associated documentation files (the "Software"), to deal in
//  the Software without restriction, including without limitation the rights to
//  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
//  the Software, and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
//  FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
//  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
//  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
//  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#ifndef Dispatch_United_objc_kvo_ext_h
#define Dispatch_United_objc_kvo_ext_h

#import <objc/runtime.h>

#define add_observer(__X__) \
NSMutableDictionary * __observer_values_##__X__ = objc_getAssociatedObject(self, "__tmp__observers_dictionary__"); \
if (!__observer_values_##__X__) { \
__observer_values_##__X__ = [NSMutableDictionary dictionary]; \
objc_setAssociatedObject(self, "__tmp__observers_dictionary__", __observer_values_##__X__, OBJC_ASSOCIATION_RETAIN_NONATOMIC); \
} \
BOOL __tmp_value_##__X__ = [[__observer_values_##__X__ valueForKey:[NSString stringWithFormat:@"%s", #__X__]] boolValue];\
if (!__tmp_value_##__X__) {\
[__observer_values_##__X__ setValue:@(YES) forKey:[NSString stringWithFormat:@"%s", #__X__]]; \
} \
if (!__tmp_value_##__X__)

#define remove_observer(__X__) \
NSMutableDictionary * __observer_values_##__X__ = objc_getAssociatedObject(self, "__tmp__observers_dictionary__"); \
if (!__observer_values_##__X__) { \
__observer_values_##__X__ = [NSMutableDictionary dictionary]; \
objc_setAssociatedObject(self, "__tmp__observers_dictionary__", __observer_values_##__X__, OBJC_ASSOCIATION_RETAIN_NONATOMIC); \
} \
BOOL __tmp_value_##__X__ = [[__observer_values_##__X__ valueForKey:[NSString stringWithFormat:@"%s", #__X__]] boolValue];\
if (__tmp_value_##__X__) {\
[__observer_values_##__X__ setValue:@(NO) forKey:[NSString stringWithFormat:@"%s", #__X__]]; \
} \
if (__tmp_value_##__X__)

#endif
