//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QTYPE_LIST_H__
#define __QTYPE_LIST_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QBaseTypes.h"
#include "QIntTypes.h"


////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
// macros QTYPELIST_1, QTYPELIST_2, ... QTYPELIST_50
// Each takes a number of arguments equal to its numeric suffix
// The arguments are type names. QTYPELIST_NN generates a typelist containing 
//     all types passed as arguments, in that order.
// Example: QTYPELIST_2(char, int) generates a type containing char and int.
////////////////////////////////////////////////////////////////////////////////
#define QTYPELIST(COUNT, TYPES)	QJOIN(QTYPELIST_,COUNT) TYPES
#define QTYPELIST_1(T1) QTypeList<T1, QNull>

#define QTYPELIST_2(T1, T2) QTypeList<T1, QTYPELIST_1(T2) >

#define QTYPELIST_3(T1, T2, T3) QTypeList<T1, QTYPELIST_2(T2, T3) >

#define QTYPELIST_4(T1, T2, T3, T4) \
    QTypeList<T1, QTYPELIST_3(T2, T3, T4) >

#define QTYPELIST_5(T1, T2, T3, T4, T5) \
    QTypeList<T1, QTYPELIST_4(T2, T3, T4, T5) >

#define QTYPELIST_6(T1, T2, T3, T4, T5, T6) \
    QTypeList<T1, QTYPELIST_5(T2, T3, T4, T5, T6) >

#define QTYPELIST_7(T1, T2, T3, T4, T5, T6, T7) \
    QTypeList<T1, QTYPELIST_6(T2, T3, T4, T5, T6, T7) >

#define QTYPELIST_8(T1, T2, T3, T4, T5, T6, T7, T8) \
    QTypeList<T1, QTYPELIST_7(T2, T3, T4, T5, T6, T7, T8) >

#define QTYPELIST_9(T1, T2, T3, T4, T5, T6, T7, T8, T9) \
    QTypeList<T1, QTYPELIST_8(T2, T3, T4, T5, T6, T7, T8, T9) >

#define QTYPELIST_10(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) \
    QTypeList<T1, QTYPELIST_9(T2, T3, T4, T5, T6, T7, T8, T9, T10) >

#define QTYPELIST_11(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11) \
    QTypeList<T1, QTYPELIST_10(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11) >


// QTypeList
template <class T, class U>
struct QTypeList;

template <class TList> 
struct QTypeListLength;

template <class TList, int index> 
struct QTypeListAt;

template <class TList, int index, class Def>
struct QTypeListAtNonStrict;

template <class TList, class T> 
struct QTypeListIndexOf;

template <class TList, class T> 
struct QTypeListAppend;

template <class TList, class T> 
struct QTypeListErase;

template <class TList, class T> 
struct QTypeListEraseAll;

template <class TList, class T, class U> 
struct QTypeListReplace;

template <class TList, class T, class U> 
struct QTypeListReplaceAll;

template <class TList> 
struct QTypeListReverse;

template <class TList>
struct QTypeListUnique;

template <class TList, int index, class T, int currentIndex = 0>
struct QTypeListSet;


template <int index, class T, int currentIndex>
struct QTypeListSet<QNull, index, T, currentIndex>
{
    typedef QNull Result;
};

template <class Head, class Tail, int index, class T, int currentIndex>
struct QTypeListSet<QTypeList<Head,Tail>, index, T, currentIndex>
{
    typedef QTypeList<Head, typename QTypeListSet<Tail, index, T, currentIndex + 1>::Result> Result;
};

template <class Head, class Tail, int index, class T>
struct QTypeListSet<QTypeList<Head,Tail>, index, T, index>
{
    typedef QTypeList<T,Tail> Result;
};




//QTypeListUnique
template <>
struct QTypeListUnique<QNull>
{
    typedef QNull Result;
};

template <class Head, class Tail>
struct QTypeListUnique< QTypeList<Head, Tail> >
{
    typedef typename QTypeListUnique<Tail>::Result L1;
    typedef typename QTypeListErase<L1,Head>::Result L2;

public:
    typedef QTypeList<Head,L2> Result;
};




// TypeListLength
template <class TList> 
struct QTypeListLength;

template <> 
struct QTypeListLength<QNull>
{
    enum { value = 0 };
};

template <class T, class U>
struct QTypeListLength< QTypeList<T,U> >
{
    enum { value = 1 + QTypeListLength<U>::value };
};



// TypeListAt
template <class TList, int index> 
struct QTypeListAt;

template <class Head, class Tail>
struct QTypeListAt< QTypeList<Head,Tail>, 0 >
{
    typedef Head Result;
};

template <class Head, class Tail, int i>
struct QTypeListAt< QTypeList<Head,Tail>, i >
{
    typedef typename QTypeListAt< Tail, i-1 >::Result Result;
};


// TypeListAtNonStrict
template <class TList, int index, class Def = QNull>
struct QTypeListAtNonStrict
{
    typedef Def Result;
};

template <class Head, class Tail, class Def>
struct QTypeListAtNonStrict< QTypeList<Head,Tail>, 0, Def >
{
    typedef Head Result;
};

template <class Head, class Tail, int i, class Def>
struct QTypeListAtNonStrict<QTypeList<Head, Tail>, i, Def>
{
    typedef typename QTypeListAtNonStrict< Tail, i-1, Def >::Result Result;
};



// TypeListIndexOf
template <class TList, class T> 
struct QTypeListIndexOf;

template <class T>
struct QTypeListIndexOf< QNull, T >
{
    enum { value = -1 };
};

template <class T, class Tail>
struct QTypeListIndexOf< QTypeList<T,Tail>, T >
{
    enum { value = 0 };
};

template <class Head, class Tail, class T>
struct QTypeListIndexOf< QTypeList<Head,Tail>, T >
{
private:
    enum { temp = QTypeListIndexOf<Tail,T>::value };
public:
    enum { value = (temp == -1 ? -1 : 1 + temp) };
};



// TypeListAppend
template <class TList, class T> 
struct QTypeListAppend;

template <> 
struct QTypeListAppend< QNull, QNull >
{
    typedef QNull Result;
};

template <class T> 
struct QTypeListAppend< QNull, T >
{
    typedef QTypeList< T,QNull > Result;
};

template <class Head, class Tail>
struct QTypeListAppend< QNull, QTypeList<Head,Tail> >
{
    typedef QTypeList<Head, Tail> Result;
};

template <class Head, class Tail, class T>
struct QTypeListAppend< QTypeList<Head,Tail>, T >
{
    typedef QTypeList< Head, typename QTypeListAppend<Tail,T>::Result > Result;
};



// TypeListErase
template <class TList, class T> 
struct QTypeListErase;

template <class T>
struct QTypeListErase< QNull, T >
{
    typedef QNull Result;
};

template <class T, class Tail>
struct QTypeListErase< QTypeList<T,Tail>, T >
{
    typedef Tail Result;
};

template <class Head, class Tail, class T>
struct QTypeListErase< QTypeList<Head,Tail>, T >
{
    typedef QTypeList< Head, typename QTypeListErase<Tail,T>::Result > Result;
};



// TypeListEraseAll
template <class TList, class T> 
struct QTypeListEraseAll;

template <class T>
struct QTypeListEraseAll< QNull, T >
{
    typedef QNull Result;
};

template <class T, class Tail>
struct QTypeListEraseAll< QTypeList<T,Tail>, T >
{
    typedef typename QTypeListEraseAll<Tail, T>::Result Result;
};

template <class Head, class Tail, class T>
struct QTypeListEraseAll< QTypeList<Head, Tail>, T >
{
    typedef QTypeList<Head, typename QTypeListEraseAll<Tail, T>::Result> Result;
};


// TypeListRemoveDuplicates
template <class TList> 
struct QTypeListRemoveDuplicates;

template <> 
struct QTypeListRemoveDuplicates<QNull>
{
    typedef QNull Result;
};

template <class Head, class Tail>
struct QTypeListRemoveDuplicates< QTypeList<Head, Tail> >
{
private:
    typedef typename QTypeListRemoveDuplicates<Tail>::Result L1;
    typedef typename QTypeListErase<L1, Head>::Result L2;
public:
    typedef QTypeList<Head, L2> Result;
};



// TypeListReplace
template <class TList, class T, class U> 
struct QTypeListReplace;

template <class T, class U>
struct QTypeListReplace<QNull, T, U>
{
    typedef QNull Result;
};

template <class T, class Tail, class U>
struct QTypeListReplace<QTypeList<T, Tail>, T, U>
{
    typedef QTypeList<U, Tail> Result;
};

template <class Head, class Tail, class T, class U>
struct QTypeListReplace<QTypeList<Head, Tail>, T, U>
{
    typedef QTypeList< Head,typename QTypeListReplace<Tail,T,U>::Result > Result;
};



// TypeListReplaceAll
template <class TList, class T, class U> 
struct QTypeListReplaceAll;

template <class T, class U>
struct QTypeListReplaceAll< QNull, T, U >
{
    typedef QNull Result;
};

template <class T, class Tail, class U>
struct QTypeListReplaceAll< QTypeList<T,Tail>, T, U >
{
    typedef QTypeList<U, typename QTypeListReplaceAll<Tail, T, U>::Result> Result;
};

template <class Head, class Tail, class T, class U>
struct QTypeListReplaceAll<QTypeList<Head, Tail>, T, U>
{
    typedef QTypeList<Head, typename QTypeListReplaceAll<Tail, T, U>::Result> Result;
};



template <class TList> 
struct QTypeListReverse;

template <>
struct QTypeListReverse<QNull>
{
    typedef QNull Result;
};

template <class Head, class Tail>
struct QTypeListReverse< QTypeList<Head, Tail> >
{
    typedef typename QTypeListAppend< typename QTypeListReverse<Tail>::Result, Head >::Result Result;
};



template <class T, class U>
struct QTypeList
{
    typedef T Head;
    typedef U Tail;

    typedef QTypeList<T,U> Self;
    enum{ length = QTypeListLength<Self>::value };
};





// MakeTypelist
template 
<
    class T1  = QNull, class T2  = QNull, class T3  = QNull,
    class T4  = QNull, class T5  = QNull, class T6  = QNull,
    class T7  = QNull, class T8  = QNull, class T9  = QNull,
    class T10 = QNull, class T11 = QNull, class T12 = QNull,
    class T13 = QNull, class T14 = QNull, class T15 = QNull,
    class T16 = QNull, class T17 = QNull, class T18 = QNull
> 
class QTypeListCreate
{
    typedef typename QTypeListCreate
    <
        T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10, T11, T12, 
        T13, T14, T15, T16, T17, T18
    >
    ::Result TailResult;

public:
    typedef QTypeList<T1, TailResult> Result;
};

template <>
struct QTypeListCreate<>
{
    typedef QNull Result;
};



typedef QTypeListCreate<qint8_t,qint16_t,qint32_t,qint64_t>::Result QSignedIntTypeList;
typedef QTypeListCreate<qint8_t,qint16_t,qint32_t,qint64_t,float,double>::Result QSignedNumberTypeList;
typedef QTypeListCreate<bool, quint8_t,quint16_t,quint32_t,quint64_t>::Result QUnsignedIntTypeList;



//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QTYPE_LIST_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

