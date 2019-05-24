//premake.vpath=boost/detail
//#pragma message(vSTRINGLIZE(vEXPAND(__CALLING __QUALIFICATION)))

template <class R, class C>
struct QFunctionTraits<R (__CALLING C::*)() __QUALIFICATION> 
{
    enum
    {
		isKnownCallable = 1,
        isMethodPointer = 1,
        isConstQualified = __IS_CONST_Q,
        isVolatileQualified = __IS_VOLATILE_Q,
        functionCallconv = __CALLING_ID,
    };

    typedef QNull Params;
    typedef R Return;
    typedef C Object;
	typedef R (__CALLING C::*Prototype)() __QUALIFICATION;
	typedef QMethodWrapper<C,Prototype,R> Wrapper;
};


template <class R, class C,class A>
struct QFunctionTraits<R (__CALLING C::*)(A) __QUALIFICATION> 
{
    enum
    {
		isKnownCallable = 1,
        isMethodPointer = 1,
        isConstQualified = __IS_CONST_Q,
        isVolatileQualified = __IS_VOLATILE_Q,
        functionCallconv = __CALLING_ID,
        functionArgCount = 1
    };

    typedef QTYPELIST_1(A) Params;
    typedef R Return;
    typedef C Object;
	typedef R (__CALLING C::*Prototype)(A) __QUALIFICATION;
	typedef QMethodWrapper<C,Prototype,R,A> Wrapper;
};

template <class R, class C,class A0, class A1>
struct QFunctionTraits<R (__CALLING C::*)(A0,A1) __QUALIFICATION> 
{
    enum
    {
		isKnownCallable = 1,
        isMethodPointer = 1,
        isConstQualified = __IS_CONST_Q,
        isVolatileQualified = __IS_VOLATILE_Q,
        functionCallconv = __CALLING_ID,
        functionArgCount = 2
    };

    typedef QTYPELIST_2(A0,A1) Params;
    typedef R Return;
    typedef C Object;
	typedef R (__CALLING C::*Prototype)(A0,A1) __QUALIFICATION;
	typedef QMethodWrapper<C,Prototype,R,A0,A1> Wrapper;
};

template <class R, class C,class A0, class A1, class A2>
struct QFunctionTraits<R (__CALLING C::*)(A0,A1,A2) __QUALIFICATION> 
{
    enum
    {
		isKnownCallable = 1,
        isMethodPointer = 1,
        isConstQualified = __IS_CONST_Q,
        isVolatileQualified = __IS_VOLATILE_Q,
        functionCallconv = __CALLING_ID,
        functionArgCount = 3
    };

    typedef QTYPELIST_3(A0,A1,A2) Params;
    typedef R Return;
    typedef C Object;
	typedef R (__CALLING C::*Prototype)(A0,A1,A2) __QUALIFICATION;
	typedef QMethodWrapper<C,Prototype,R,A0,A1,A2> Wrapper;
};

template <class R, class C,class A0, class A1, class A2, class A3>
struct QFunctionTraits<R (__CALLING C::*)(A0,A1,A2,A3) __QUALIFICATION> 
{
    enum
    {
		isKnownCallable = 1,
        isMethodPointer = 1,
        isConstQualified = __IS_CONST_Q,
        isVolatileQualified = __IS_VOLATILE_Q,
        functionCallconv = __CALLING_ID,
        functionArgCount = 4
    };

    typedef QTYPELIST_4(A0,A1,A2,A3) Params;
    typedef R Return;
    typedef C Object;
	typedef R (__CALLING C::*Prototype)(A0,A1,A2,A3) __QUALIFICATION;
	typedef QMethodWrapper<C,Prototype,R,A0,A1,A2,A3> Wrapper;
};

template <class R, class C,class A0, class A1, class A2, class A3, class A4>
struct QFunctionTraits<R (__CALLING C::*)(A0,A1,A2,A3,A4) __QUALIFICATION> 
{
    enum
    {
		isKnownCallable = 1,
        isConstQualified = __IS_CONST_Q,
        isVolatileQualified = __IS_VOLATILE_Q,
        functionCallconv = __CALLING_ID,
        functionArgCount = 5
    };

    typedef QTYPELIST_5(A0,A1,A2,A3,A4) Params;
    typedef R Return;
    typedef C Object;
	typedef R (__CALLING C::*Prototype)(A0,A1,A2,A3,A4) __QUALIFICATION;
	typedef QMethodWrapper<C,Prototype,R,A0,A1,A2,A3,A4> Wrapper;
};

template <class R, class C,class A0, class A1, class A2, class A3, class A4, class A5>
struct QFunctionTraits<R (__CALLING C::*)(A0,A1,A2,A3,A4,A5) __QUALIFICATION> 
{
    enum
    {
		isKnownCallable = 1,
        isMethodPointer = 1,
        isConstQualified = __IS_CONST_Q,
        isVolatileQualified = __IS_VOLATILE_Q,
        functionCallconv = __CALLING_ID,
        functionArgCount = 6
    };

    typedef QTYPELIST_6(A0,A1,A2,A3,A4,A5) Params;
    typedef R Return;
    typedef C Object;
	typedef R (__CALLING C::*Prototype)(A0,A1,A2,A3,A4,A5) __QUALIFICATION;
	typedef QMethodWrapper<C,Prototype,R,A0,A1,A2,A3,A4,A5> Wrapper;
};

template <class R, class C,class A0, class A1, class A2, class A3, class A4, class A5, class A6>
struct QFunctionTraits<R (__CALLING C::*)(A0,A1,A2,A3,A4,A5,A6) __QUALIFICATION> 
{
    enum
    {
		isKnownCallable = 1,
        isMethodPointer = 1,
        isConstQualified = __IS_CONST_Q,
        isVolatileQualified = __IS_VOLATILE_Q,
        functionCallconv = __CALLING_ID,
        functionArgCount = 7
    };

    typedef QTYPELIST_7(A0,A1,A2,A3,A4,A5,A6) Params;
    typedef R Return;
    typedef C Object;
	typedef R (__CALLING C::*Prototype)(A0,A1,A2,A3,A4,A5,A6) __QUALIFICATION;
	typedef QMethodWrapper<C,Prototype,R,A0,A1,A2,A3,A4,A5,A6> Wrapper;
};

template <class R, class C,class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
struct QFunctionTraits<R (__CALLING C::*)(A0,A1,A2,A3,A4,A5,A6,A7) __QUALIFICATION> 
{
    enum
    {
		isKnownCallable = 1,
        isMethodPointer = 1,
        isConstQualified = __IS_CONST_Q,
        isVolatileQualified = __IS_VOLATILE_Q,
        functionCallconv = __CALLING_ID,
        functionArgCount = 8
    };

    typedef QTYPELIST_8(A0,A1,A2,A3,A4,A5,A6,A7) Params;
    typedef R Return;
    typedef C Object;
	typedef R (__CALLING C::*Prototype)(A0,A1,A2,A3,A4,A5,A6,A7) __QUALIFICATION;
	typedef QMethodWrapper<C,Prototype,R,A0,A1,A2,A3,A4,A5,A6,A7> Wrapper;
};

template <class R, class C,class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
struct QFunctionTraits<R (__CALLING C::*)(A0,A1,A2,A3,A4,A5,A6,A7,A8) __QUALIFICATION> 
{
    enum
    {
		isKnownCallable = 1,
        isMethodPointer = 1,
        isConstQualified = __IS_CONST_Q,
        isVolatileQualified = __IS_VOLATILE_Q,
        functionCallconv = __CALLING_ID,
        functionArgCount = 9
    };

    typedef QTYPELIST_9(A0,A1,A2,A3,A4,A5,A6,A7,A8) Params;
    typedef R Return;
    typedef C Object;
	typedef R (__CALLING C::*Prototype)(A0,A1,A2,A3,A4,A5,A6,A7,A8) __QUALIFICATION;
	typedef QMethodWrapper<C,Prototype,R,A0,A1,A2,A3,A4,A5,A6,A7,A8> Wrapper;
};

template <class R, class C,class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
struct QFunctionTraits<R (__CALLING C::*)(A0,A1,A2,A3,A4,A5,A6,A7,A8,A9) __QUALIFICATION> 
{
    enum
    {
		isKnownCallable = 1,
        isMethodPointer = 1,
        isConstQualified = __IS_CONST_Q,
        isVolatileQualified = __IS_VOLATILE_Q,
        functionCallconv = __CALLING_ID,
        functionArgCount = 9
    };

    typedef QTYPELIST_10(A0,A1,A2,A3,A4,A5,A6,A7,A8,A9) Params;
    typedef R Return;
    typedef C Object;
	typedef R (__CALLING C::*Prototype)(A0,A1,A2,A3,A4,A5,A6,A7,A8,A9) __QUALIFICATION;
	typedef QMethodWrapper<C,Prototype,R,A0,A1,A2,A3,A4,A5,A6,A7,A8,A9> Wrapper;
};


#undef __CALLING
#undef __CALLING_ID