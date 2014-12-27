Macros for working with KVO
============

Do you not like @try-catch or you can not use it for some other reason? But you using KVO and care about error handling and exceptions? These macroses special for you!

How you should know, `-removeObserver:forKeyPath:` and `-removeObserver:forKeyPath:context:` methods could crash your app if you don't call `-addObserver:forKeyPath:options:context:` before. For example: `-addObserver:forKeyPath:options:context:` in `-viewDidLoad` and `-removeObserver:forKeyPath:` in `-dealloc`. It could crash your app if controller has not been presented.

But you can use these macroses for this situation. 

Using KVO
============
### @try-catch

```objective-c
- (void)viewDidLoad {
  //...
  [model addObserver:self forKeyPath:@"status" options:NSKeyValueObservingOptionNew context:nil];
  //...
}
- (void)someMethod {
  //...
  [model addObserver:self forKeyPath:@"progress" options:NSKeyValueObservingOptionNew context:nil];
  //...
}
- (void)someOtherMethod {
  //...
  [model addObserver:self forKeyPath:@"value" options:NSKeyValueObservingOptionNew context:nil];
  //...
}
- (void)dealloc {
  @try {
    [model removeObserver:self forKeyPath:@"status"];
  } @catch (NSException *exception) {}
  @try {
    [model removeObserver:self forKeyPath:@"progress"];
  } @catch (NSException *exception) {}
  @try {
    [model removeObserver:self forKeyPath:@"value"];
  } @catch (NSException *exception) {}
}
```
### BOOL variables
```objective-c
- (void)viewDidLoad {
  //...
  _observed_status = YES;
  [model addObserver:self forKeyPath:@"status" options:NSKeyValueObservingOptionNew context:nil];
  //...
}
- (void)someMethod {
  //...
  _observed_progress = YES;
  [model addObserver:self forKeyPath:@"progress" options:NSKeyValueObservingOptionNew context:nil];
  //...
}
- (void)someOtherMethod {
  //...
  _observed_value = YES;
  [model addObserver:self forKeyPath:@"value" options:NSKeyValueObservingOptionNew context:nil];
  //...
}
- (void)dealloc {
  if (_observed_status) {
    [model removeObserver:self forKeyPath:@"status"];
  }
  if (_observed_progress) {
    [model removeObserver:self forKeyPath:@"progress"];
  }
  if (_observed_value) {
    [model removeObserver:self forKeyPath:@"value"];
  }
}
```
### Macroses
```objective-c
- (void)viewDidLoad {
  //... 
  add_observer(status) {
    [model addObserver:self forKeyPath:@"status" options:NSKeyValueObservingOptionNew context:nil];
  }
  //...
}
- (void)someMethod {
  //...
  add_observer(progress) {
    [model addObserver:self forKeyPath:@"progress" options:NSKeyValueObservingOptionNew context:nil];
  }
  //...
}
- (void)someOtherMethod {
  //...
  add_observer(value) {
    [model addObserver:self forKeyPath:@"value" options:NSKeyValueObservingOptionNew context:nil];
  }
  //...
}
- (void)dealloc {
  remove_observer(status) {
    [model removeObserver:self forKeyPath:@"status"];
  }
  remove_observer(progress) {
    [model removeObserver:self forKeyPath:@"progress"];
  }
  remove_observer(value) {
    [model removeObserver:self forKeyPath:@"value"];
  }
}
```

How it works?
============
Simply, it works like bool variables. It means, that you can debug your app without special breakpoints. These macroses creates associated object for self with bool variables for current parameter. Parameter is like identifier.

It is really easy for using. You should not create a lot of bool variables for using KVO. Macros will make it instead of you.

License
===========
The MIT License (MIT)

Copyright (c) 2014 Alex

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
