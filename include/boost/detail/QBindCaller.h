//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QBIND_CALLER_H__
#define __QBIND_CALLER_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QBasetypes.h"
#include "QFunctionCaller.h"


////////////////////////////////////////////////////////////////////////////


template<class T>
struct QBindStorageType
{
	typedef T Result;
};

template<class T, size_t N>
struct QBindStorageType<T[N]>
{
	typedef T* Result;
};

struct QBindCaller0
{
    typedef QNull Params;

public:
    template <class R, class F, class TArgs>
    R call(const F& f, const TArgs& args) const
    {
		typedef typename QFunctionTraits<F>::Wrapper Wrapper;
        return returnCall<R>(Wrapper(f));
    }
};

template <class T0>
struct QBindCaller1
{
	typedef typename QBindStorageType<T0>::Result A0;
    typedef QTYPELIST_1(A0) Params;

public:
    QBindCaller1(const A0& a0)
        : m_a0(a0)
    {}

    template <class R, class F, class TArgs>
    R call(const F& f, const TArgs& args) const
    {
		typedef typename QFunctionTraits<F>::Wrapper Wrapper;
        return returnCall<R>(Wrapper(f), args.valueOf(&m_a0));
    }

protected:
    A0 m_a0;
};

template <class T0, class T1>
struct QBindCaller2
{
	typedef typename QBindStorageType<T0>::Result A0;
	typedef typename QBindStorageType<T1>::Result A1;
    typedef QTYPELIST_2(A0,A1) Params;

public:
    QBindCaller2(const A0& a0, const A1& a1)
        : m_a0(a0)
        , m_a1(a1)
    {}

    template <class R, class F, class TArgs>
    R call(const F& f, const TArgs& args) const
    {
		typedef typename QFunctionTraits<F>::Wrapper Wrapper;
        return returnCall<R>(Wrapper(f), args.valueOf(&m_a0), args.valueOf(&m_a1));
    }

protected:
    A0 m_a0;
    A1 m_a1;
};


template <class T0, class T1, class T2>
struct QBindCaller3
{
	typedef typename QBindStorageType<T0>::Result A0;
	typedef typename QBindStorageType<T1>::Result A1;
	typedef typename QBindStorageType<T2>::Result A2;
    typedef QTYPELIST_3(A0,A1,A2) Params;

public:
    QBindCaller3(const A0& a0, const A1& a1, const A2& a2)
        : m_a0(a0)
        , m_a1(a1)
        , m_a2(a2)
    {}

public:
    template <class R, class F, class TArgs>
    R call(const F& f, const TArgs& args) const
    {
		typedef typename QFunctionTraits<F>::Wrapper Wrapper;
        return returnCall<R>(Wrapper(f), args.valueOf(&m_a0), args.valueOf(&m_a1), args.valueOf(&m_a2));
    }


protected:
    A0 m_a0;
    A1 m_a1;
    A2 m_a2;
};


template <class T0, class T1, class T2, class T3>
struct QBindCaller4
{
	typedef typename QBindStorageType<T0>::Result A0;
	typedef typename QBindStorageType<T1>::Result A1;
	typedef typename QBindStorageType<T2>::Result A2;
	typedef typename QBindStorageType<T3>::Result A3;
    typedef QTYPELIST_4(A0,A1,A2,A3) Params;

public:
    QBindCaller4(const A0& a0, const A1& a1, const A2& a2, const A3& a3)
        : m_a0(a0)
        , m_a1(a1)
        , m_a2(a2)
        , m_a3(a3)
    {}

public:
    template <class R, class F, class TArgs>
    R call(const F& f, const TArgs& args) const
    {
		typedef typename QFunctionTraits<F>::Wrapper Wrapper;
        return returnCall<R>(Wrapper(f), args.valueOf(&m_a0), args.valueOf(&m_a1), args.valueOf(&m_a2), args.valueOf(&m_a3));
    }

protected:
    A0 m_a0;
    A1 m_a1;
    A2 m_a2;
    A3 m_a3;
};


template <class T0, class T1, class T2, class T3, class T4>
struct QBindCaller5
{
	typedef typename QBindStorageType<T0>::Result A0;
	typedef typename QBindStorageType<T1>::Result A1;
	typedef typename QBindStorageType<T2>::Result A2;
	typedef typename QBindStorageType<T3>::Result A3;
	typedef typename QBindStorageType<T4>::Result A4;
    typedef QTYPELIST_5(A0,A1,A2,A3,A4) Params;

public:
    QBindCaller5(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4)
        : m_a0(a0)
        , m_a1(a1)
        , m_a2(a2)
        , m_a3(a3)
        , m_a4(a4)
    {}

public:
    template <class R, class F, class TArgs>
    R call(const F& f, const TArgs& args) const
    {
		typedef typename QFunctionTraits<F>::Wrapper Wrapper;
        return returnCall<R>(Wrapper(f), args.valueOf(&m_a0), args.valueOf(&m_a1), args.valueOf(&m_a2), args.valueOf(&m_a3), 
            args.valueOf(&m_a4));
    }

protected:
    A0 m_a0;
    A1 m_a1;
    A2 m_a2;
    A3 m_a3;
    A4 m_a4;
};


template <class T0, class T1, class T2, class T3, class T4, class T5>
struct QBindCaller6
{
	typedef typename QBindStorageType<T0>::Result A0;
	typedef typename QBindStorageType<T1>::Result A1;
	typedef typename QBindStorageType<T2>::Result A2;
	typedef typename QBindStorageType<T3>::Result A3;
	typedef typename QBindStorageType<T4>::Result A4;
	typedef typename QBindStorageType<T5>::Result A5;
    typedef QTYPELIST_6(A0,A1,A2,A3,A4,A5) Params;

public:
    QBindCaller6(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5)
        : m_a0(a0)
        , m_a1(a1)
        , m_a2(a2)
        , m_a3(a3)
        , m_a4(a4)
        , m_a5(a5)
    {}

public:
    template <class R, class F, class TArgs>
    R call(const F& f, const TArgs& args) const
    {
		typedef typename QFunctionTraits<F>::Wrapper Wrapper;
        return returnCall<R>(Wrapper(f), args.valueOf(&m_a0), args.valueOf(&m_a1), args.valueOf(&m_a2), args.valueOf(&m_a3), 
            args.valueOf(&m_a4), args.valueOf(&m_a4));
    }

protected:
    A0 m_a0;
    A1 m_a1;
    A2 m_a2;
    A3 m_a3;
    A4 m_a4;
    A5 m_a5;
};

template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
struct QBindCaller7
{
	typedef typename QBindStorageType<T0>::Result A0;
	typedef typename QBindStorageType<T1>::Result A1;
	typedef typename QBindStorageType<T2>::Result A2;
	typedef typename QBindStorageType<T3>::Result A3;
	typedef typename QBindStorageType<T4>::Result A4;
	typedef typename QBindStorageType<T5>::Result A5;
	typedef typename QBindStorageType<T6>::Result A6;
     typedef QTYPELIST_7(A0,A1,A2,A3,A4,A5,A6) Params;

public:
    QBindCaller7(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6)
        : m_a0(a0)
        , m_a1(a1)
        , m_a2(a2)
        , m_a3(a3)
        , m_a4(a4)
        , m_a5(a5)
        , m_a6(a6)
    {}

public:
    template <class R, class F, class TArgs>
    R call(const F& f, const TArgs& args) const
    {
		typedef typename QFunctionTraits<F>::Wrapper Wrapper;
        return returnCall<R>(Wrapper(f), args.valueOf(&m_a0), args.valueOf(&m_a1), args.valueOf(&m_a2), args.valueOf(&m_a3), 
            args.valueOf(&m_a4), args.valueOf(&m_a5), args.valueOf(&m_a6));
    }

protected:
    A0 m_a0;
    A1 m_a1;
    A2 m_a2;
    A3 m_a3;
    A4 m_a4;
    A5 m_a5;
    A6 m_a6;
};


template <class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7>
struct QBindCaller8
{
	typedef typename QBindStorageType<T0>::Result A0;
	typedef typename QBindStorageType<T1>::Result A1;
	typedef typename QBindStorageType<T2>::Result A2;
	typedef typename QBindStorageType<T3>::Result A3;
	typedef typename QBindStorageType<T4>::Result A4;
	typedef typename QBindStorageType<T5>::Result A5;
	typedef typename QBindStorageType<T6>::Result A6;
	typedef typename QBindStorageType<T7>::Result A7;
     typedef QTYPELIST_8(A0,A1,A2,A3,A4,A5,A6,A7) Params;

public:
    QBindCaller8(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7)
        : m_a0(a0)
        , m_a1(a1)
        , m_a2(a2)
        , m_a3(a3)
        , m_a4(a4)
        , m_a5(a5)
        , m_a6(a6)
        , m_a7(a7)
    {}

public:
    template <class R, class F, class TArgs>
    R call(const F& f, const TArgs& args) const
    {
		typedef typename QFunctionTraits<F>::Wrapper Wrapper;
        return returnCall<R>(Wrapper(f), args.valueOf(&m_a0), args.valueOf(&m_a1), args.valueOf(&m_a2), args.valueOf(&m_a3), 
            args.valueOf(&m_a4), args.valueOf(&m_a5), args.valueOf(&m_a6), args.valueOf(&m_a7));
    }

protected:
    A0 m_a0;
    A1 m_a1;
    A2 m_a2;
    A3 m_a3;
    A4 m_a4;
    A5 m_a5;
    A6 m_a6;
    A7 m_a7;
};


template <class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
struct QBindCaller9
{
	typedef typename QBindStorageType<T0>::Result A0;
	typedef typename QBindStorageType<T1>::Result A1;
	typedef typename QBindStorageType<T2>::Result A2;
	typedef typename QBindStorageType<T3>::Result A3;
	typedef typename QBindStorageType<T4>::Result A4;
	typedef typename QBindStorageType<T5>::Result A5;
	typedef typename QBindStorageType<T6>::Result A6;
	typedef typename QBindStorageType<T7>::Result A7;
	typedef typename QBindStorageType<T8>::Result A8;
     typedef QTYPELIST_9(A0,A1,A2,A3,A4,A5,A6,A7,A8) Params;

public:
    QBindCaller9(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8)
        : m_a0(a0)
        , m_a1(a1)
        , m_a2(a2)
        , m_a3(a3)
        , m_a4(a4)
        , m_a5(a5)
        , m_a6(a6)
        , m_a7(a7)
        , m_a8(a8)
    {}

public:
    template <class R, class F, class TArgs>
    R call(const F& f, const TArgs& args) const
    {
		typedef typename QFunctionTraits<F>::Wrapper Wrapper;
        return returnCall<R>(Wrapper(f), args.valueOf(&m_a0), args.valueOf(&m_a1), args.valueOf(&m_a2), args.valueOf(&m_a3), 
            args.valueOf(&m_a4), args.valueOf(&m_a5), args.valueOf(&m_a6), args.valueOf(&m_a7), args.valueOf(&m_a8));
    }

protected:
    A0 m_a0;
    A1 m_a1;
    A2 m_a2;
    A3 m_a3;
    A4 m_a4;
    A5 m_a5;
    A6 m_a6;
    A7 m_a7;
    A8 m_a8;
};



template <class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9>
struct QBindCaller10
{
	typedef typename QBindStorageType<T0>::Result A0;
	typedef typename QBindStorageType<T1>::Result A1;
	typedef typename QBindStorageType<T2>::Result A2;
	typedef typename QBindStorageType<T3>::Result A3;
	typedef typename QBindStorageType<T4>::Result A4;
	typedef typename QBindStorageType<T5>::Result A5;
	typedef typename QBindStorageType<T6>::Result A6;
	typedef typename QBindStorageType<T7>::Result A7;
	typedef typename QBindStorageType<T8>::Result A8;
	typedef typename QBindStorageType<T9>::Result A9;
     typedef QTYPELIST_10(A0,A1,A2,A3,A4,A5,A6,A7,A8,A9) Params;

public:
    QBindCaller10(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9)
        : m_a0(a0)
        , m_a1(a1)
        , m_a2(a2)
        , m_a3(a3)
        , m_a4(a4)
        , m_a5(a5)
        , m_a6(a6)
        , m_a7(a7)
        , m_a8(a8)
        , m_a9(a9)
    {}

public:
    template <class R, class F, class TArgs>
    R call(const F& f, const TArgs& args) const
    {
		typedef typename QFunctionTraits<F>::Wrapper Wrapper;
        return returnCall<R>(Wrapper(f), 
			args.valueOf(&m_a0), args.valueOf(&m_a1), args.valueOf(&m_a2), args.valueOf(&m_a3), 
			args.valueOf(&m_a4), args.valueOf(&m_a5), args.valueOf(&m_a6), args.valueOf(&m_a7), 
			args.valueOf(&m_a8), args.valueOf(&m_a9));
    }

protected:
    A0 m_a0;
    A1 m_a1;
    A2 m_a2;
    A3 m_a3;
    A4 m_a4;
    A5 m_a5;
    A6 m_a6;
    A7 m_a7;
    A8 m_a8;
    A9 m_a9;
};



//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QBIND_CALLER_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

