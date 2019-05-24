//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QINTETYPES_H__
#define __QINTETYPES_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QKernelConfig.h"
#include <limits.h>


////////////////////////////////////////////////////////////////////////////



// MSVC
#if defined(_MSC_VER)
    typedef signed char      qint8_t;
    typedef unsigned char    quint8_t;
    typedef signed short     qint16_t;
    typedef unsigned short   quint16_t;
    typedef signed int       qint32_t;
    typedef unsigned int     quint32_t;
    typedef signed __int64   qint64_t;
    typedef unsigned __int64 quint64_t;
#   if defined(_WIN64)
#      define QPOINTER_IS_64_BIT
#   endif
#   define QHAS_INT64
#   define QHAS_LONG_LONG

// GCC
#elif defined(__GNUC__)
    typedef signed char      qint8_t;
    typedef unsigned char    quint8_t;
    typedef signed short     qint16_t;
    typedef unsigned short   quint16_t;
    typedef signed int       qint32_t;
    typedef unsigned int     quint32_t;
#   if defined(__LP64__)
#      define QPOINTER_IS_64_BIT
#      define QLONG_IS_64_BIT
        typedef signed long   qint64_t;
        typedef unsigned long quint64_t;
#   else
        typedef signed long long qint64_t;
        typedef unsigned long long quint64_t;
#   endif
#   define QHAS_INT64
#   define QHAS_LONG_LONG

// Unknown
#else
#   error "QKernel: Sorry, QIntTypes is not avaiable."
#endif


typedef unsigned char byte_t;



//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif //__QINTETYPES_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

