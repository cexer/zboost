//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QKERNEL_CONFIG_H__
#define __QKERNEL_CONFIG_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QConfigCompiler.h"
#include "QConfigPlatform.h"
#include "QConfigProcessor.h"
#include <stddef.h>


////////////////////////////////////////////////////////////////////////////


//调试、发行标志
#if defined(_DEBUG)
#   define QDEBUG
#endif


//动态、静态库标志
#if !defined(QSHARED)
#   undef  QSTATIC
#   define QSTATIC
#endif


//导入、导出符号标志
#if defined(QSHARED)
#   if defined(QKERNEL_BUILD)
#      define QKERNEL_SYMBOL QSYMBOL_EXPORT
#   else
#      define QKERNEL_SYMBOL QSYMBOL_IMPORT
#   endif
#else
#	define QKERNEL_SYMBOL
#endif


//跟踪分配器内存分配情况
#if defined(QDEBUG)
#   define QALLOCATOR_ENABLE_TRACE_TYPE
#   define QALLOCATOR_ENABLE_TRACE
#endif


//一些额外模块开关
//#define QENABLE_GETTEXT     //允许使用gettext
//#define QENABLE_TCMALLOC   //允许使用tcmalloc
#define QENABLE_WINTHREAD  //允许使用windows线程
//#define QENABLE_PTHREAD    //允许使用pthread实现
#define QENABLE_WSTRING     //允许宽字符集相关功能


//宽字符字节数
#if defined(QENABLE_WSTRING)
#   if defined(QOS_IS_WINDOWS_FAMILY)
#      define QWCHAR_IS_16BIT
#   else
#      define QWCHAR_IS_32BIT
#   endif
#endif




//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QKERNEL_CONFIG_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

