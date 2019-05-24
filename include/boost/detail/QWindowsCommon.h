//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QWINDOWS_H__
#define __QWINDOWS_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QKernelConfig.h"
#if defined(QOS_IS_WINDOWS_FAMILY)

//////////////////////////////////////////////////////////////////////////

//_WIN32_WINDOWS
#if !defined(_WIN32_WINDOWS) || (_WIN32_WINDOWS < 0x502)
#   undef _WIN32_WINDOWS
#   define _WIN32_WINDOWS 0x502
#endif

//_WIN32_WINNT
#if !defined(_WIN32_WINNT) || (_WIN32_WINNT < 0x502)
#   undef _WIN32_WINNT
#   define _WIN32_WINNT 0x502
#endif

//WINVER
#if !defined(WINVER) || (WINVER < 0x502)
#   undef WINVER
#   define WINVER 0x502
#endif

//_WIN32_IE
#if !defined(_WIN32_IE) || (_WIN32_IE < _WIN32_IE_IE70)
#   undef _WIN32_IE
#   define _WIN32_IE _WIN32_IE_IE70
#endif


//通用头文件
#include <Windows.h>
//#include <WindowsX.h>
#include <TChar.h>
#include <Ole2.h>
#include <Conio.h>
#include <WinNT.h>


//////////////////////////////////////////////////////////////////////////

#endif//defined(QOS_IS_WINDOWS_FAMILY)

//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QWINDOWS_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}