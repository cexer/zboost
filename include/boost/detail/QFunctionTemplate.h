//premake.vpath=boost/detail

#define QFunctionImplN         QJOIN(QFunctionImpl, __ARGS)
#define QFunctionCallerN       QJOIN(QFunctionCaller, __ARGS)
#define QFunctionFunctionImplN QJOIN(QFunctionFunctionImpl, __ARGS)
#define QFunctionMethodImplN   QJOIN(QFunctionMethodImpl, __ARGS)

template<class R __COMMA __class_Tn>
class QFunctionImplN
{
    __typedef_Pn;
public:
    virtual ~QFunctionImplN(){}
    virtual R invoke(__Pn_pn) const = 0;
    virtual QFunctionImplN* clone() const = 0;
};


template<class R, class F __COMMA __class_Tn>
class QFunctionFunctionImplN : public QFunctionImplN<R __COMMA __Tn>
                              //, public QNewable< QFunctionFunctionImplN<R,F __COMMA __Tn> >
{
    __typedef_Pn;
public:
    QFunctionFunctionImplN(const F& f)
        : m_f(f)
    {
    }

    virtual R invoke(__Pn_pn) const
    {
        return returnCall<R>(m_f __COMMA __pn);
    }

    virtual QFunctionImplN<R __COMMA __Tn>* clone() const
    {
        return new QFunctionFunctionImplN(m_f);
    }

protected:
    F m_f;
};


//template<class R, class C, class F __COMMA __class_Tn>
//class QFunctionMethodImplN : public QFunctionImplN<R __COMMA __Tn>
//                            , public QNewable< QFunctionMethodImplN<R,C,F __COMMA __Tn> >
//{
//    __typedef_Pn;
//public:
//    QFunctionMethodImplN(F f, const C* c)
//        : m_f(f)
//		, m_c((C*)c)
//    {}
//
//    virtual R invoke(__Pn_pn) const
//    {
//        return returnCallMethod<R>(m_f, m_c __COMMA __pn);
//    }
//
//    virtual QFunctionImplN<R __COMMA __Tn>* clone() const
//    {
//        return new QFunctionMethodImplN(m_f, m_c);
//    }
//
//protected:
//    C* m_c;
//    F m_f;
//};


namespace boost
{



template<class R __COMMA __class_Tn>
class function<R (__Tn)>
{
    typedef void (function::*UnspecificBool)();
    void unspecificTrue(){}
    __typedef_Pn;

public:
    typedef R Return;
    typedef typename QTypeListCreate<__Tn>::Result Params;

public:
    function()
    {

    }

   ~function()
    {

    }

    template<class F>
    function(const F& f)
    {
		_construct(f);
    }

	function(const function& f)
		: m_impl(f.m_impl)
	{}

    template<class F>
    function& operator=(const F& f)
    {
		_construct(f);
        return *this;
    }

    R operator()(__Tn_an) const
    {
        QASSERT(m_impl);
        return m_impl->invoke(__an);
    }

    operator UnspecificBool() const
    {
        return m_impl ? &function::unspecificTrue : NULL;
    }

    void reset()
    {
        m_impl.reset();
    }

    void swap(function& that)
    {
        m_impl.swap(that.m_impl);
    }

protected:
	typedef QTrue _F_isRawCallable;
	typedef QFalse _F_notRawCallable;

    template<class F>
    void _construct(const F& f)
    {
        //_constructCase(LogicOr<IsMethodPointer<F>, IsFunction<F> >(), f);
        _constructCase(IsRawCallable<F>(), f);
    }

    template<class F>
    void _constructCase(_F_isRawCallable, const F& f)
    {
		typedef typename QFunctionTraits<F>::Wrapper Wrapper;
        m_impl.reset(new QFunctionFunctionImplN<R,Wrapper __COMMA __Tn>(f));
    }

    template<class F>
    void _constructCase(_F_notRawCallable, const F& f)
    {
        m_impl.reset(new QFunctionFunctionImplN<R,F __COMMA __Tn>(f));
    }

    typedef QFunctionImplN<R __COMMA __Tn> Impl;
    boost::shared_ptr<Impl> m_impl;
};

};//namespace boost


#undef QFunctionImplN
#undef QFunctionCallerN
#undef QFunctionFunctionImplN
#undef QFunctionMethodImplN


#undef __ARGS
#undef __COMMA
#undef __class_Tn
#undef __typedef_Pn
#undef __Tn
#undef __Tn_an
#undef __Pn
#undef __Pn_pn
#undef __pn
#undef __rn
#undef __an
