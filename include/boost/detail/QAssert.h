//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QASSERT_H__
#define __QASSERT_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QNoop.h"
#include <assert.h>


////////////////////////////////////////////////////////////////////////////





#if defined(QDEBUG)
#   define QASSERT(x) //if (!(x)) { _asm{ int 3 }; }
#else
#   define QASSERT(x) (void)0
#endif


#define QSTATIC_IFERROR(expr)           (((int)(expr)) / ((int)(expr)))  
#define QSTATIC_ASSERT(expr)            { char static_assert_failed[ QSTATIC_IFERROR(expr) ]; (void)static_assert_failed; }
#define QSTATIC_ASSERT_MSG(expr, msg)   { char msg[ QSTATIC_IFERROR(expr) ]; (void)msg; }
#define QSTATIC_ASSERT_C(expr)           QSTATIC_ASSERT(expr::value)


#if defined(QDEBUG)
#   define QVERIFY(expr) QASSERT(expr)
#else
#   define QVERIFY(expr) ((void)(expr))
#endif





//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif //__QASSERT_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

