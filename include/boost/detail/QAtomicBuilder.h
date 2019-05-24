//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QATOMIC_BUILDER_H__
#define __QATOMIC_BUILDER_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QKernelConfig.h"


////////////////////////////////////////////////////////////////////////////


#define _constChild static_cast<const TChild*>(this)
#define _child  static_cast<TChild*>(this)


template<class TChild, class T=long>
class QAtomicStoreFromCASAndFetch
{
public:
    T store(T v)
    {
        T o = _child->fetch();
        while (o != _child->compareAndExchange(v, o))
            o = _child->fetch();

        return o;
    }
};

template<class TChild, class T=long>
class QAtomicAddFromCASAndFetch
{
public:
    T operator+=(T v)
    {
        T o = _child->fetch();
        T n = o + v;

        while (o != _child->compareAndExchange(n, o))
        {
            o = _child->fetch();
            n = o + v;
        }

        return n;
    }
};


template<class TChild, class T=long>
class QAtomicSubFromCASAndFetch
{
public:
    T operator-=(T v)
    {
        T o = _child->fetch();
        T n = o - v;

        while (o != _child->compareAndExchange(n, o))
        {
            o = _child->fetch();
            n = o - v;
        }

        return n;
    }
};


template<class TChild, class T=long>
class QAtomicMulFromCASAndFetch
{
public:
    T operator*=(T v)
    {
        T o = _child->fetch();
        T n = o * v;

        while (o != _child->compareAndExchange(n, o))
        {
            o = _child->fetch();
            n = o * v;
        }

        return n;
    }
};

template<class TChild, class T=long>
class QAtomicDivFromCASAndFetch
{
public:
    T operator/=(T v)
    {
        T o = _child->fetch();
        T n = o / v;

        while (o != _child->compareAndExchange(n, o))
        {
            o = _child->fetch();
            n = o / v;
        }

        return n;
    }
};


template<class TChild, class T=long>
class QAtomicModFromCASAndFetch
{
public:
    T operator%=(T v)
    {
        T o = _child->fetch();
        T n = o % v;

        while (o != _child->compareAndExchange(n, o))
        {
            o = _child->fetch();
            n = o % v;
        }

        return n;
    }
};



template<class TChild, class T=long>
class QAtomicAndFromCASAndFetch
{
public:
    T operator&=(T v)
    {
        T o = _child->fetch();
        T n = o & v;

        while (o != _child->compareAndExchange(n, o))
        {
            o = _child->fetch();
            n = o & v;
        }

        return n;
    }
};



template<class TChild, class T=long>
class QAtomicOrFromCASAndFetch
{
public:
    T operator|=(T v)
    {
        T o = _child->fetch();
        T n = o | v;

        while (o != _child->compareAndExchange(n, o))
        {
            o = _child->fetch();
            n = o | v;
        }

        return n;
    }
};



template<class TChild, class T=long>
class QAtomicXorFromCASAndFetch
{
public:
    T operator^=(T v)
    {
        T o = _child->fetch();
        T n = o ^ v;

        while (o != _child->compareAndExchange(n, o))
        {
            o = _child->fetch();
            n = o ^ v;
        }

        return n;
    }
};



#undef _child
#undef _constChild


//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QATOMIC_BUILDER_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

