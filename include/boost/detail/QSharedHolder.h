//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QSHARED_HOLDER_H__
#define __QSHARED_HOLDER_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QSharedForward.h"
#include "QAssert.h"
//#include "QNewable.h"
#include "QTypeInfo.h"
#include <new>


////////////////////////////////////////////////////////////////////////////


class ISharedHolder
{
public:
    virtual ~ISharedHolder(){}
    virtual long sharedCount() const = 0;
    virtual long sharedCountIncreaseWithLock() = 0;
    virtual long sharedCountIncrease() = 0;
    virtual long sharedCountDecrease() = 0;

    virtual long watchedCount() const = 0;
    virtual long watchedCountIncrease() = 0;
    virtual long watchedCountDecrease() = 0;

    virtual void dispose() = 0;
    virtual void destroy()
    {
        delete this;
    }

    virtual void* sharedData(QTypeInfo info = NULL) const = 0;
	template<class T>
	T* sharedDataOf() const
	{
		return (T*)sharedData(typeid(T));
	}
};

class QWatchHolder
{
public:
    QWatchHolder()
        : m_count(NULL)
    {}

    QWatchHolder(const QWatchHolder& that)
        : m_count(that.m_count)
    {
        if (m_count) 
            m_count->watchedCountIncrease();
    }

   ~QWatchHolder()
    {
        if (m_count) 
        {
            m_count->watchedCountDecrease();
            m_count = NULL;
        }
    }

    QWatchHolder& operator=(const QWatchHolder& that)
    {
        if (that.m_count != m_count)
        {
            if (that.m_count) 
                that.m_count->watchedCountIncrease();

            if (m_count) 
                m_count->watchedCountDecrease();

            m_count = that.m_count;
        }

        return *this;
    }


    QWatchHolder(const QSharedHolder& that);
    QWatchHolder& operator=(const QSharedHolder& that);


    void swap(QWatchHolder& that)
    {
        std::swap(m_count, that.m_count);
    }

    long sharedCount() const
    {
        return m_count ? m_count->sharedCount(): 0;
    }

	bool expired() const
	{
		return !m_count || m_count->sharedCount() == 0;
	}

    bool empty() const
    {
        return !m_count;
    }

	ISharedHolder* holder() const
	{
		return m_count;
	}

    bool operator<(const QWatchHolder& that) const
    {
        return m_count < that.m_count;
    }

private:
    friend class QSharedHolder;
    ISharedHolder* m_count;
};


class QSharedHolderAtomicImpl : public ISharedHolder
{
public:
    QSharedHolderAtomicImpl()
        : m_sharedCount(1)
        , m_watchedCount(1)
    {}

public:
    virtual long sharedCount() const
    {
        QASSERT(m_sharedCount >= 0);
        return m_sharedCount;
    }

    virtual long sharedCountIncrease()
    {
        QASSERT(m_sharedCount >= 1);
        return ++ m_sharedCount;
    }

    virtual long sharedCountIncreaseWithLock()
    {
        QASSERT(m_sharedCount >= 0);
        while (true)
        {
            long o = m_sharedCount;
            if (o == 0)
                return 0;

            if (o == qatomicCompareAndExchange(&m_sharedCount, o, o + 1))
                return m_sharedCount;
        }
        return 0;
    }

    virtual long sharedCountDecrease()
    {
        QASSERT(m_sharedCount > 0);

        if (-- m_sharedCount == 0)
        {
            dispose();
            watchedCountDecrease();
            return 0;
        }
        return m_sharedCount;
    }

    virtual long watchedCount() const
    {
        return m_watchedCount;
    }

    virtual long watchedCountIncrease()
    {
        QASSERT(m_watchedCount >= 0);
        return ++ m_watchedCount;
    }

    virtual long watchedCountDecrease()
    {
        QASSERT(m_watchedCount >= 0);
        if (-- m_watchedCount == 0)
        {
            destroy();
            return 0;
        }
        return m_watchedCount;
    }

    QAtomic m_sharedCount;
    QAtomic m_watchedCount;
};

template<class T>
class QSharedHolderImplBase : public QSharedHolderAtomicImpl
{
public:
    QSharedHolderImplBase(T* p)
        : m_p(p)
    {}

public:
    virtual void* sharedData(QTypeInfo info) const
    {
        if (m_sharedCount <= 0)
            return NULL;

        if (!info || info == typeid(T))
            return (void*)m_p;

        return NULL;
    }
    
    void reset()
    {
	m_p = NULL;	
    }

protected:
    T* m_p;
};

template<class T>
class QSharedHolderImplT : public QSharedHolderImplBase<T>
                          //, public QNewable<QSharedHolderImplT<T> >
{
	 using QSharedHolderImplBase<T>::m_p;
public:
    QSharedHolderImplT(T* p)
        : QSharedHolderImplBase<T>(p)
    {}

    virtual void dispose()
    {
        delete m_p;
        m_p = NULL;
    }
};

template<class T, class TDelete>
class QSharedHolderImplTD : public QSharedHolderImplBase<T>
                           //, public QNewable<QSharedHolderImplTD<T,TDelete> >
{
	using QSharedHolderImplBase<T>::m_p;
public:
    QSharedHolderImplTD(T* p, TDelete d)
        : QSharedHolderImplBase<T>(p)
        , m_d(d)
    {}

    virtual void dispose()
    {
        m_d(m_p);
        m_p = NULL;
    }

protected:
    TDelete m_d;
};


template<class T, class TDelete, class TAllocator>
class QSharedHolderImplTDA : public QSharedHolderImplBase<T>
{
    typedef QSharedHolderImplTDA _This;
    typedef typename TAllocator::template rebind<_This>::other _Allocator;
	using QSharedHolderImplBase<T>::m_p;

public:
    QSharedHolderImplTDA(T* p, TDelete d, TAllocator a)
        : QSharedHolderImplBase<T>(p)
		, m_d(d)
		, m_a(a)
    {}

	virtual void dispose()
	{
        m_d(m_p);
		m_p = NULL;
	}

    virtual void destroy()
    {
        _Allocator a = m_a;
        this->~_This();
        a.deallocate(this, sizeof(_This));
    }

protected:
    _Allocator m_a;
	TDelete m_d;
};


class QSharedHolder
{
public:
    template<class T>
    explicit QSharedHolder(T* p)
        : m_holder(new QSharedHolderImplT<T>(p))
    {}

    explicit QSharedHolder(ISharedHolder* h)
        : m_holder(NULL)
    {
        if (h && h->sharedCountIncreaseWithLock())
            m_holder = h;
    }

    template<class T, class D>
    QSharedHolder(T* p, D d)
        : m_holder(new QSharedHolderImplTD<T,D>(p,d))
    {}

    template<class T, class D, class A>
    QSharedHolder(T* p, D d, A a)
        : m_holder(NULL)
    {
        typedef QSharedHolderImplTDA<T,D,A> Impl;

        typedef typename A::template rebind<Impl>::other _A;
        _A _a(a);
        Impl* m = NULL;
        try
        {
            m = _a.allocate(1, (Impl*)NULL);
            if (NULL == m)
                throw std::bad_alloc();
            new (m) Impl(p,d,a);
            m_holder = m;
        }
        catch (const std::exception& e)
        {
            const char* s = e.what();
            //ZION_UNUSED(s);
            
            d(p);
            if (NULL != m_holder)
            {
                _a.deallocate(m, sizeof(Impl));
                m = NULL;
            }
        }
    }

    QSharedHolder()
        : m_holder(NULL)
    {}

    QSharedHolder(const QSharedHolder& rhs)
        : m_holder(rhs.m_holder)
    {
        if (m_holder)
            m_holder->sharedCountIncrease();
    }

    QSharedHolder(const QWatchHolder& that)
        : m_holder(that.m_count)
    {
        if (m_holder && !m_holder->sharedCountIncreaseWithLock())
            m_holder = NULL;
    }

   ~QSharedHolder()
    {
        if (m_holder)
        {
            m_holder->sharedCountDecrease();
            m_holder = NULL;
        }
    }

    QSharedHolder& operator=(const QSharedHolder& rhs)
    {
        if (this != &rhs)
        {
            if (rhs.m_holder)
                rhs.m_holder->sharedCountIncrease();

            if (m_holder)
            {
                m_holder->sharedCountDecrease();
                m_holder = NULL;
            }

            m_holder = rhs.m_holder;
        }

        return *this;
    }

public:
    bool addRef()
    {
        if (m_holder && m_holder->sharedCount())
        {
            m_holder->sharedCountIncrease();
            return true;
        }
        else
            return false;
    }

    bool release()
    {
        if (m_holder && m_holder->sharedCount())
        {
            m_holder->sharedCountDecrease();
            return true;
        }
        else
            return false;
    }

    void swap(QSharedHolder& rhs)
    {
        std::swap(m_holder, rhs.m_holder);
    }

    long sharedCount() const
    {
        return m_holder ? m_holder->sharedCount() : 0;
    }

    bool unique() const
    {
        return m_holder ? m_holder->sharedCount() == 1: false;
    }

    void reset()
    {
        if (m_holder)
        {
            m_holder->sharedCountDecrease();
            m_holder = NULL;
        }
    }

	ISharedHolder* holder() const
	{
		return m_holder;
	}

protected:
    friend class QWatchHolder;
    ISharedHolder* m_holder;
};



inline QWatchHolder::QWatchHolder(const QSharedHolder& that)
    : m_count(that.m_holder)
{
    if (m_count) 
        m_count->watchedCountIncrease();
}

inline QWatchHolder& QWatchHolder::operator=(const QSharedHolder& that)
{
    if (that.m_holder != m_count)
    {
        if (that.m_holder) 
            that.m_holder->watchedCountIncrease();

        if (m_count) 
            m_count->watchedCountDecrease();

        m_count = that.m_holder;
    }
    return *this;
}


//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QSHARED_HOLDER_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
