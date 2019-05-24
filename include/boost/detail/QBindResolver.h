//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QBIND_RESOLVER_H__
#define __QBIND_RESOLVER_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QBaseTypes.h"


////////////////////////////////////////////////////////////////////////////





class QBindResolver0
{
public:
    template<class A>
    A* valueOf(A* a) const
    {
        return (A*)a;
    }
};

template <class A0>
class QBindResolver1 : public QBindResolver0
{
public:
    QBindResolver1(const A0* a0)
        : m_a0(a0)
    {}

public:
    using QBindResolver0::valueOf;
    A0* valueOf(const QPlaceHolder<0>*) const
    {
        return (A0*)m_a0;
    }

protected:
    const A0* m_a0;
};

template <class A0, class A1>
class QBindResolver2 : public QBindResolver1<A0>
{
public:
    QBindResolver2(const A0* a0, const A1* a1)
        : QBindResolver1<A0>(a0)
		, m_a1(a1)
    {}

public:
    using QBindResolver1<A0>::valueOf;
    A1* valueOf(const QPlaceHolder<1>*) const
    {
        return (A1*)m_a1;
    }

protected:
    const A1* m_a1;
};

template <class A0, class A1, class A2>
class QBindResolver3 : public QBindResolver2<A0,A1>
{
public:
    QBindResolver3(const A0* a0, const A1* a1, const A2* a2)
        : QBindResolver2<A0,A1>(a0, a1)
        , m_a2(a2)
    {}

public:
    using QBindResolver2<A0,A1>::valueOf;
    A2* valueOf(const QPlaceHolder<2>*) const
    {
        return (A2*)m_a2;
    }

protected:
    const A2* m_a2;
};

template <class A0, class A1, class A2, class A3>
class QBindResolver4: public QBindResolver3<A0,A1,A2>
{
public:
    QBindResolver4(const A0* a0, const A1* a1, const A2* a2, const A3* a3)
        : QBindResolver3<A0,A1,A2>(a0, a1, a2)
        , m_a3(a3)
    {}

public:
    using QBindResolver3<A0,A1,A2>::valueOf;
    A3* valueOf(const QPlaceHolder<3>*) const
    {
        return (A3*)m_a3;
    }

protected:
    const A3* m_a3;
};

template <class A0, class A1, class A2, class A3, class A4>
class QBindResolver5: public QBindResolver4<A0, A1, A2, A3>
{
public:
    QBindResolver5(const A0* a0, const A1* a1, const A2* a2, const A3* a3, const A4* a4)
        : QBindResolver4<A0,A1,A2,A3>(a0, a1, a2, a3)
        , m_a4(a4)
    {}

public:
    using QBindResolver4<A0,A1,A2,A3>::valueOf;
    A4* valueOf(const QPlaceHolder<4>*) const
    {
        return (A4*)m_a4;
    }

protected:
    const A4* m_a4;
};

template <class A0, class A1, class A2, class A3, class A4, class A5>
class QBindResolver6: public QBindResolver5<A0, A1, A2, A3, A4>
{
public:
    QBindResolver6(const A0* a0, const A1* a1, const A2* a2, const A3* a3, const A4* a4, const A5* a5)
        : QBindResolver5<A0,A1,A2,A3,A4>(a0, a1, a2, a3, a4)
        , m_a5(a5)
    {}

public:
    using QBindResolver5<A0,A1,A2,A3,A4>::valueOf;
    A5* valueOf(const QPlaceHolder<5>*) const
    {
        return (A5*)m_a5;
    }

protected:
    const A5* m_a5;
};

template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
class QBindResolver7: public QBindResolver6<A0, A1, A2, A3, A4, A5>
{
public:
    QBindResolver7(const A0* a0, const A1* a1, const A2* a2, const A3* a3, const A4* a4, const A5* a5, const A6* a6)
        : QBindResolver6<A0,A1,A2,A3,A4,A5>(a0, a1, a2, a3, a4, a5)
        , m_a6(a6)
    {}

public:
    using QBindResolver6<A0,A1,A2,A3,A4,A5>::valueOf;
    A6* valueOf(const QPlaceHolder<6>*) const
    {
        return (A6*)m_a6;
    }

protected:
    const A6* m_a6;
};


template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
class QBindResolver8: public QBindResolver7<A0, A1, A2, A3, A4, A5, A6>
{
public:
    QBindResolver8(const A0* a0, const A1* a1, const A2* a2, const A3* a3, const A4* a4, const A5* a5, const A6* a6, const A7* a7)
        : QBindResolver7<A0,A1,A2,A3,A4,A5,A6>(a0, a1, a2, a3, a4, a5, a6)
        , m_a7(a7)
    {}

public:
    using QBindResolver7<A0,A1,A2,A3,A4,A5,A6>::valueOf;
    A7* valueOf(const QPlaceHolder<7>*) const
    {
        return (A7*)m_a7;
    }

protected:
    const A7* m_a7;
};


template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
class QBindResolver9 : public QBindResolver8<A0, A1, A2, A3, A4, A5, A6, A7>
{
public:
    QBindResolver9(const A0* a0, const A1* a1, const A2* a2, const A3* a3, const A4* a4, const A5* a5, const A6* a6, const A7* a7, const A8* a8)
        : QBindResolver8<A0,A1,A2,A3,A4,A5,A6,A7>(a0, a1, a2, a3, a4, a5, a6, a7)
        , m_a8(a8)
    {}

public:
    using QBindResolver8<A0,A1,A2,A3,A4,A5,A6,A7>::valueOf;
    A8* valueOf(const QPlaceHolder<8>*) const
    {
        return (A8*)m_a8;
    }

protected:
    const A8* m_a8;
};

template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
class QBindResolver10 : public QBindResolver9<A0, A1, A2, A3, A4, A5, A6, A7, A8>
{
public:
    QBindResolver10(const A0* a0, const A1* a1, const A2* a2, const A3* a3, const A4* a4, const A5* a5, const A6* a6, const A7* a7, const A8* a8, const A9* a9)
        : QBindResolver9<A0,A1,A2,A3,A4,A5,A6,A7,A8>(a0, a1, a2, a3, a4, a5, a6, a7, a8)
        , m_a9(a9)
    {}

public:
    using QBindResolver9<A0,A1,A2,A3,A4,A5,A6,A7,A8>::valueOf;
    A9* valueOf(const QPlaceHolder<9>*) const
    {
        return (A9*)m_a9;
    }

protected:
    const A9* m_a9;
};




//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QBIND_RESOLVER_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

