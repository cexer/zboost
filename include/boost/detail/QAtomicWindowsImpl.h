//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QATOMIC_WINDOWS_IMPL_H__
#define __QATOMIC_WINDOWS_IMPL_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QAtomicDetector.h"
#if defined(QHAS_WINDOWS_ATOMIC)


//////////////////////////////////////////////////////////////////////////


#include "QWindowsCommon.h"


////////////////////////////////////////////////////////////////////////////


typedef long qwinodows_atomic_t;


class QAtomicWindowsImpl
{
public:
	inline static long qatomicFetch(const long* value)
	{
		return *(volatile long*)value;
	}

	inline static long qatomicStore(long* value, long newVal)
	{
		return InterlockedExchange((volatile long*)value, newVal);
	}

	inline static long qatomicAdd(long* value, long addVal)
	{
		return InterlockedExchangeAdd((volatile long*)value, addVal) + addVal;
	}

	inline static long qatomicSub(long* value, long subVal)
	{
		return InterlockedExchangeAdd((volatile long*)value, -subVal) - subVal;
	}

	inline static long qatomicCompareAndExchange(long* value, long expected, long newVal)
	{
		return InterlockedCompareExchange((volatile long*)value, newVal, expected);
	}
};







//////////////////////////////////////////////////////////////////////////

#endif //#if defined(QHAS_WINDOWS_ATOMIC)

//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QATOMIC_WINDOWS_IMPL_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

