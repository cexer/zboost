//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QCONFIG_PLATFORM_H__
#define __QCONFIG_PLATFORM_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#if defined(__FreeBSD__)
#   define QOS_IS_UNIX_FAMILY 1
#   define QOS_IS_BSD_FAMILY 1
#   define QOS_IS_FREE_BSD 1

#elif defined(_AIX) || defined(__TOS_AIX__)
#   define QOS_IS_UNIX_FAMILY 1
#   define QOS_IS_AIX 1

#elif defined(hpux) || defined(_hpux)
#   define QOS_IS_UNIX_FAMILY 1
#   define QOS_IS_HPUX 1

#elif defined(__digital__) || defined(__osf__)
#   define QOS_IS_UNIX_FAMILY 1
#   define QOS_IS_TRU64 1

#elif defined(linux) || defined(__linux) || defined(__linux__) || defined(__TOS_LINUX__)
#   define QOS_IS_UNIX_FAMILY 1
#   define QOS_IS_LINUX 1
#   include "QConfigLinux.h"

#elif defined(__APPLE__) || defined(__TOS_MACOS__)
#   define QOS_IS_UNIX_FAMILY 1
#   define QOS_IS_BSD_FAMILY 1
#   define QOS_IS_MAC_OS_X 1

#elif defined(__NetBSD__)
#   define QOS_IS_UNIX_FAMILY 1
#   define QOS_IS_BSD_FAMILY 1
#   define QOS_IS_NET_BSD 1

#elif defined(__OpenBSD__)
#   define QOS_IS_UNIX_FAMILY 1
#   define QOS_IS_BSD_FAMILY 1
#   define QOS_IS_OPEN_BSD 1

#elif defined(sgi) || defined(__sgi)
#   define QOS_IS_UNIX_FAMILY 1
#   define QOS_IS_IRIX 1

#elif defined(sun) || defined(__sun)
#   define QOS_IS_UNIX_FAMILY 1
#   define QOS_IS_SOLARIS 1

#elif defined(__QNX__)
#   define QOS_IS_UNIX_FAMILY 1
#   define QOS_IS_QNX 1

#elif defined(unix) || defined(__unix) || defined(__unix__)
#   define QOS_IS_UNIX_FAMILY 1
#   define QOS_IS_UNKNOWN_UNIX 1

#elif defined(_WIN32_WCE)
#   define QOS_IS_WINDOWS_FAMILY 1
#   define QOS_IS_WINDOWS_CE 1

#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#   define QOS_IS_WINDOWS_FAMILY 1
#   define QOS_IS_WINDOWS_NT 1
    #include "QConfigWindows.h"

#elif defined(__CYGWIN__)
#   define QOS_IS_UNIX_FAMILY 1
#   define QOS_IS_CYGWIN 1

#elif defined(__VMS)
#   define QOS_IS_VMS_FAMILY 1
#   define QOS_IS_VMS 1

#else
#  error "Sorry, QKernel.QConfigPlatform can not recongnize this platform."
#endif



//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QCONFIG_PLATFORM_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

