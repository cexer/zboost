zboost
-------------------


## 说明
对于一个常年在代码沙场上冲锋陷阵的 C++ 战士而言，shared_ptr、weak_ptr、bind、function 几个库就像是伴随着一起出生入死的心爱武器，有无数藉其化解危机、救命立功的时候。现在写项目基本这几上库是库不离身，稍复杂的项目，缺一个都感觉是在枪林弹雨的战场裸奔“肉”搏。但是要用这几个库，要么带上一个几百M的 boost（害死有代码洁癖的强迫症患者），要么必须使用较新的编译器（不能适应对新编译器有被害妄想的患者）。因此业余自己锤锤打打实现了这几个库，本来是自己大框架里的几个小功能，想着也许真有其它人需求，因此剥离出来，并修改命名为标准的接口开源出来，方便有需求的直接替换使用。


## 功能一览

### boost 标准功能

这些功能有的直接从 boost 当中拿的（开源界的事，能叫偷吗？），有的是自己实现的。
- boost.predef 直接从 boost-1.68.0 当中拿的。
- boost.config 直接从 boost-1.68.0 当中拿的。
- boost.smart_ptr 自己实现的，包含 shared_ptr、weak_ptr、enable_shared_from_this，不依赖其它库。
- boost.bind 自己实现的，不依赖其它库。
- boost.function 自己实现的，依赖 boost.smart_ptr。

暂时没有需求再增加其它功能，但也可以考虑把 boost.any 这种轻而精的库拿进来。

### zboost 实现功能

这些功能其实是为了支持实现 boost.xxxx 标准功能而实现的辅助性功能。
- QAtomic 原子操作，支持 msvc、gcc。
- QFunctionTraits 支持函数及函数指针判断、成员函数 wrapper、参数及返回值推导等功能。
- QFunctionCaller 可根据返回值执行调用函数（对象），避免出现返回值编译错误。
- QBooleanable 实现了一些支持 safe_bool 手法的基类。
- QTypeList 这是 C++ 萌新进入模板元编程世界的魔法门。

还有一些其它小东西，也许也有用，有兴趣可以看看，按需可取用之


## 支持环境

测试过以下环境
- Windows 7 上 vs2008
- macOS 10.14 上 xcode 10
- macOS 10.14 上 codelite 12


## 授权

boost 部分仍遵照 boost 授权，详见项目目录下 LICENSE_1_0.boost.txt
其余部分使用 Anti-996 授权，详见项目目录下 LICENSE_1_0.anti996.txt

