//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QFUNTCION_TRAITS_H__
#define __QFUNTCION_TRAITS_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QTypeList.h"
#include "QMethodWraper.h"
#include "QTraits.h"


////////////////////////////////////////////////////////////////////////////



template <class T>
struct QFunctionTraits : public QFunctionTraitsBase
{
    //typedef typename T::Params Params;
    //typedef typename T::Return Return;
    //typedef typename T::Wrapper Wrapper;
};

template <class T>
struct QFunctionPointerTraits : public QFunctionTraitsBase
{
    //typedef typename T::Params Params;
    //typedef typename T::Return Return;
    //typedef typename T::Wrapper Wrapper;
};


#if defined(QCXX_CALLCONV_AFFECT_SIGNATURE)
#   define __CALLING     __stdcall
#   define __CALLING_ID  QFUNCTION_STDCALL
#   include "QFunctionTraitsTemplate.h"

#   define __CALLING     __cdecl
#   define __CALLING_ID  QFUNCTION_CDECL
#   include "QFunctionTraitsTemplate.h"
//warning C4561: '__fastcall' incompatible with the '/clr' option: converting to '__stdcall'
//#   define __CALLING     __fastcall 
//#   define __CALLING_ID  QFUNCTION_PASCAL
//#   include "QFunctionTraitsTemplate.h"
#
#else
#   define __CALLING
#   define __CALLING_ID  QFUNCTION_UNKNOWNCALL
#   include "QFunctionTraitsTemplate.h"
#endif




#define __QUALIFICATION
#define __IS_CONST_Q      0
#define __IS_VOLATILE_Q   0
#include "QMethodTraitsTemplate1.h"

#define __QUALIFICATION   const
#define __IS_CONST_Q      1
#define __IS_VOLATILE_Q   0
#include "QMethodTraitsTemplate1.h"

#define __QUALIFICATION   volatile
#define __IS_CONST_Q      0
#define __IS_VOLATILE_Q   1
#include "QMethodTraitsTemplate1.h"

#define __QUALIFICATION   const volatile
#define __IS_CONST_Q      1
#define __IS_VOLATILE_Q   1
#include "QMethodTraitsTemplate1.h"



template<class F>
struct IsFunction : public QBoolean<QFunctionTraits<F>::isFunction>
{};

template<class F>
struct IsFunctionPointer : public QBoolean<QFunctionPointerTraits<F>::isFunctionPointer>
{};

template<class F>
struct IsFunctionOrFunctionPtr : public LogicOr< IsFunction<F>, IsFunctionPointer<F> >
{};

template<class F>
struct IsMethodPointer : public QBoolean<QFunctionTraits<F>::isMethodPointer>
{};

template<class F>
struct IsRawCallable : public LogicOr< IsFunctionOrFunctionPtr<F>, IsMethodPointer<F> >
{};

template<class F>
struct IsKnownCallable : public QBoolean<QFunctionTraits<F>::isKnownCallable>
{};

template<class F>
struct GetRawCallableWrapper
{
    typedef typename IfElse<IsFunction<F>, QFunctionTraits<F>, QFunctionPointerTraits<F> >::Result Traits;
    typedef typename Traits::Wrapper Result;
};



//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QFUNTCION_TRAITS_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

