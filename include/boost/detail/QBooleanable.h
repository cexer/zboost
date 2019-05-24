//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QOPERATOR_BOOL_H__
#define __QOPERATOR_BOOL_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QKernelConfig.h"

////////////////////////////////////////////////////////////////////////////


//class QBooleanableBase
//{
//protected:
//    struct __UnspecifiedType { void _unspecified_true(){} };
//    typedef __UnspecifiedType _UnspecifiedType;  
//    typedef void (_UnspecifiedType::*_UnspecifiedBool)();
//};


template <class T>
class QNonComparable
{
    void this_type_does_not_support_comparisons() const {}
};

#define QDEFINE_BOOLEANABLE_CLASS(NAME, COND)                                  \
template <class T>                                                           \
class NAME : public QNonComparable<T>                                        \
{                                                                              \
protected:                                                                    \
    struct _UnspecifiedType { void _unspecified_true(){} };                  \
    typedef void (_UnspecifiedType::*_UnspecifiedBool)();                    \
public:                                                                       \
    inline operator _UnspecifiedBool() const                                \
    {                                                                          \
        return (COND) ? &_UnspecifiedType::_unspecified_true : 0;             \
    }                                                                          \
protected:                                                                    \
    const T& _derived() const { return *static_cast<const T*>(this); }    \
    const T* _cthis() const  { return static_cast<const T*>(this); }      \
};



QDEFINE_BOOLEANABLE_CLASS(QValidCheckable,      _cthis()->valid());
QDEFINE_BOOLEANABLE_CLASS(QCheckable,           _cthis()->check());
QDEFINE_BOOLEANABLE_CLASS(QSucceededCheckable,  _cthis()->succeeded());
QDEFINE_BOOLEANABLE_CLASS(QExistsCheckable,     _cthis()->exists());
QDEFINE_BOOLEANABLE_CLASS(QNotEmptyCheckable,  !_cthis()->empty());
QDEFINE_BOOLEANABLE_CLASS(QSatisfiyCheckable,   _cthis()->satisfied());
QDEFINE_BOOLEANABLE_CLASS(QNoErrorCheckable,   !_cthis()->error());
QDEFINE_BOOLEANABLE_CLASS(QOccuredCheckable,    _cthis()->occured());



//#define QBOOLEANABLE_DERIVED(base, cond)                                        \
//protected:                                                                    \
//    typedef base::_UnspecifiedBool _UnspecifiedBool;                          \
//    typedef base::_UnspecifiedType _UnspecifiedType;                          \
//public:                                                                       \
//    inline operator _UnspecifiedBool() const                                \
//    {                                                                          \
//        return (this->cond) ? &_UnspecifiedType::_unspecified_true : 0;       \
//    }                                                                          \



//#define QOPERATOR_BOOL(name, cond)                                            \
//    QBOOLEANABLE_DERIVED(name, QBooleanableBase, cond)


class IValidCheckable : public QValidCheckable<IValidCheckable>
{
public:
    virtual bool valid() const = 0;
};



//template <typename T> 
//inline bool operator==(const QNonComparable<T>& lhs, bool b) 
//{
//    return b == static_cast<bool>((const T&)lhs);
//}
//
//template <typename T> 
//inline bool operator==(bool b, const QNonComparable<T>& rhs) 
//{
//    return b == static_cast<bool>((const T&)rhs);
//}


template <typename T, typename U> 
inline bool operator==(const QNonComparable<T>& lhs,const QNonComparable<U>& rhs) 
{
    lhs.this_type_does_not_support_comparisons();
    return false;
}

template <typename T,typename U> 
inline bool operator!=(const QNonComparable<T>& lhs,const QNonComparable<U>& rhs) 
{
    lhs.this_type_does_not_support_comparisons();
    return false;
}


//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif //__QOPERATOR_BOOL_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

