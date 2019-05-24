//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QCONFIG_RUNTIME_H__
#define __QCONFIG_RUNTIME_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}



////////////////////////////////////////////////////////////////////////////



//检查编译的库类型，与运行时类型不一致
#if defined(QSHARED)
#   if !defined(_DLL) && !defined(_RTLDLL)
#      error "QKernel: Mixing a shared library with a static runtime is a really bad idea ..."
#   endif

#else
#   if defined(_DLL) || defined(_RTLDLL)
#      error "QKernel: Mixing a shared library with a static runtime is a really bad idea ..."
#   endif
#endif


//静态标志
#if defined(QSHARED)
#   define QRUNTIME_SHARED_FLAG  ""
#   define QRUNTIME_SHARED_FLAG_START ""
#else
#   define QRUNTIME_SHARED_FLAG  "s"
#   define QRUNTIME_SHARED_FLAG_START "-s"
#endif


//调试标志
#if defined(QDEBUG)
#   define QRUNTIME_DEBUG_FLAG "d"
#   define QRUNTIME_DEBUG_FLAG_START "-d"
#else
#   define QRUNTIME_DEBUG_FLAG  ""
#   define QRUNTIME_DEBUG_FLAG_START  ""
#endif


//连接标志
// 静态调试 -sd
// 静态     -s
// 动态调度 -d
// 动态     [空]
#if defined(QSHARED)
#   define QRUNTIME_FLAGS  QRUNTIME_DEBUG_FLAG_START
#else
#   define QRUNTIME_FLAGS  QRUNTIME_SHARED_FLAG_START QRUNTIME_DEBUG_FLAG
#endif






//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QCONFIG_RUNTIME_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

