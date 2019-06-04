//premake.vpath=boost/detail
template <class R>
struct QFunctionPrototypeTraits<R __CALLING ()> : public QFunctionTraitsBase
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 0,
        isFunction = 1,
        functionCallConv = __CALLING_ID,
    };

    typedef QNull Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)();
	typedef R (__CALLING *Prototype)();
};


template <class R, class A>
struct QFunctionPrototypeTraits<R __CALLING (A)> : public QFunctionTraitsBase
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 0,
        isFunction = 1,
        functionCallConv = __CALLING_ID,
        functionParamCount = 1
    };

    typedef QTYPELIST_1(A) Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)(A);
	typedef R (__CALLING *Prototype)(A);
};

template <class R, class A0, class A1>
struct QFunctionPrototypeTraits<R __CALLING (A0,A1)> : public QFunctionTraitsBase 
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 0,
        isFunction = 1,
        functionCallConv = __CALLING_ID,
        functionParamCount = 2
    };

    typedef QTYPELIST_2(A0,A1) Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)(A0,A1);
	typedef R (__CALLING *Prototype)(A0,A1);
};

template <class R, class A0, class A1, class A2>
struct QFunctionPrototypeTraits<R __CALLING (A0,A1,A2)> : public QFunctionTraitsBase 
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 0,
        isFunction = 1,
        functionCallConv = __CALLING_ID,
        functionParamCount = 3
    };

    typedef QTYPELIST_3(A0,A1,A2) Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)(A0,A1,A2);
	typedef R (__CALLING *Prototype)(A0,A1,A2);
};

template <class R, class A0, class A1, class A2, class A3>
struct QFunctionPrototypeTraits<R __CALLING (A0,A1,A2,A3)> : public QFunctionTraitsBase 
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 0,
        isFunction = 1,
        functionCallConv = __CALLING_ID,
        functionParamCount = 4
    };

    typedef QTYPELIST_4(A0,A1,A2,A3) Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)(A0,A1,A2,A3);
	typedef R (__CALLING *Prototype)(A0,A1,A2,A3);
};


template <class R, class A0, class A1, class A2, class A3, class A4>
struct QFunctionPrototypeTraits<R __CALLING (A0,A1,A2,A3,A4)> : public QFunctionTraitsBase
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 0,
        isFunction = 1,
        functionCallConv = __CALLING_ID,
        functionParamCount = 5
    };

    typedef QTYPELIST_5(A0,A1,A2,A3,A4) Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)(A0,A1,A2,A3,A4);
	typedef R (__CALLING *Prototype)(A0,A1,A2,A3,A4);
};

template <class R, class A0, class A1, class A2, class A3, class A4, class A5>
struct QFunctionPrototypeTraits<R __CALLING (A0,A1,A2,A3,A4,A5)> : public QFunctionTraitsBase
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 0,
        isFunction = 1,
        functionCallConv = __CALLING_ID,
        functionParamCount = 6
    };

    typedef QTYPELIST_6(A0,A1,A2,A3,A4,A5) Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)(A0,A1,A2,A3,A4,A5);
	typedef R (__CALLING *Prototype)(A0,A1,A2,A3,A4,A5);
};

template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6>
struct QFunctionPrototypeTraits<R __CALLING (A0,A1,A2,A3,A4,A5,A6)> : public QFunctionTraitsBase
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 0,
        isFunction = 1,
        functionCallConv = __CALLING_ID,
        functionParamCount = 7
    };

    typedef QTYPELIST_7(A0,A1,A2,A3,A4,A5,A6) Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)(A0,A1,A2,A3,A4,A5,A6);
	typedef R (__CALLING *Prototype)(A0,A1,A2,A3,A4,A5,A6);
};


template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
struct QFunctionPrototypeTraits<R __CALLING (A0,A1,A2,A3,A4,A5,A6,A7)> : public QFunctionTraitsBase
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 0,
        isFunction = 1,
        functionCallConv = __CALLING_ID,
        functionParamCount = 8
    };

    typedef QTYPELIST_8(A0,A1,A2,A3,A4,A5,A6,A7) Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)(A0,A1,A2,A3,A4,A5,A6,A7);
	typedef R (__CALLING *Prototype)(A0,A1,A2,A3,A4,A5,A6,A7);
};

template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
struct QFunctionPrototypeTraits<R __CALLING (A0,A1,A2,A3,A4,A5,A6,A7,A8)> : public QFunctionTraitsBase
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 0,
        isFunction = 1,
        functionCallConv = __CALLING_ID,
        functionParamCount = 9
    };

    typedef QTYPELIST_9(A0,A1,A2,A3,A4,A5,A6,A7,A8) Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)(A0,A1,A2,A3,A4,A5,A6,A7,A8);
	typedef R (__CALLING *Prototype)(A0,A1,A2,A3,A4,A5,A6,A7,A8);
};

template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
struct QFunctionPrototypeTraits<R __CALLING (A0,A1,A2,A3,A4,A5,A6,A7,A8,A9)> : public QFunctionTraitsBase
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 0,
        isFunction = 1,
        functionCallConv = __CALLING_ID,
        functionParamCount = 10
    };

    typedef QTYPELIST_10(A0,A1,A2,A3,A4,A5,A6,A7,A8,A9) Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)(A0,A1,A2,A3,A4,A5,A6,A7,A8,A9);
	typedef R (__CALLING *Prototype)(A0,A1,A2,A3,A4,A5,A6,A7,A8,A9);
};

template <class R>
struct QFunctionPointerTraits<R (__CALLING *)()> : public QFunctionTraitsBase
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 1,
        isFunction = 0,
        functionCallConv = __CALLING_ID,
    };

    typedef QNull Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)();
	typedef R (__CALLING *Prototype)();
};

template <class R, class A>
struct QFunctionPointerTraits<R (__CALLING*)(A)> : public QFunctionTraitsBase
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 1,
        isFunction = 0,
        functionCallConv = __CALLING_ID,
        functionParamCount = 1
    };

    typedef QTYPELIST_1(A) Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)(A);
	typedef R (__CALLING *Prototype)(A);
};

template <class R, class A0, class A1>
struct QFunctionPointerTraits<R (__CALLING *)(A0,A1)> : public QFunctionTraitsBase 
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 1,
        isFunction = 0,
        functionCallConv = __CALLING_ID,
        functionParamCount = 2
    };

    typedef QTYPELIST_2(A0,A1) Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)(A0,A1);
	typedef R (__CALLING *Prototype)(A0,A1);
};

template <class R, class A0, class A1, class A2>
struct QFunctionPointerTraits<R (__CALLING *)(A0,A1,A2)> : public QFunctionTraitsBase 
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 1,
        isFunction = 0,
        functionCallConv = __CALLING_ID,
        functionParamCount = 3
    };

    typedef QTYPELIST_3(A0,A1,A2) Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)(A0,A1,A2);
	typedef R (__CALLING *Prototype)(A0,A1,A2);
};

template <class R, class A0, class A1, class A2, class A3>
struct QFunctionPointerTraits<R (__CALLING *)(A0,A1,A2,A3)> : public QFunctionTraitsBase 
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 1,
        isFunction = 0,
        functionCallConv = __CALLING_ID,
        functionParamCount = 4
    };

    typedef QTYPELIST_4(A0,A1,A2,A3) Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)(A0,A1,A2,A3);
	typedef R (__CALLING *Prototype)(A0,A1,A2,A3);
};


template <class R, class A0, class A1, class A2, class A3, class A4>
struct QFunctionPointerTraits<R (__CALLING *)(A0,A1,A2,A3,A4)> : public QFunctionTraitsBase
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 1,
        isFunction = 0,
        functionCallConv = __CALLING_ID,
        functionParamCount = 5
    };

    typedef QTYPELIST_5(A0,A1,A2,A3,A4) Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)(A0,A1,A2,A3,A4);
	typedef R (__CALLING *Prototype)(A0,A1,A2,A3,A4);
};

template <class R, class A0, class A1, class A2, class A3, class A4, class A5>
struct QFunctionPointerTraits<R (__CALLING *)(A0,A1,A2,A3,A4,A5)> : public QFunctionTraitsBase
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 1,
        isFunction = 0,
        functionCallConv = __CALLING_ID,
        functionParamCount = 6
    };

    typedef QTYPELIST_6(A0,A1,A2,A3,A4,A5) Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)(A0,A1,A2,A3,A4,A5);
	typedef R (__CALLING *Prototype)(A0,A1,A2,A3,A4,A5);
};

template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6>
struct QFunctionPointerTraits<R (__CALLING *)(A0,A1,A2,A3,A4,A5,A6)> : public QFunctionTraitsBase
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 1,
        isFunction = 0,
        functionCallConv = __CALLING_ID,
        functionParamCount = 7
    };

    typedef QTYPELIST_7(A0,A1,A2,A3,A4,A5,A6) Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)(A0,A1,A2,A3,A4,A5,A6);
	typedef R (__CALLING *Prototype)(A0,A1,A2,A3,A4,A5,A6);
};


template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
struct QFunctionPointerTraits<R (__CALLING *)(A0,A1,A2,A3,A4,A5,A6,A7)> : public QFunctionTraitsBase
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 1,
        isFunction = 0,
        functionCallConv = __CALLING_ID,
        functionParamCount = 8
    };

    typedef QTYPELIST_8(A0,A1,A2,A3,A4,A5,A6,A7) Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)(A0,A1,A2,A3,A4,A5,A6,A7);
	typedef R (__CALLING *Prototype)(A0,A1,A2,A3,A4,A5,A6,A7);
};

template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
struct QFunctionPointerTraits<R (__CALLING *)(A0,A1,A2,A3,A4,A5,A6,A7,A8)> : public QFunctionTraitsBase
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 1,
        isFunction = 0,
        functionCallConv = __CALLING_ID,
        functionParamCount = 9
    };

    typedef QTYPELIST_9(A0,A1,A2,A3,A4,A5,A6,A7,A8) Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)(A0,A1,A2,A3,A4,A5,A6,A7,A8);
	typedef R (__CALLING *Prototype)(A0,A1,A2,A3,A4,A5,A6,A7,A8);
};

template <class R, class A0, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
struct QFunctionPointerTraits<R (__CALLING *)(A0,A1,A2,A3,A4,A5,A6,A7,A8,A9)> : public QFunctionTraitsBase
{
    enum
    {
		isKnownCallable = 1,
        isFunctionPointer = 1,
        isFunction = 0,
        functionCallConv = __CALLING_ID,
        functionParamCount = 10
    };

    typedef QTYPELIST_10(A0,A1,A2,A3,A4,A5,A6,A7,A8,A9) Params;
    typedef R Return;
	typedef R (__CALLING *Wrapper)(A0,A1,A2,A3,A4,A5,A6,A7,A8,A9);
	typedef R (__CALLING *Prototype)(A0,A1,A2,A3,A4,A5,A6,A7,A8,A9);
};

#undef __CALLING
#undef __CALLING_ID