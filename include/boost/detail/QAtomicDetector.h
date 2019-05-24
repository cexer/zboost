//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QATOMIC_DETECTOR_H__
#define __QATOMIC_DETECTOR_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QKernelConfig.h"


////////////////////////////////////////////////////////////////////////////



#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#   define QHAS_WINDOWS_ATOMIC

#elif defined(__GNUC__) &&\
        (__GNUC__ >  4 ||\
        (__GNUC__ == 4 && __GNUC_MINOR__ >= 3) ||\
        (__GNUC__ == 4 && __GNUC_MINOR__ >= 2 && (defined(__x86_64__) || defined(__i386__))))
#   define QHAS_GCC_ATOMIC

#elif defined(__GNUC__) && (defined(__x86_64__) || defined(__i386__))
#   define QHAS_GCC_X64_ATOMIC
#endif




//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QATOMIC_DETECTOR_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
