//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QATOMIC_H__
#define __QATOMIC_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QAtomicBuilder.h"
#include "QAtomicDetector.h"
#include "QCalculatable.h"

//[[ standard include 
#include <utility>
//]]


////////////////////////////////////////////////////////////////////////////


#if defined(QHAS_WINDOWS_ATOMIC)
#   include "QAtomicWindowsImpl.h"
	typedef qwindows_atomic_t qatomic_t;

#elif defined(QHAS_GCC_ATOMIC)
#   include "QAtomicGccImpl.h"
	typedef qgcc_atomic_t qatomic_t;

#elif defined(QHAS_GCC_X64_ATOMIC)
#   include "QAtomicGccX86Impl.h"
	typedef qgcc_x86_atomic_t qatomic_t;

#else
#   error "QKernel: Sorry, QAtomicPlatformImpl is not avaiable."
#endif


class QAtomic : public QIncreasable<QAtomic,qatomic_t>
               , public QDecreasable<QAtomic,qatomic_t>
               , public QAtomicMulFromCASAndFetch<QAtomic,qatomic_t>
               , public QAtomicDivFromCASAndFetch<QAtomic,qatomic_t>
               , public QAtomicModFromCASAndFetch<QAtomic,qatomic_t>
               , public QAtomicOrFromCASAndFetch<QAtomic,qatomic_t>
               , public QAtomicAndFromCASAndFetch<QAtomic,qatomic_t>
               , public QAtomicXorFromCASAndFetch<QAtomic,qatomic_t>
{
public:
    QAtomic(qatomic_t initVal = 0)
        : m_value(initVal)
    {}

    QAtomic& operator=(qatomic_t newVal)
    {
        store(newVal);
        return *this;
    }

    operator qatomic_t() const
    {
        return qatomicFetch(&m_value);
    }

    qatomic_t operator+=(qatomic_t val)
    {
        return qatomicAdd(&m_value, val);
    }

    qatomic_t operator-=(qatomic_t val)
    {
        return qatomicSub(&m_value, val);
    }

    qatomic_t fetch() const
    {
        return qatomicFetch(&m_value);
    }

    qatomic_t store(qatomic_t newVal)
    {
        return qatomicStore(&m_value, newVal);
    }

    qatomic_t compareAndExchange(qatomic_t expected, qatomic_t newVal)
    {
        return qatomicCompareAndExchange(&m_value, expected, newVal);
    }

    void swap(QAtomic& that)
    {
        std::swap(m_value, that.m_value);
    }

protected:
    qatomic_t m_value;
};




template<class T>
inline T qatomicCompareAndExchange(T* value, const T& expected, const T& newVal)
{
    T oldVal = *value;
    if (oldVal == expected)
        *value = newVal;

    return oldVal;
}


inline qatomic_t qatomicCompareAndExchange(QAtomic* value, qatomic_t expected, qatomic_t newVal)
{
    return value->compareAndExchange(expected, newVal);
}



//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QATOMIC_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

