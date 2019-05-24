//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QCONFIG_COMPILER_H__
#define __QCONFIG_COMPILER_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}



// GCC-XML 会模仿其它编译器, 所以必须在最前面检测.
#if defined(__GCCXML__)
#   define QCXX_IS_GCCXML 1

// NVIDIA CUDA C++ compiler for GPU
#elif defined(__CUDACC__)
#   define QCXX_IS_NVCC 1

// Comeau C++
#elif defined(__COMO__)
#   define QCXX_IS_COMO 1

// Digital Mars C++
#elif defined(__DMC__)
#   define QCXX_IS_DMC 1

// Intel
#elif defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)
#   define QCXX_IS_INTEL 1

// GNU C++:
#elif defined(__GNUC__)
#   define QCXX_IS_GNUC 1
//#   include "QConfigGCC.h"

// Kai C++
#elif defined(__KCC)
#   define QCXX_IS_KCC 1

// SGI MIPSpro C++
#elif defined(__sgi)
#   define QCXX_IS_SGI 1

// Compaq Tru64 Unix cxx
#elif defined(__DECCXX)
#   define QCXX_IS_TRU64 1

// Greenhills C++
#elif defined(__ghs)
#   define QCXX_IS_GHS 1

// CodeGear - must be checked for before Borland
#elif defined(__CODEGEARC__)
#   define QCXX_IS_CG 1

// Borland
#elif defined(__BORLANDC__)
#   define QCXX_IS_BORLAND 1

// Metrowerks CodeWarrior
#elif defined(__MWERKS__)
#   define QCXX_IS_CW 1

// Sun Workshop Compiler C++
#elif defined(__SUNPRO_CC)
#   define QCXX_IS_SUNPRO 1

// HP aCC
#elif defined(__HP_aCC)
#   define QCXX_IS_HPACC 1

// MPW MrCpp or SCpp
#elif defined(__MRC__) || defined(__SC__)
#   define QCXX_IS_MPW 1

// IBM Visual Age
#elif defined(__IBMCPP__)
#   define QCXX_IS_IBMCPP 1

// Portland Group Inc.
#elif defined(__PGI)
#   define QCXX_IS_PGI 1

// Microsoft Visual C++ 必须在最后检测, 因为其它的编译器(如 Metrowerks)
// 也会定义 _MSC_VER 宏.
#elif defined(_MSC_VER) && !defined(__MWERKS__) && !defined(__EDG_VERSION__)
#   define QCXX_IS_MSVC 1
#   define QCXX_CALLCONV_AFFECT_SIGNATURE
#   define QCXX_HAS_PRAGMA_COMMENT_LIB
#   include "QConfigCompilerMSVC.h"

// 无法识别当前使用的编译器.
#else
#  error "Sorry, QKernel.QConfigCompiler can not recongnize this compiler."
#endif




//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QCONFIG_COMPILER_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

