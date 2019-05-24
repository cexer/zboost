//premake.vpath=boost
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QWATCH_H__
#define __QWATCH_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "shared_ptr.hpp"


////////////////////////////////////////////////////////////////////////////


namespace boost
{






template<class T>
class weak_ptr
{
public:
    weak_ptr() 
        : m_p(0)
    {
    }

    //  The "obvious" converting constructor implementation:
    //
    //  template<class U>
    //  QWatch(QWatch<U> const & r): m_p(r.m_p), m_c(r.m_c) // never throws
    //  {
    //  }
    //
    //  has a serious problem.
    //
    //  r.m_p may already have been invalidated. The m_p(r.m_p)
    //  conversion may require access to *that.m_p (virtual inheritance).
    //
    //  It is not possible to avoid spurious access violations since
    //  in multithreaded programs r.m_p may be invalidated at any point.
    //
    template<class U>
    weak_ptr(const weak_ptr<U>& that)
        : m_p(that.lock().get())
        , m_h(that.m_c)
    {}

    template<class U>
    weak_ptr(U* that)
        : m_p(static_cast<T*>(that))
    {}

    template<class U>
    weak_ptr(const shared_ptr<U>& that)
        : m_p(that.m_p)
        , m_h(that.m_h)
    {}

    template<class U>
    weak_ptr& operator=(const weak_ptr<U>& that)
    {
        if (this != &that)
        {
            m_p = that.lock().get();
            m_h = that.m_h;
        }
        return *this;
    }

    template<class U>
    weak_ptr& operator=(const shared_ptr<U>& that)
    {
        m_p = that.m_p;
        m_h = that.m_h;
        return *this;
    }

    shared_ptr<T> lock() const
    {
        return shared_ptr<T>(m_p, m_h);
    }

    long sharedCount() const
    {
        return m_h.sharedCount();
    }

	ISharedHolder* holder() const
	{
		return m_h.holder();
	}

    bool expired() const
    {
        return m_h.sharedCount() == 0;
    }

    bool empty() const
    {
        return m_h.empty();
    }

    void reset()
    {
        weak_ptr().swap(*this);
    }

    T* unsafe() const
    {
        return m_p;
    }

    void swap(weak_ptr& that)
    {
        std::swap(m_p, that.m_p);
        m_h.swap(that.m_h);
    }

    template<class U>
    bool operator<(const weak_ptr<U>& r) const
    {
        return m_p < static_cast<T*>(r.m_p);
    }

    template<class U>
    bool operator==(const weak_ptr<U>& r) const
    {
        return !(*this < r) && !(r < *this);
    }

    template<class U>
    bool operator!=(const weak_ptr<U>& r) const
    {
        return !(*this == r);
    }

private:
    template<class U> 
    friend class weak_ptr;

    template<class U> 
    friend class shared_ptr;

    T* m_p;
    QWatchHolder m_h;
};


};//namespace boost




//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QWATCH_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
