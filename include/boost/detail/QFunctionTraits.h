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


template<class T, bool isfun, bool isfunptr>
struct QFunctionTraitsImpl : public QFunctionTraitsBase
{};

template<class T>
struct QFunctionTraitsImpl<T,true,false>
    : public QFunctionPrototypeTraits<T>
{};

template<class T>
struct QFunctionTraitsImpl<T,false,true>
    : public QFunctionPointerTraits<T>
{};

template<class T>
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


template<class R, class PS>
struct QFunctionTraitsFromParams;

template<class R, class PS, int pn=QTypeListLength<PS>::value>
struct GetFunctionTraitsBase;

template<class R, class PS>
struct GetFunctionTraitsBase<R,PS,0>
{
    typedef QFunctionTraits<R ()> Result;
};

template<class R, class PS>
struct GetFunctionTraitsBase<R,PS,1>
{
    typedef typename QTypeListAt<PS,0>::Result P0;
    typedef QFunctionTraits<R (P0)> Result;
};

template<class R, class PS>
struct GetFunctionTraitsBase<R,PS,2>
{
    typedef typename QTypeListAt<PS,0>::Result P0;
    typedef typename QTypeListAt<PS,1>::Result P1;
    typedef QFunctionTraits<R (P0,P1)> Result;
};

template<class R, class PS>
struct GetFunctionTraitsBase<R,PS,3>
{
    typedef typename QTypeListAt<PS,0>::Result P0;
    typedef typename QTypeListAt<PS,1>::Result P1;
    typedef typename QTypeListAt<PS,2>::Result P2;
    typedef QFunctionTraits<R (P0,P1,P2)> Result;
};

template<class R, class PS>
struct GetFunctionTraitsBase<R,PS,4>
{
    typedef typename QTypeListAt<PS,0>::Result P0;
    typedef typename QTypeListAt<PS,1>::Result P1;
    typedef typename QTypeListAt<PS,2>::Result P2;
    typedef typename QTypeListAt<PS,3>::Result P3;
    typedef QFunctionTraits<R (P0,P1,P2,P3)> Result;
};

template<class R, class PS>
struct GetFunctionTraitsBase<R,PS,5>
{
    typedef typename QTypeListAt<PS,0>::Result P0;
    typedef typename QTypeListAt<PS,1>::Result P1;
    typedef typename QTypeListAt<PS,2>::Result P2;
    typedef typename QTypeListAt<PS,3>::Result P3;
    typedef typename QTypeListAt<PS,4>::Result P4;
    typedef QFunctionTraits<R (P0,P1,P2,P3,P4)> Result;
};

template<class R, class PS>
struct GetFunctionTraitsBase<R,PS,6>
{
    typedef typename QTypeListAt<PS,0>::Result P0;
    typedef typename QTypeListAt<PS,1>::Result P1;
    typedef typename QTypeListAt<PS,2>::Result P2;
    typedef typename QTypeListAt<PS,3>::Result P3;
    typedef typename QTypeListAt<PS,4>::Result P4;
    typedef typename QTypeListAt<PS,5>::Result P5;
    typedef QFunctionTraits<R (P0,P1,P2,P3,P4,P5)> Result;
};

template<class R, class PS>
struct GetFunctionTraitsBase<R,PS,7>
{
    typedef typename QTypeListAt<PS,0>::Result P0;
    typedef typename QTypeListAt<PS,1>::Result P1;
    typedef typename QTypeListAt<PS,2>::Result P2;
    typedef typename QTypeListAt<PS,3>::Result P3;
    typedef typename QTypeListAt<PS,4>::Result P4;
    typedef typename QTypeListAt<PS,5>::Result P5;
    typedef typename QTypeListAt<PS,6>::Result P6;
    typedef QFunctionTraits<R (P0,P1,P2,P3,P4,P5,P6)> Result;
};

template<class R, class PS>
struct GetFunctionTraitsBase<R,PS,8>
{
    typedef typename QTypeListAt<PS,0>::Result P0;
    typedef typename QTypeListAt<PS,1>::Result P1;
    typedef typename QTypeListAt<PS,2>::Result P2;
    typedef typename QTypeListAt<PS,3>::Result P3;
    typedef typename QTypeListAt<PS,4>::Result P4;
    typedef typename QTypeListAt<PS,5>::Result P5;
    typedef typename QTypeListAt<PS,6>::Result P6;
    typedef typename QTypeListAt<PS,7>::Result P7;
    typedef QFunctionTraits<R (P0,P1,P2,P3,P4,P5,P6,P7)> Result;
};

template<class R, class PS>
struct GetFunctionTraitsBase<R,PS,9>
{
    typedef typename QTypeListAt<PS,0>::Result P0;
    typedef typename QTypeListAt<PS,1>::Result P1;
    typedef typename QTypeListAt<PS,2>::Result P2;
    typedef typename QTypeListAt<PS,3>::Result P3;
    typedef typename QTypeListAt<PS,4>::Result P4;
    typedef typename QTypeListAt<PS,5>::Result P5;
    typedef typename QTypeListAt<PS,6>::Result P6;
    typedef typename QTypeListAt<PS,7>::Result P7;
    typedef typename QTypeListAt<PS,7>::Result P8;
    typedef QFunctionTraits<R (P0,P1,P2,P3,P4,P5,P6,P7,P8)> Result;
};

template<class R, class PS>
struct QFunctionTraitsFromParams
    : public GetFunctionTraitsBase<R,PS>::Result
{

};




//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QFUNTCION_TRAITS_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

