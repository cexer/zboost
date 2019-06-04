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
struct QFunctionPrototypeTraits : public QFunctionTraitsBase
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
struct IsFunctionPrototype : public QBoolean<QFunctionPrototypeTraits<F>::isFunction>
{};

template<class F>
struct IsFunctionPointer : public QBoolean<QFunctionPointerTraits<F>::isFunctionPointer>
{};


template <class T, bool isfun, bool isfunptr>
struct QFunctionTraitsImpl : public QFunctionTraitsBase
{};

template <class T>
struct QFunctionTraitsImpl<T,true,false>
    : public QFunctionPrototypeTraits<T>
{};

template <class T>
struct QFunctionTraitsImpl<T,false,true>
    : public QFunctionPointerTraits<T>
{};

template <class T>
struct QFunctionTraits
    : public QFunctionTraitsImpl<T, IsFunctionPrototype<T>::value, IsFunctionPointer<T>::value>
{};

template<class F>
struct IsFunctionPrototypeOrPointer : public LogicOr< IsFunctionPrototype<F>, IsFunctionPointer<F> >
{};

template<class F>
struct IsMethodPointer : public QBoolean<QFunctionTraits<F>::isMethodPointer>
{};

template<class F>
struct IsRawCallable : public LogicOr< IsFunctionPrototypeOrPointer<F>, IsMethodPointer<F> >
{};




//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QFUNTCION_TRAITS_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

