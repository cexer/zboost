//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QCONFIG_PLATFORM_WINDOWS_H__
#define __QCONFIG_PLATFORM_WINDOWS_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


// Target platform
#if !defined(_WIN32_WINNT)
#   define _WIN32_WINNT 0x0500
#endif

// Windows Version
#if _WIN32_WINNT >= 0x601
#   define QOS_SHORT_NAME "Win7"
#   define QOS_NAME       "Microsoft Windows 7"
#   define QOS_IS_WINDOWS_7 1

#elif _WIN32_WINNT >= 0x0600
#   define QOS_SHORT_NAME "Win2008"
#   define QOS_NAME       "Microsoft Windows Server 2008"
#   define QOS_IS_WINDOWS_SERVER2008 1

#elif _WIN32_WINNT >= 0x0600
#   define QOS_SHORT_NAME "WinVista"
#   define QOS_NAME       "Microsoft Windows Vista"
#   define QOS_IS_WINDOWS_VISTA 1

#elif _WIN32_WINNT >= 0x0502
#   define QOS_SHORT_NAME "Win2003"
#   define QOS_NAME       "Microsoft Windows Server 2003"
#   define QOS_IS_WINDOWS_SERVER2003 1

#elif _WIN32_WINNT >= 0x0501
#   define QOS_SHORT_NAME "WinXP"
#   define QOS_NAME       "Microsoft Windows XP"
#   define QOS_IS_WINDOWS_XP 1

#elif _WIN32_WINNT >= 0x0500
#   define QOS_SHORT_NAME "Win2000"
#   define QOS_NAME       "Microsoft Windows 2000"
#   define QOS_IS_WINDOWS_2000 1

#elif _WIN32_WINNT >= 0x0400
#   define QOS_SHORT_NAME "WinNT40"
#   define QOS_NAME       "Microsoft Windows NT 4.0"
#   define QOS_IS_WINDOWS_NT4 1

#else
#   define QOS_SHORT_NAME "WinUnknown"
#   define QOS_NAME       "Microsoft Windows Unknown version"
#endif


// Reduce bloat imported by <windows.h>
#if !defined(WIN32_LEAN_AND_MEAN)
#   define WIN32_LEAN_AND_MEAN
#endif

// Disable max/min macro by <windows.h>
#if !defined(NOMINMAX)
#   define NOMINMAX
#endif




//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QCONFIG_PLATFORM_WINDOWS_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

