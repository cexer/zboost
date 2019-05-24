//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QCONFIG_PROCESSOR_H__
#define __QCONFIG_PROCESSOR_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#if defined(__ALPHA) || defined(__alpha) || defined(__alpha__) || defined(_M_ALPHA)
#   define QCPU_IS_ALPHA 1
#   define QCPU_IS_LITTLE_ENDIAN 1

#elif defined(i386) || defined(__i386) || defined(__i386__) || defined(_M_IX86)
#   define QCPU_IS_IA32 1
#   define QCPU_IS_X86_FAMILY
#   define QCPU_IS_LITTLE_ENDIAN 1
#   define QCPU_SHORT_NAME "ia32"
#   define QCPU_NAME       "Intel Architecture, 32-bit"

#elif defined(_IA64) || defined(__IA64__) || defined(__ia64__) || defined(__ia64) || defined(_M_IA64)
#   define QCPU_IS_IA64 1
#   define QCPU_IS_X86_FAMILY
#   if defined(hpux) || defined(_hpux)
#      define QCPU_IS_BIG_ENDIAN 1
#   else
#      define QCPU_IS_LITTLE_ENDIAN 1
#   endif

#elif defined(__x86_64__) || defined(_M_X64)
#   define QCPU_IS_AMD64 1
#   define QCPU_IS_LITTLE_ENDIAN 1
#   define QCPU_SHORT_NAME "amd64"
#   define QCPU_NAME       "AMD64 Architecture"

#elif defined(__mips__) || defined(__mips) || defined(__MIPS__) || defined(_M_MRX000)
#   define QCPU_IS_MIPS 1
#   define QCPU_IS_BIG_ENDIAN 1

#elif defined(__hppa) || defined(__hppa__)
#   define QCPU_IS_HPPA 1
#   define QCPU_IS_BIG_ENDIAN 1

#elif defined(__PPC) || defined(__POWERPC__) || defined(__powerpc) || defined(__PPC__) || \
      defined(__powerpc__) || defined(__ppc__) || defined(_ARCH_PPC) || defined(_M_PPC)
#   define QCPU_IS_PPC 1
#   define QCPU_IS_BIG_ENDIAN 1

#elif defined(_POWER) || defined(_ARCH_PWR) || defined(_ARCH_PWR2) || defined(_ARCH_PWR3) || \
      defined(_ARCH_PWR4) || defined(__THW_RS6000)
#   define QCPU_IS_POWER 1
#   define QCPU_IS_BIG_ENDIAN 1

#elif defined(__sparc__) || defined(__sparc) || defined(sparc)
#   define QCPU_IS_SPARC 1
#   define QCPU_IS_BIG_ENDIAN 1

#elif defined(__arm__) || defined(__arm) || defined(ARM) || defined(_ARM_) || defined(__ARM__) || defined(_M_ARM)
#   define QCPU_IS_ARM 1
#   if defined(__ARMEB__)
#      define QCPU_IS_BIG_ENDIAN 1
#   else
#      define QCPU_IS_LITTLE_ENDIAN 1
#   endif

#elif defined(__m68k__)
#   define QCPU_IS_M68K 1
#   define QCPU_IS_BIG_ENDIAN 1

#elif defined(__s390__)
#   define QCPU_IS_S390 1
#   define QCPU_IS_BIG_ENDIAN 1

#elif defined(__sh__)
#   define QCPU_IS_SH 1
#   if defined(__LITTLE_ENDIAN__)
#      define QCPU_IS_LITTLE_ENDIAN 1
#   else
#      define QCPU_IS_BIG_ENDIAN 1
#   endif

#else
#  error "Sorry, QKernel.QConfigProcessor can not recongnize this processor."
#endif




//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QCONFIG_PROCESSOR_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

