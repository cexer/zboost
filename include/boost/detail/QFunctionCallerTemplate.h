//premake.vpath=boost/detail
//#define QFunctionCallerN QJOIN(QFunctionCaller, __ARGS)

//template<class R, class F __COMMA __class_Tn>
//static R returnCall(const F& f __COMMA __Pn_pn)
//{
//	typedef typename QFunctionTraits<F>::Return FR;
//	return returnCallCase<R>(IsVoid<R>(), IsVoid<FR>(), f __COMMA __pn);
//}

//template<class R, class F __COMMA __class_Tn>
//static R returnCallCase(QTrue, QTrue, const F& f __COMMA __Pn_pn)
//{
//	f(__rn);
//}
//
//template<class R, class F __COMMA __class_Tn>
//static R returnCallCase(QTrue, QFalse, const F& f __COMMA __Pn_pn)
//{
//	f(__rn);
//}
//
//template<class R, class F __COMMA __class_Tn>
//static R returnCallCase(QFalse, QTrue, const F& f __COMMA __Pn_pn)
//{
//	f(__rn);
//	return R();
//}
//
//template<class R, class F __COMMA __class_Tn>
//static R returnCallCase(QFalse, QFalse, const F& f __COMMA __Pn_pn)
//{
//	return R( f(__rn) );
//}


//template<class R, class F, class C __COMMA __class_Tn>
//static R returnCallMethod(const F& f, const C& c __COMMA __Pn_pn)
//{
//	typedef typename QFunctionTraits<F>::Return FR;
//	return returnCallMethodCase<R>(IsVoid<R>(), IsVoid<FR>(), f, &c __COMMA __pn);
//}
//
//template<class R, class F, class C __COMMA __class_Tn>
//static R returnCallMethod(const F& f, const C* c __COMMA __Pn_pn)
//{
//	typedef typename QFunctionTraits<F>::Return FR;
//	return returnCallMethodCase(IsVoid<R>(), IsVoid<FR>(), f, c __COMMA __Pn_pn);
//}
//
//template<class R, class F, class C __COMMA __class_Tn>
//static R returnCallMethodCase(QTrue, QTrue, const F& f, const C* c __COMMA __Pn_pn)
//{
//	((C*)c->*f)(__rn);
//}
//
//template<class R, class F, class C  __COMMA __class_Tn>
//static R returnCallMethodCase(QTrue, QFalse, const F& f, const C* c __COMMA __Pn_pn)
//{
//	((C*)c->*f)(__rn);
//}
//
//template<class R, class F, class C  __COMMA __class_Tn>
//static R returnCallMethodCase(QFalse, QTrue, const F& f, const C* c __COMMA __Pn_pn)
//{
//	((C*)c->*f)(__rn);
//	return R();
//}
//
//template<class R, class F, class C  __COMMA __class_Tn>
//static R returnCallMethodCase(QFalse, QFalse, const F& f, const C* c __COMMA __Pn_pn)
//{
//	return R( ((C*)c->*f)(__rn) );
//}


template<class R, class F __COMMA __class_Tn>
static R returnCallIfVoid(QTrue, const F& f __COMMA __Pn_pn)
{
	f(__rn);
}

template<class R, class F __COMMA __class_Tn>
static R returnCallIfVoid(QFalse, const F& f __COMMA __Pn_pn)
{
    return f(__rn);
}

template<class R, class F __COMMA __class_Tn>
static R returnCall(const F& f __COMMA __Pn_pn)
{
	return returnCallIfVoid<R>(IsVoid<R>(), f __COMMA __pn);
}


//template<class R, class F __COMMA __class_Tn>
//static R returnCallIfVoid(QFalse, const F& f __COMMA __Pn_pn)
//{
//	return returnCallIfRef<R>(IsReference<R>(), f __COMMA __pn);
//}
//
//
//template<class R, class F __COMMA __class_Tn>
//static R returnCallIfRef(QTrue, const F& f __COMMA __Pn_pn)
//{
//    return f(__rn);
//}
//
//
//template<class R, class F __COMMA __class_Tn>
//static R returnCallIfRef(QFalse, const F& f __COMMA __Pn_pn)
//{
//    return R( f(__rn) );
//}



template<class R, class F, class C __COMMA __class_Tn>
static R returnCallMethodIfVoid(QTrue, const F& f, const C* c __COMMA __Pn_pn)
{
	((C*)c->*f)(__rn);
}

template<class R, class F, class C  __COMMA __class_Tn>
static R returnCallMethodIfVoid(QFalse, const F& f, const C* c __COMMA __Pn_pn)
{
    return R( ((C*)c->*f)(__rn) );
}

template<class R, class F, class C __COMMA __class_Tn>
static R returnCallMethod(const F& f, const C& c __COMMA __Pn_pn)
{
	return returnCallMethodIfVoid<R>(IsVoid<R>(), f, &c __COMMA __pn);
}

//template<class R, class F, class C  __COMMA __class_Tn>
//static R returnCallMethodIfVoid(QFalse, const F& f, const C* c __COMMA __Pn_pn)
//{
//	return returnCallMethodIfRef<R>(IsReference<R>(), f, c __COMMA __pn)
//}
//
//template<class R, class F, class C  __COMMA __class_Tn>
//static R returnCallMethodIfRef(QTrue, const F& f, const C* c __COMMA __Pn_pn)
//{
//    return ((C*)c->*f)(__rn);
//}
//
//template<class R, class F, class C  __COMMA __class_Tn>
//static R returnCallMethodIfRef(QFalse, const F& f, const C* c __COMMA __Pn_pn)
//{
//    return R( ((C*)c->*f)(__rn) );
//}



#undef __ARGS
#undef __COMMA
#undef __class_Tn
#undef __Pn_pn
#undef __pn
#undef __rn

//#undef QFunctionCallerN