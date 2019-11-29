//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QATOMIC_GCC_IMPL_H__
#define __QATOMIC_GCC_IMPL_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QAtomicDetector.h"
#if defined(QHAS_GCC_ATOMIC)


////////////////////////////////////////////////////////////////////////////


typedef long qgcc_atomic_t;


inline static long qatomicFetch(const long* value)
{
	return *(volatile long*)value;
}

inline static long qatomicStore(long* value, long newVal)
{
	return __sync_lock_test_and_set(value, newVal);
}

inline static long qatomicAdd(long* value, long addVal)
{
	return __sync_add_and_fetch(value, addVal);
}

inline static long qatomicSub(long* value, long subVal)
{
	return __sync_sub_and_fetch(value, subVal);
}

inline static long qatomicCompareAndExchange(long* value, long expected, long newVal)
{
	return __sync_val_compare_and_swap(value, expected, newVal);
}





//////////////////////////////////////////////////////////////////////////

#endif //#if defined(QHAS_GCC_ATOMIC)

//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QATOMIC_GCC_IMPL_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

