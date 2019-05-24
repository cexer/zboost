//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QPOINTER_OF_H__
#define __QPOINTER_OF_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QKernelConfig.h"

//////////////////////////////////////////////////////////////////////////



template<class T>
inline const T* pointerOf(const T* p)
{
	return p;
}

template<class T>
inline T* pointerOf(T* p)
{
	return p;
}

template<class T>
inline const T* pointerOf(const T& p)
{
    return &p;
}

template<class T>
inline T* pointerOf(T& p)
{
    return &p;
}

//template<class T>
//inline const T* pointerOf(const T& p)
//{
//	return &p;
//}
//
//template<class T>
//inline T* pointerOf(T& p)
//{
//	return &p;
//}



//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//#ifndef __QPOINTER_OF_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
