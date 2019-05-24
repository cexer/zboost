//premake.vpath=boost
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QBIND_H__
#define __QBIND_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "detail/QBindResolver.h"
#include "detail/QBindCaller.h"
#include "detail/QBaseTypes.h"
#include "detail/QFunctionTraits.h"
#include "detail/QBindParams.h"


////////////////////////////////////////////////////////////////////////////




template<class F, class TCaller>
class QBinder
{
    typedef typename QFunctionTraits<F>::Return R;
	typedef typename QFunctionTraits<F>::Wrapper Wrapper;
    typedef typename QFunctionTraits<Wrapper>::Params ParamsOld;
    typedef typename TCaller::Params ParamsBind;

public:
    typedef typename QBindFindParams<ParamsOld,ParamsBind>::Result Params;
    typedef typename QFunctionTraits<F>::Return Return;

public:
    QBinder(const F& f, const TCaller& caller)
        : m_f(f)
        , m_caller(caller)
    {
    }

public:
    R operator ()() const
    {
        return m_caller.template call<R,F>(m_f, QBindResolver0());
    }

    template <class A0>
    R operator ()(const A0& a0) const
    {
        return m_caller.template call<R,F>(m_f, QBindResolver1<A0>(&a0));
    }

    template <class A0, class A1>
    R operator ()(const A0& a0, const A1& a1) const
    {
        return m_caller.template call<R,F>(m_f, QBindResolver2<A0,A1>(&a0, &a1));
    }

    template <class A0, class A1, class A2>
    R operator ()(const A0& a0, const A1& a1, const A2& a2) const
    {
        return m_caller.template call<R,F>(m_f, QBindResolver3<A0,A1,A2>(&a0, &a1, &a2));
    }

    template <class A0, class A1, class A2, class A3>
    R operator ()(const A0& a0, const A1& a1, const A2& a2, const A3& a3) const
    {
        return m_caller.template call<R,F>(m_f, QBindResolver4<A0,A1,A2,A3>(&a0, &a1, &a2, &a3));
    }

    template <class A0, class A1, class A2, class A3, class A4>
    R operator ()(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4) const
    {
        return m_caller.template call<R,F>(m_f, QBindResolver5<A0,A1,A2,A3,A4>(&a0, &a1, &a2, &a3, &a4));
    }

    template <class A0, class A1, class A2, class A3, class A4, class A5>
    R operator ()(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5) const
    {
        return m_caller.template call<R,F>(m_f, QBindResolver6<A0,A1,A2,A3,A4,A5>(&a0, &a1, &a2, &a3, &a4, &a5));
    }

    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6>
    R operator ()(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6) const
    {
        return m_caller.template call<R,F>(m_f, QBindResolver7<A0,A1,A2,A3,A4,A5,A6>(&a0, &a1, &a2, &a3, &a4, &a5, &a6));
    }

    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
    R operator ()(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7) const
    {
        return m_caller.template call<R,F>(m_f, QBindResolver8<A0,A1,A2,A3,A4,A5,A6,A7>(&a0, &a1, &a2, &a3, &a4, &a5, &a6, &a7));
    }

    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
    R operator ()(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8) const
    {
        return m_caller.template call<R,F>(m_f, QBindResolver9<A0,A1,A2,A3,A4,A5,A6,A7,A8>(&a0, &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8));
    }

    template <class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
    R operator ()(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9) const
    {
        return m_caller.template call<R,F>(m_f, QBindResolver10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(&a0, &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9));
    }

protected:
    F m_f;
    TCaller m_caller;
};



//template<class F>
//class QSecondPassBinder
//{
//public:
//	QSecondPassBinder(F f)
//		: m_f(f)
//	{}
//
//	QBinder<F,QBindCaller0> operator()()
//	{
//		return QBinder<F, QBindCaller0>(m_f,QBindCaller0());
//	}
//
//	template <class A1>
//	QBinder<F,QBindCaller1<A1> > operator()(const A0& a0)
//	{
//		return QBinder<F, QBindCaller1<A1> >(m_f,QBindCaller1<A1>(a1));
//	}
//
//	template <class A1, class A2>
//	QBinder<F,QBindCaller2<A0,A1,A2> > operator()(const A0& a0, const A1& a1)
//	{
//		return QBinder<F, QBindCaller2<A0,A1,A2> >(m_f,QBindCaller2<A0,A1,A2>(a0,a1,a2));
//	}
//
//	template <class A1, class A2, class A3>
//	QBinder<F,QBindCaller3<A0,A1,A2,A3> > operator()(const A0& a0, const A1& a1, const A2& a2)
//	{
//		return QBinder<F, QBindCaller3<A0,A1,A2,A3> >(m_f,QBindCaller3<A0,A1,A2,A3>(a0,a1,a2,a3));
//	}
//
//	template <class A1, class A2, class A3, class A4>
//	QBinder<F,QBindCaller4<A0,A1,A2,A3,A4> > operator()(const A0& a0, const A1& a1, const A2& a2, const A3& a3)
//	{
//		return QBinder<F, QBindCaller4<A0,A1,A2,A3,A4> >(m_f,QBindCaller4<A0,A1,A2,A3,A4>(a0,a1,a2,a3,a4));
//	}
//
//	template <class A1, class A2, class A3, class A4, class A5>
//	QBinder<F,QBindCaller5<A0,A1,A2,A3,A4,A5> > operator()(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4)
//	{
//		return QBinder<F, QBindCaller5<A0,A1,A2,A3,A4,A5> >(m_f,QBindCaller5<A0,A1,A2,A3,A4,A5>(a0,a1,a2,a3,a4,a5));
//	}
//
//	template <class A1, class A2, class A3, class A4, class A5, class A6>
//	QBinder<F,QBindCaller6<A0,A1,A2,A3,A4,A5,A6> > operator()(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5)
//	{
//		return QBinder<F, QBindCaller6<A0,A1,A2,A3,A4,A5,A6> >(m_f,QBindCaller6<A0,A1,A2,A3,A4,A5,A6>(a0,a1,a2,a3,a4,a5,a6));
//	}
//
//	template <class A1, class A2, class A3, class A4, class A5, class A6, class A7>
//	QBinder<F,QBindCaller7<A0,A1,A2,A3,A4,A5,A6,A7> > operator()(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6)
//	{
//		return QBinder<F, QBindCaller7<A0,A1,A2,A3,A4,A5,A6,A7> >(m_f,QBindCaller7<A0,A1,A2,A3,A4,A5,A6,A7>(a0,a1,a2,a3,a4,a5,a6,a7));
//	}
//
//	template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
//	QBinder<F,QBindCaller8<A0,A1,A2,A3,A4,A5,A6,A7,A8> > operator()(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7)
//	{
//		return QBinder<F, QBindCaller8<A0,A1,A2,A3,A4,A5,A6,A7,A8> >(m_f,QBindCaller8<A0,A1,A2,A3,A4,A5,A6,A7,A8>(a0,a1,a2,a3,a4,a5,a6,a7,a8));
//	}
//
//	template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
//	QBinder<F,QBindCaller9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> > operator()(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8)
//	{
//		return QBinder<F, QBindCaller9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> >(m_f,QBindCaller9<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9));
//	}
//
//protected:
//	F m_f;
//};


namespace boost
{
	//template <class F>
	//QSecondPassBinder<F> bind(F f)
	//{
	//	return QSecondPassBinder<F>(f);
	//}

	template <class F>
	QBinder<F,QBindCaller0> bind(F f)
	{
		return QBinder<F, QBindCaller0>(f, QBindCaller0());
	}

	template <class F, class A0>
	QBinder<F,QBindCaller1<A0> > bind(F f, const A0& a0)
	{
		return QBinder<F, QBindCaller1<A0> >(f, QBindCaller1<A0>(a0));
	}

	template <class F, class A0, class A1>
	QBinder<F,QBindCaller2<A0,A1> > bind(F f, const A0& a0, const A1& a1)
	{
		return QBinder<F, QBindCaller2<A0,A1> >(f, QBindCaller2<A0,A1>(a0,a1));
	}

	template <class F, class A0, class A1, class A2>
	QBinder<F,QBindCaller3<A0,A1,A2> > bind(F f, const A0& a0, const A1& a1, const A2& a2)
	{
		return QBinder<F, QBindCaller3<A0,A1,A2> >(f, QBindCaller3<A0,A1,A2>(a0,a1,a2));
	}

	template <class F, class A0, class A1, class A2, class A3>
	QBinder<F,QBindCaller4<A0,A1,A2,A3> > bind(F f, const A0& a0, const A1& a1, const A2& a2, const A3& a3)
	{
		return QBinder<F, QBindCaller4<A0,A1,A2,A3> >(f, QBindCaller4<A0,A1,A2,A3>(a0,a1,a2,a3));
	}

	template <class F, class A0, class A1, class A2, class A3, class A4>
	QBinder<F,QBindCaller5<A0,A1,A2,A3,A4> > bind(F f, const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4)
	{
		return QBinder<F, QBindCaller5<A0,A1,A2,A3,A4> >(f, QBindCaller5<A0,A1,A2,A3,A4>(a0,a1,a2,a3,a4));
	}

	template <class F, class A0, class A1, class A2, class A3, class A4, class A5>
	QBinder<F,QBindCaller6<A0,A1,A2,A3,A4,A5> > bind(F f, const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5)
	{
		return QBinder<F, QBindCaller6<A0,A1,A2,A3,A4,A5> >(f, QBindCaller6<A0,A1,A2,A3,A4,A5>(a0,a1,a2,a3,a4,a5));
	}

	template <class F, class A0, class A1, class A2, class A3, class A4, class A5, class A6>
	QBinder<F,QBindCaller7<A0,A1,A2,A3,A4,A5,A6> > bind(F f, const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6)
	{
		return QBinder<F, QBindCaller7<A0,A1,A2,A3,A4,A5,A6> >(f, QBindCaller7<A0,A1,A2,A3,A4,A5,A6>(a0,a1,a2,a3,a4,a5,a6));
	}

	template <class F, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
	QBinder<F,QBindCaller8<A0,A1,A2,A3,A4,A5,A6,A7> > bind(F f, const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7)
	{
		return QBinder<F, QBindCaller8<A0,A1,A2,A3,A4,A5,A6,A7> >(f, QBindCaller8<A0,A1,A2,A3,A4,A5,A6,A7>(a0,a1,a2,a3,a4,a5,a6,a7));
	}

	template <class F, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
	QBinder<F,QBindCaller9<A0,A1,A2,A3,A4,A5,A6,A7,A8> > bind(F f, const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8)
	{
		return QBinder<F, QBindCaller9<A0,A1,A2,A3,A4,A5,A6,A7,A8> >(f, QBindCaller9<A0,A1,A2,A3,A4,A5,A6,A7,A8>(a0,a1,a2,a3,a4,a5,a6,a7,a8));
	}

	template <class F, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
	QBinder<F,QBindCaller10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> > bind(F f, const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9)
	{
		return QBinder<F, QBindCaller10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> >(f, QBindCaller10<A0,A1,A2,A3,A4,A5,A6,A7,A8,A9>(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9));
	}
}



//template<class F, class TCaller>
//struct QFunctionTraits<QBinder<F,TCaller> > : public QFunctionTraitsBase
//{
//    typedef typename QBinder<F,TCaller>::Params Params;
//    typedef typename QBinder<F,TCaller>::Return Return;
//    typedef typename QBinder<F,TCaller> Wrapper;
//
//    enum
//    {
//		isKnownCallable = 1,
//        isFunctionObject = 1,
//        functionParamCount = QTypeListLength<Params>::value
//    };
//};



//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QBIND_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

