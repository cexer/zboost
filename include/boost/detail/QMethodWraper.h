//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QMETHOD_WRAPPER_H__
#define __QMETHOD_WRAPPER_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QFunctionTraisBase.h"
#include "QAssert.h"


////////////////////////////////////////////////////////////////////////////



template<class C, class F, class R, 
	class A0 = void,
	class A1 = void,
	class A2 = void,
	class A3 = void,
	class A4 = void,
	class A5 = void,
	class A6 = void,
	class A7 = void,
	class A8 = void,
	class A9 = void>
struct QMethodWrapper;


template<class C, class F, class R>
struct QMethodWrapper<C,F,R>
{
    typedef QTYPELIST_1(const C*) Params;
    typedef R Return;

    QMethodWrapper(F f)
        : m_f(f)
    {}

    R operator()(const C* c) const
    {
        return ((C*)c->*m_f)();
    }
	template<class T>
    R operator()(const T& t) const
    {
        const C* c = pointerOf(t);
        QASSERT(c != NULL);
        return ((C*)c->*m_f)();
    }

protected:
    F m_f;
};


template<class C, class F, class R, class A>
struct QMethodWrapper<C,F,R,A>
{
    typedef QTYPELIST_2(const C*,A) Params;
    typedef R Return;

    QMethodWrapper(F f)
        : m_f(f)
    {}

    R operator()(const C* c, A a) const
    {
        return ((C*)c->*m_f)(a);
    }

	template<class T>
    R operator()(const T& t, A a) const
    {
		const C* c = pointerOf(t);
        QASSERT(c != NULL);
	    return ((C*)c->*m_f)(a);
    }
protected:
    F m_f;
};


template<class C, class F, class R, class A0, class A1>
struct QMethodWrapper<C,F,R,A0,A1>
{
    typedef QTYPELIST_3(const C*,A0,A1) Params;
    typedef R Return;

    QMethodWrapper(F f)
        : m_f(f)
    {}

    R operator()(const C* c, A0 a0, A1 a1) const
    {
        return ((C*)c->*m_f)(a0, a1);
    }

	template<class T>
    R operator()(const T& t, A0 a0, A1 a1) const
    {
		const C* c = pointerOf(t);
        QASSERT(c != NULL);
        return ((C*)c->*m_f)(a0, a1);
    }
protected:
    F m_f;
};



template<class C, class F, class R, class A0, class A1, class A2>
struct QMethodWrapper<C,F,R,A0,A1,A2>
{
    typedef QTYPELIST_4(const C*,A0,A1,A2) Params;
    typedef R Return;

    QMethodWrapper(F f)
        : m_f(f)
    {}

    R operator()(const C* c, A0 a0, A1 a1, A2 a2) const
    {
        return ((C*)c->*m_f)(a0, a1, a2);
    }

	template<class T>
    R operator()(const T& t, A0 a0, A1 a1, A2 a2) const
    {
        const C* c = pointerOf(t);
        QASSERT(c != NULL);
        return ((C*)c->*m_f)(a0, a1, a2);
    }
protected:
    F m_f;
};


template<class C, class F, class R, class A0, class A1, class A2, class A3>
struct QMethodWrapper<C,F,R,A0,A1,A2,A3>
{
    typedef QTYPELIST_5(const C*,A0,A1,A2,A3) Params;
    typedef R Return;

    QMethodWrapper(F f)
        : m_f(f)
    {}

    R operator()(const C* c, A0 a0, A1 a1, A2 a2, A3 a3) const
    {
        return ((C*)c->*m_f)(a0, a1, a2, a3);
    }

	template<class T>
    R operator()(const T& t, A0 a0, A1 a1, A2 a2, A3 a3) const
    {
        const C* c = pointerOf(t);
        QASSERT(c != NULL);
        return ((C*)c->*m_f)(a0, a1, a2, a3);
    }
protected:
    F m_f;
};



template<class C, class F, class R, class A0, class A1, class A2, class A3, class A4>
struct QMethodWrapper<C,F,R,A0,A1,A2,A3,A4>
{
    typedef QTYPELIST_6(const C*,A0,A1,A2,A3,A4) Params;
    typedef R Return;

    QMethodWrapper(F f)
        : m_f(f)
    {}

    R operator()(const C* c, A0 a0, A1 a1, A2 a2, A3 a3, A4 a4) const
    {
        return ((C*)c->*m_f)(a0, a1, a2, a3, a4);
    }

	template<class T>
    R operator()(const T& t, A0 a0, A1 a1, A2 a2, A3 a3, A4 a4) const
    {
        const C* c = pointerOf(t);
        QASSERT(c != NULL);
        return ((C*)c->*m_f)(a0, a1, a2, a3, a4);
    }
protected:
    F m_f;
};


template<class C, class F, class R, class A0, class A1, class A2, class A3, class A4, class A5>
struct QMethodWrapper<C,F,R,A0,A1,A2,A3,A4,A5>
{
    typedef QTYPELIST_7(const C*,A0,A1,A2,A3,A4,A5) Params;
    typedef R Return;

    QMethodWrapper(F f)
        : m_f(f)
    {}

    R operator()(const C* c, A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5) const
    {
        return ((C*)c->*m_f)(a0, a1, a2, a3, a4, a5);
    }

	template<class T>
    R operator()(const T& t, A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5) const
    {
        const C* c = pointerOf(t);
        QASSERT(c != NULL);
        return ((C*)c->*m_f)(a0, a1, a2, a3, a4, a5);
    }
protected:
    F m_f;
};


template<class C, class F, class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6>
struct QMethodWrapper<C,F,R,A0,A1,A2,A3,A4,A5,A6>
{
    typedef QTYPELIST_8(const C*,A0,A1,A2,A3,A4,A5,A6) Params;
    typedef R Return;

    QMethodWrapper(F f)
        : m_f(f)
    {}

    R operator()(const C* c, A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6) const
    {
        return ((C*)c->*m_f)(a0, a1, a2, a3, a4, a5, a6);
    }

	template<class T>
    R operator()(const T& t, A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6) const
    {
        const C* c = pointerOf(t);
        QASSERT(c != NULL);
        return ((C*)c->*m_f)(a0, a1, a2, a3, a4, a5, a6);
    }
protected:
    F m_f;
};


template<class C, class F, class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
struct QMethodWrapper<C,F,R,A0,A1,A2,A3,A4,A5,A6,A7>
{
    typedef QTYPELIST_9(const C*,A0,A1,A2,A3,A4,A5,A6,A7) Params;
    typedef R Return;

    QMethodWrapper(F f)
        : m_f(f)
    {}

    R operator()(const C* c, A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7) const
    {
        return ((C*)c->*m_f)(a0, a1, a2, a3, a4, a5, a6, a7);
    }

	template<class T>
    R operator()(const T& t, A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7) const
    {
        const C* c = pointerOf(t);
        QASSERT(c != NULL);
        return ((C*)c->*m_f)(a0, a1, a2, a3, a4, a5, a6, a7);
    }
protected:
    F m_f;
};



template<class C, class F, class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
struct QMethodWrapper<C,F,R,A0,A1,A2,A3,A4,A5,A6,A7,A8>
{
    typedef QTYPELIST_10(const C*,A0,A1,A2,A3,A4,A5,A6,A7,A8) Params;
    typedef R Return;

    QMethodWrapper(F f)
        : m_f(f)
    {}

    R operator()(const C* c, A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8) const
    {
        return ((C*)c->*m_f)(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    }

	template<class T>
    R operator()(const T& t, A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8) const
    {
        const C* c = pointerOf(t);
        QASSERT(c != NULL);
        return ((C*)c->*m_f)(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    }
protected:
    F m_f;
};


template<class C, class F, class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
struct QMethodWrapper
{
    typedef QTYPELIST_11(const C*,A0,A1,A2,A3,A4,A5,A6,A7,A8,A9) Params;
    typedef R Return;

    QMethodWrapper(F f)
        : m_f(f)
    {}

    R operator()(const C* c, A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9) const
    {
        return ((C*)c->*m_f)(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    }

	template<class T>
    R operator()(const T& t, A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9) const
    {
        const C* c = pointerOf(t);
        QASSERT(c != NULL);
        return ((C*)c->*m_f)(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    }
protected:
    F m_f;
};


template<class C, class F, class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
struct QFunctionTraits< QMethodWrapper<C,F,R,A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> > : public QFunctionTraitsBase
{
	typedef QMethodWrapper<C,F,R,A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> Wrapper;
    typedef typename Wrapper::Params Params;
    typedef typename Wrapper::Return Return;

    enum
    {
		isKnownCallable = 1,
        isFunctionObject = 1,
        functionParamCount = QTypeListLength<Params>::value
    };
};


//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QMETHOD_WRAPPER_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
