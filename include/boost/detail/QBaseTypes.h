//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QBASETYPES_H__
#define __QBASETYPES_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QKernelConfig.h"

////////////////////////////////////////////////////////////////////////////





struct QNull{};
struct QEmpty{};

template<class T>
struct QNullT;

template<class T1,class T2>
struct QNull2T;


template<unsigned int v>
struct QBoolean
{
    enum{ value = true };
    char placeholder[32];
};

template<>
struct QBoolean<0>
{
    enum{ value = false };
};


typedef QBoolean<false> QFalse;
typedef QBoolean<true> QTrue;


template<int v>
class QInteger : public QBoolean<v == 0>
{

};


template<class V1, class V2>
class LogicOr: public QBoolean<V1::value || V2::value>
{

};

template<class V1, class V2>
class LogicAnd: public QBoolean<V1::value && V2::value>
{

};



template <int i>
struct QPlaceHolder
{
    enum{ value = i };
};

static QPlaceHolder<0> _1;
static QPlaceHolder<1> _2;
static QPlaceHolder<2> _3;
static QPlaceHolder<3> _4;
static QPlaceHolder<4> _5;
static QPlaceHolder<5> _6;


template<class T>
struct IsPlaceHolder
{
    enum{ value = 0 };
};


template<int i>
struct IsPlaceHolder<QPlaceHolder<i> >
{
    enum{ value = i };
};


template<class T>
struct PlaceIndex
{
    enum { value = -1 };
};

template<int i>
struct PlaceIndex<QPlaceHolder<i> >
{
    enum { value = i };
};


template<bool cond, class T = void>
struct EnableIfC
{
    typedef T Result;
};

template<class T>
struct EnableIfC<false,T>
{
};


template<class C, class T=void>
struct EnableIf : public EnableIfC<C::value,T>
{};


template<bool cond, class Then, class Else>
struct IfElseC
{
	typedef Else Result;
};

template<class Then, class Else>
struct IfElseC<true,Then,Else>
{
	typedef Then Result;
};


template<class Cond, class Then, class Else>
struct IfElse : public IfElseC<Cond::value,Then,Else>
{};



//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QBASETYPES_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

