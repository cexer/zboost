//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QCONFIG_COMPILER_MSVC_H__
#define __QCONFIG_COMPILER_MSVC_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}



// 1 Check VisualC version and fullname
#if _MSC_VER < 1200
#   define QCXX_SHORT_NAME  "VC50"
#   define QCXX_NAME        "Microsoft Visual C++ 5.0"

#elif _MSC_VER == 1200
#   define QCXX_SHORT_NAME  "VC60"
#   define QCXX_NAME        "Microsoft Visual C++ 6.0"

#elif _MSC_VER == 1300
#   define QCXX_SHORT_NAME  "VC70"
#   define QCXX_NAME        "Microsoft Visual Studio 2002"

#elif _MSC_VER == 1310
#   define QCXX_SHORT_NAME  "VC71"
#   define QCXX_NAME        "Microsoft Visual Studio 2003"

#elif _MSC_VER == 1400
#   define QCXX_SHORT_NAME  "VC80"
#   define QCXX_NAME        "Microsoft Visual Studio 2005"

#elif _MSC_VER == 1500
#   define QCXX_SHORT_NAME  "VC90"
#   define QCXX_NAME        "Microsoft Visual Studio 2008"

#elif _MSC_VER == 1600
#   define QCXX_SHORT_NAME  "VC100"
#   define QCXX_NAME        "Microsoft Visual Studio 2010"

#else
#   define QCXX_SHORT_NAME  "VCUnknown"
#   define QCXX_NAME        "Microsoft Visual Studio/Visual C++ Unknown version"
#endif


// 2 Dynamic shared object (DSO) and dynamic-link library (DLL) support
#define QSYMBOL_EXPORT __declspec(dllexport)
#define QSYMBOL_IMPORT __declspec(dllimport)



// Verify that we're built with the multithreaded 
// versions of the runtime libraries
#if !defined(_MT)
#	error "vcode: Must compile with /MD, /MDd, /MT or /MTd"
#endif


// Check debug/release settings consistency
#if defined(NDEBUG) && defined(_DEBUG)
#	error "vcode: Inconsistent build settings (check for /MD[d])"
#endif


// check /RTC option or /GZ options
#if defined(__MSVC_RUNTIME_CHECKS) && !defined(_DEBUG)
#  pragma message("vcode: Using the /RTC option without specifying a debug runtime will lead to linker errors")
#  pragma message("vcode: Hint: go to the code generation options and switch to one of the debugging runtimes")
#  error "vcode: Incompatible build options"
#endif


// Turn off some annoying warnings
#pragma warning(disable:4250) // 'xxxx' 通过域控制继承
#pragma warning(disable:4251) // 'xxxx' needs to have dll-interface warning 
#pragma warning(disable:4355) // 'this' : used in base member initializer list
#pragma warning(disable:4996) // VC++ 8.0 deprecation warnings
#pragma warning(disable:4351) // new behavior: elements of array '...' will be default initialized
#pragma warning(disable:4675) // resolved overload was found by argument-dependent lookup
#pragma warning(disable:4275) // 非 dll 接口 class “A”用作 dll 接口 class“B”的基
#pragma warning(disable:4661) // “A::method()”: 没有为显式模板实例化请求提供适当的定义
#pragma warning(disable:4503) // “std::map<_Kty,_Ty,_Pr,_Alloc>::map”: 超出修饰名的长度，名称被截断




//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QCONFIG_COMPILER_MSVC_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

