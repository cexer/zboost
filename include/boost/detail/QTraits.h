//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QTRAITS_H__
#define __QTRAITS_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QBaseTypes.h"
#include "QTypeList.h"


////////////////////////////////////////////////////////////////////////////

template<class U, class V>
struct IsSampeType : public QFalse
{
};

template<class U>
struct IsSampeType<U,U> : public QTrue
{
};


template<class U, class V>
class TypeConversion
{
    static QTrue test(V*);
    static QFalse test(...);

public:
    enum { exists = sizeof(test((U*)0)) == sizeof(test((V*)0)) };
    enum { exists2way = exists && TypeConversion<V,U>::exists };
};


template<class U>
struct ReferenceTraits
{
    typedef U NonQualified;
    enum { isQualified = 0 };
};

template<class U>
struct ReferenceTraits<U&>
{
    typedef U NonQualified;
    enum { isQualified = 1 };
};

template<class T>
struct IsReference : public QBoolean<ReferenceTraits<T>::isQualified>
{

};

template<class T>
struct RemoveReference
{
    typedef typename ReferenceTraits<T>::NonQualified Result;
};


template<class U>
struct PointerTraits
{
    typedef U NonQualified;
    enum { isQualified = 0 };
};

template<class U>
struct PointerTraits<U*>
{
    typedef U NonQualified;
    enum { isQualified = 1 };
};

template<class U>
struct PointerTraits<U*&>
{
    typedef U NonQualified;
    enum { isQualified = 1 };
};

template<class U>
struct IsPointer : public QBoolean<PointerTraits<U>::isQualified>
{

};

template<class U>
struct RemovePointer
{
	typedef typename PointerTraits<U>::NonQualified Result;
};


template<class U>
struct ConstTraits
{
    typedef U NonQualified;
    enum{ isQualified = 0 };
};

template<class U>
struct ConstTraits<const U>
{
    typedef U NonQualified;
    enum{ isQualified = 1 };
};

template<class U>
struct ConstTraits<const U&>
{
    typedef U& NonQualified;
    enum{ isQualified = 1 };
};


template<class U>
struct VolatileTraits
{
    typedef U NonQualified;
    enum{ isQualified = 0 };
};

template<class U>
struct VolatileTraits<volatile U>
{
    typedef U NonQualified;
    enum{ isQualified = 1 };
};

template<class U>
struct VolatileTraits<volatile U&>
{
    typedef U& NonQualified;
    enum{ isQualified = 1 };
};


template<class T>
struct IsVoid : public QFalse
{};

template<>
struct IsVoid<void> : public QTrue
{};


template<class T>
struct IsSignedNumber : public QBoolean<QTypeListIndexOf<QSignedIntTypeList,T>::value != -1>
{};

template<class T>
struct IsUnsignedNumber : public QBoolean<QTypeListIndexOf<QUnsignedIntTypeList,T>::value != -1>
{};

template<class T>
struct IsArray : public QFalse{};


template<class T, size_t n>
struct IsArray<T[n]> : public QTrue{};



template<class T>
struct ClassTraits
{
    template<class U> static QTrue test(void(U::*)(void));  
    template<class U> static QFalse test(...);  

    enum{ isClass = (sizeof(test<T>(0)) == sizeof(QTrue)) };
};  

template<class T>  
struct IsClass : QBoolean<ClassTraits<T>::isClass>
{};

template<class T>
class QTraits
{
    template<class U, class V>
    class TypeConversion
    {
        static QTrue test(V*);
        static QFalse test(...);

    public:
        enum { exists = sizeof(test((U*)0)) == sizeof(test((V*)0)) };
        enum { exists2way = exists && TypeConversion<V,U>::exists };
    };

    typedef typename ConstTraits<T>::NonQualified _NonConst;
    typedef typename ReferenceTraits<_NonConst>::NonQualified _NonRef;
    typedef typename PointerTraits<_NonRef>::NonQualified _NonPtr;
    typedef typename VolatileTraits<_NonPtr>::NonQualified _NonVola;

public:
    typedef typename ConstTraits<T>::NonQualified NonConst;
    typedef typename ReferenceTraits<T>::NonQualified NonReference;
    typedef typename PointerTraits<T>::NonQualified NonPointer;
    typedef typename VolatileTraits<T>::NonQualified NonVolatile;
    typedef _NonVola NonQualified;

    enum
    {
        isPointer = PointerTraits<T>::isQualified,
        isReference = ReferenceTraits<T>::isQualified,
        isVolatile = VolatileTraits<T>::isQualified,
        isConst = ConstTraits<T>::isQualified,
        isQualified = isPointer || isConst || isReference || isVolatile,
		isSignedInt = IsSignedNumber<T>::value,
		isSignedNumber = IsSignedNumber<T>::value,
        isUnsignedNumber = IsSignedNumber<T>::value,
        isClass = ClassTraits<T>::isClass,
		isArray = IsArray<T>::value
    };

    template<class U>
    struct isType : public IsSampeType<T,U>
    {};

    template<class U>
    struct convertableTo : public QBoolean<TypeConversion<T,U>::exists>
    {};

    template<class U>
    struct convertableFrom : public QBoolean<TypeConversion<U,T>::exists>
    {};
};


template<class T>
struct SelctParameterType
{
    typedef const T& Result;
};

template<class T>
struct SelctParameterType<T&>
{
    typedef T& Result;
};

template<class T>
struct SelctParameterType<const T&>
{
    typedef const T& Result;
};


template<class T>
struct SelectPointerType
{
    typedef T* Result;
};

template<class T>
struct SelectPointerType<T&>
{
    typedef T* Result;
};

template<class T>
struct SelectPointerType<const T&>
{
    typedef const T* Result;
};



//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QTRAITS_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

