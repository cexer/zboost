//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QFUNTCION_TRAITS_BASE_H__
#define __QFUNTCION_TRAITS_BASE_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QTypeList.h"
#include "QMethodWraper.h"


////////////////////////////////////////////////////////////////////////////




#define QFUNCTION_UNKNOWNCALL 0
#define QFUNCTION_STDCALL 1
#define QFUNCTION_CDECL   2
#define QFUNCTION_PASCAL  3
#define QFUNCTION_THISCALL 4
#define QFUNCTION_DEFAULT 5


struct QFunctionTraitsBase
{
    enum
    {
		isKnownCallable = 0,
        isFunctionPointer = 0,
        isFunction = 0,
        isMethodPointer = 0,
        isFunctionObject = 0,
        isConstQualified = 0,
        isVolatileQualified = 0,
        functionCallConv = QFUNCTION_UNKNOWNCALL,
        functionParamCount = 0
    };
};


template <class T>
struct QFunctionTraits;




//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QFUNTCION_TRAITS_BASE_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
