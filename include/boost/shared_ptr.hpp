//premake.vpath=boost
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QSHARED_H__
#define __QSHARED_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "detail/QSharedHolder.h"
#include "detail/QBooleanable.h"
#include "detail/QNoop.h"
#include "detail/QPointerOf.h"
#include "detail/IAbstract.h"
#include <new>


////////////////////////////////////////////////////////////////////////////



template<class T>
struct QSharedDefaultDeleter
{
public:
    void operator()(T* p) const
    {
        delete p;
    }
};

int inline sharedTypeId(...)
{
    return -1;
}

namespace boost
{






template<class T>
class shared_ptr : public QValidCheckable< shared_ptr<T> >
               , public IAbstract
{
    typedef QNull (*NullPtr)(QNull);
public:
    shared_ptr(NullPtr = NULL)
        : m_p(NULL)
    {
        _initSharedTypeId((T*)0);
    }

    shared_ptr(const shared_ptr& that)
        :m_p(NULL)
    {
        _initSharedTypeId((T*)0);
        reset(that);
    }

    template<class U>
    explicit shared_ptr(U* p)
        :m_p(NULL)
    {
        _initSharedTypeId((T*)0);
        reset(p);
    }

    template<class U>
    shared_ptr(U* p, const QSharedHolder& h)
        :m_p(NULL)
    {
        _initSharedTypeId((T*)0);
        reset(p, h);
    }

    template<class U>
    shared_ptr(U* p, const QWatchHolder& h)
        :m_p(NULL)
    {
        _initSharedTypeId((T*)0);
        reset(p, h);
    }

	template<class U, class TDelete>
    shared_ptr(U* p, TDelete d)
        :m_p(NULL)
    {
        _initSharedTypeId((T*)0);
        reset(p, d);
    }

    template<class U, class TDelete, class TAllocator>
    shared_ptr(U* p, TDelete d, TAllocator a)
        :m_p(NULL)
    {
        _initSharedTypeId((T*)0);
        reset(p, d, a);
    }

    template<class U>
    shared_ptr(const shared_ptr<U>& that)
        :m_p(NULL)
    {
        _initSharedTypeId((T*)0);
        reset(that);
    }

    template<class U>
    shared_ptr(T* p, const shared_ptr<U>& that)
        :m_p(NULL)
    {
        _initSharedTypeId((T*)0);
        reset(p, that);
    }

    template<class U>
    shared_ptr& operator=(const shared_ptr<U>& that)
    {
        reset(that);
        return *this;
    }

    shared_ptr& operator=(const shared_ptr& that)
    {
        reset(that);
        return *this;
    }

    ~shared_ptr()
    {

    }

    T* operator->() const
    {
        QASSERT(m_p && m_h.sharedCount() != 0);
        return get();
    }

    T& operator*() const
    {
        QASSERT(m_p && m_h.sharedCount() != 0);
        return *get();
    }

    T* get() const
    {
        return const_cast<T*>(m_p);
    }

    bool valid() const
    {
        return m_p != NULL && m_h.sharedCount() != 0;
    }

    shared_ptr& reset()
    {
        _initSharedTypeId((T*)0);
        m_p = NULL;
        m_h.reset();
        return *this;
    }

    template<class U>
    shared_ptr& reset(U* u, const QSharedHolder& c)
    {
        T* p = static_cast<T*>(u);
        QASSERT(NULL == p || p != m_p);
        if (NULL != p && p == m_p)
            return *this;

        reset();
        if (NULL != p)
        {
            m_p = p;
            m_h = c;
        }

        return *this;
    }

    template<class U>
    shared_ptr& reset(U* u, const QWatchHolder& c)
    {
        T* p = static_cast<T*>(u);
        QASSERT(NULL == p || p != m_p);
        if (NULL != p && p == m_p)
            return *this;

        reset();
        if (NULL != p)
        {
            m_p = p;
            QSharedHolder(c).swap(m_h);
        }

        return *this;
    }

    template<class U>
    shared_ptr& reset(U* u)
    {
        T* p = static_cast<T*>(u);
        QASSERT(NULL == p || p != m_p);
        if (NULL != p && p == m_p)
            return *this;

        reset();
        if (NULL != p)
        {
            m_p = p;
            QSharedHolder(p).swap(m_h);
        }
		_initEmbedWeakCount(IsSharable<U>(), u);
        return *this;
    }


    template<class U, class D>
    shared_ptr& reset(U* u, D d)
    {
        T* p = static_cast<T*>(u);
        QASSERT(NULL == p || p != m_p);
        if (NULL != p && p == m_p)
            return *this;
        
        reset();
        if (NULL != p)
        {
            m_p = p;
            QSharedHolder(p,d).swap(m_h);
        }
		_initEmbedWeakCount(IsSharable<U>(), u);
        return *this;
    }

    template<class U, class D, class A>
    shared_ptr& reset(U* u, D d, A a)
    {
        T* p = static_cast<T*>(u);
        QASSERT(NULL == p || p != m_p);
        if (NULL != p && p == m_p)
            return *this;

        reset();
        if (NULL != p)
        {
            m_p = p;
            QSharedHolder(p,d,a).swap(m_h);
        }
		_initEmbedWeakCount(IsSharable<U>(), u);
        return *this;
    }

    template<class U>
    shared_ptr& reset(const shared_ptr<U>& that)
    {
        T* p = static_cast<T*>(that.get());
        if (NULL != p && p == m_p)
            return *this;

        reset();
        m_p = p;
        m_h = that.m_h;

        return *this;
    }

    template<class U>
    shared_ptr& dynamicReset(U* p)
    {
        return reset(dynamic_cast<T*>(p));
    }

    template<class U, class D, class A>
    shared_ptr& dynamicReset(U* p, D d, A a)
    {
        return reset(dynamic_cast<T*>(p), d, a);
    }

    template<class U>
    shared_ptr& dynamicReset(const shared_ptr<U>& that)
    {
        return reset(dynamic_cast<T*>(that.get()), that.m_h);
    }

    template<class U>
    shared_ptr& reinterpretReset(U* p)
    {
        return reset(reinterpret_cast<T*>(p));
    }

    template<class U, class D, class A>
    shared_ptr& reinterpretReset(U* p, D d, A a)
    {
        return reset(reinterpret_cast<T*>(p), d, a);
    }

    template<class U>
    shared_ptr& reinterpretReset(const shared_ptr<U>& that)
    {
        return reset(reinterpret_cast<T*>(that.get()), that.m_h);
    }

    template<class U>
    shared_ptr& polymorphicReset(U* p)
    {
#if defined(_DEBUG)
        return reset(dynamic_cast<T*>(p));
#else
        return reset(reinterpret_cast<T*>(p));
#endif
    }

    template<class U, class D, class A>
    shared_ptr& polymorphicReset(U* p, D d, A a)
    {
#if defined(_DEBUG)
        return reset(dynamic_cast<T*>(p), d, a);
#else
        return reset(reinterpret_cast<T*>(p), d, a);
#endif
    }

    template<class U>
    shared_ptr& polymorphicReset(const shared_ptr<U>& that)
    {
#if defined(_DEBUG)
        return reset(dynamic_cast<T*>(that.get()), that.m_h);
#else
        return reset(reinterpret_cast<T*>(that.get()), that.m_h);
#endif
    }

	//template<class U>
	//QShared& universalReset(const QShared<U>& that)
	//{
	//	return reset(universal_cast<T*>(that.get()), that.m_h);
	//}

    bool addRef() const
    {
        return m_h.addRef();
    }

    bool release() const
    {
        return m_h.release();
    }

    long sharedCount() const
    {
        return m_h.sharedCount();
    }

	ISharedHolder* holder() const
	{
		return m_h.holder();
	}

    bool unique() const
    {
        return m_h.unique();
    }

    shared_ptr& swap(shared_ptr& that)
    {
        std::swap(m_p, that.m_p);
        std::swap(m_h, that.m_h);
        return *this;
    }

    template<class U>
    bool operator<(const shared_ptr<U>& r) const
    {
        return m_p < static_cast<T*>(r.m_p);
    }

    template<class U>
    bool operator==(const shared_ptr<U>& r) const
    {
        return !(*this < r) && !(r < *this);
    }

    template<class U>
    bool operator!=(const shared_ptr<U>& r) const
    {
        return !(*this == r);
    }

protected:
    template<class U>
    friend class shared_ptr;

    template<class U>
    friend class weak_ptr;

	typedef QTrue _U_isSharable;
	typedef QFalse _U_notSharable;

    template<class U>
    void _initEmbedWeakCount(_U_notSharable, U*)
	{}

    template<class U>
    void _initEmbedWeakCount(_U_isSharable, U* u)
	{
		u->m_watchHolder = m_h;
	}

    T* m_p;
    QSharedHolder m_h;

#if defined(QDEBUG)
    int m_typeName;
    template<class U>
    void _initSharedTypeId(U* p)
    {
        m_typeName = sharedTypeId(p);
    }
#else
    template<class U>
    void _initSharedTypeId(U* p)
    {}
#endif
};



template<class T>
inline T* pointerOf(const shared_ptr<T>& p)
{ return p.get();
}


template<class T>
inline const T* pointerOf(const shared_ptr<const T>& p)
{
    return p.get();
}



template<class T>
inline void swap(shared_ptr<T>& a, shared_ptr<T>& b)
{
    a.swap(b);
}


template<class T, class S>
inline shared_ptr<T> shared_static_cast(const shared_ptr<S>& s)
{
    return shared_ptr<T>(s);
}


template<class T, class S>
inline shared_ptr<T> shared_dynamic_cast(const shared_ptr<S>& s)
{
    shared_ptr<T> p;
    p.dynamicReset(s);
    return p;
}

template<class T, class S>
inline shared_ptr<T> shared_reinterpret_cast(const shared_ptr<S>& s)
{
    shared_ptr<T> p;
    p.reinterpretReset(s);
    return p;
}

template<class T, class S>
inline shared_ptr<T> shared_polymorphic_cast(const shared_ptr<S>& s)
{
    shared_ptr<T> p;
    p.polymorphicReset(s);
    return p;
}

//template<class T, class S>
//inline QShared<T> shared_universal_cast(const QShared<S>& s)
//{
//    QShared<T> p;
//    p.universalReset(s);
//    return p;
//}

//template<class T, class D>
//inline QShared<T> shared(T* p, D d)
//{
//    return QShared<T>(p, d);
//}
//
//
//template<class T>
//inline QShared<T> shared(T* p)
//{
//    return QShared<T>(p, QSharedDefaultDeleter<T>());
//}
//
//template<class T>
//inline QShared<T> sharedNoDelete(T* p)
//{
//    return QShared<T>(p, noop);
//}



};//namespace boost





//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QSHARED_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

