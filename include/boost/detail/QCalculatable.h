//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QOPERATOR_MATH_H__
#define __QOPERATOR_MATH_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QKernelConfig.h"
#include "QMacros.h"


////////////////////////////////////////////////////////////////////////////


// 需要 r = (t op= u)
#define QOPERATOR_OP_LEFT_Q(qualification, R, T, U, op)            \
    qualification R operator op(T t, const U& u){ R r(t); r op##= u; return r; }

// 需要 r = (t op= u)
#define QOPERATOR_OP_RIGHT_Q(qualification, R, T, U, op)           \
    qualification R operator op(const U& u, T t){ R r(t); r op##= u; return r; }

// 需要 r = (t op= u)
#define QOPERATOR_OP_Q(qualification, R, T, U, op)                 \
    QOPERATOR_OP_LEFT_Q(qualification, R, T, U, op)                 \
    QOPERATOR_OP_RIGHT_Q(qualification, R, T, U, op)



// 需要 r = (t += u)
#define QOPERATOR_ADD_LEFT_Q(qualification, R, T, U)                \
    QOPERATOR_OP_LEFT_Q(qualification, R, T, U, +)

// 需要 r = (t += u)
#define QOPERATOR_ADD_RIGHT_Q(qualification, R, T, U)               \
    QOPERATOR_OP_RIGHT_Q(qualification, R, T, U, +)

// 需要 r = (t += u)
#define QOPERATOR_ADD_Q(qualification, R, T, U)                     \
    QOPERATOR_ADD_LEFT_Q(qualification, R, T, U)                     \
    QOPERATOR_ADD_RIGHT_Q(qualification, R, T, U)



// 需要 r = (t -= u)
#define QOPERATOR_SUB_LEFT_Q(qualification, R, T, U)                \
    QOPERATOR_OP_LEFT_Q(qualification, R, T, U, -)

// 需要 r = (t -= u)
#define QOPERATOR_SUB_RIGHT_Q(qualification, R, T, U)               \
    QOPERATOR_OP_RIGHT_Q(qualification, R, T, U, -)

// 需要 r = (t -= u)
#define QOPERATOR_SUB_Q(qualification, R, T, U)                     \
    QOPERATOR_SUB_LEFT_Q(qualification, R, T, U)                     \
    QOPERATOR_SUB_RIGHT_Q(qualification, R, T, U)



// 需要 r = (t *= u)
#define QOPERATOR_MUL_LEFT_Q(qualification, R, T, U)                \
    QOPERATOR_OP_LEFT_Q(qualification, R, T, U, *)

// 需要 r = (t *= u)
#define QOPERATOR_MUL_RIGHT_Q(qualification, R, T, U)               \
    QOPERATOR_OP_RIGHT_Q(qualification, R, T, U, *)

// 需要 r = (t *= u)
#define QOPERATOR_MUL_Q(qualification, R, T, U)                     \
    QOPERATOR_MUL_LEFT_Q(qualification, R, T, U)                     \
    QOPERATOR_MUL_RIGHT_Q(qualification, R, T, U)



// 需要 r = (t /= u)
#define QOPERATOR_DIV_LEFT_Q(qualification, R, T, U)                \
    QOPERATOR_OP_LEFT_Q(qualification, R, T, U, /)

// 需要 r = (t /= u)
#define QOPERATOR_DIV_RIGHT_Q(qualification, R, T, U)               \
    QOPERATOR_OP_RIGHT_Q(qualification, R, T, U, /)

// 需要 r = (t /= u)
#define QOPERATOR_DIV_Q(qualification, R, T, U)                     \
    QOPERATOR_DIV_LEFT_Q(qualification, R, T, U)                     \
    QOPERATOR_DIV_RIGHT_Q(qualification, R, T, U)



// 需要 r = (t %= u)
#define QOPERATOR_MOD_LEFT_Q(qualification, R, T, U)                \
    QOPERATOR_OP_LEFT_Q(qualification, R, T, U, %)

// 需要 r = (t %= u)
#define QOPERATOR_MOD_RIGHT_Q(qualification, R, T, U)               \
    QOPERATOR_OP_RIGHT_Q(qualification, R, T, U, %)

// 需要 r = (t %= u)
#define QOPERATOR_MOD_Q(qualification, R, T, U)                     \
    QOPERATOR_MOD_LEFT_Q(qualification, R, T, U)                     \
    QOPERATOR_MOD_RIGHT_Q(qualification, R, T, U)



////////////////////////////////////////////////////////////////////////////

#define QOPERATOR_ADD_LEFT(R, T, U)     QOPERATOR_ADD_LEFT_Q(public:friend, R, T, U)
#define QOPERATOR_ADD_RIGHT(R, T, U)    QOPERATOR_ADD_RIGHT_Q(public:friend, R, T, U)
#define QOPERATOR_ADD(R, T, U)          QOPERATOR_ADD_Q(public:friend, R, T, U)
#define QOPERATOR_SUB_LEFT(R, T, U)     QOPERATOR_SUB_LEFT_Q(public:friend, R, T, U)
#define QOPERATOR_SUB_RIGHT(R, T, U)    QOPERATOR_SUB_RIGHT_Q(public:friend, R, T, U)
#define QOPERATOR_SUB(R, T, U)          QOPERATOR_SUB_Q(public:friend, R, T, U)
#define QOPERATOR_MUL_LEFT(R, T, U)     QOPERATOR_MUL_LEFT_Q(public:friend, R, T, U)
#define QOPERATOR_MUL_RIGHT(R, T, U)    QOPERATOR_MUL_RIGHT_Q(public:friend, R, T, U)
#define QOPERATOR_MUL(R, T, U)          QOPERATOR_MUL_Q(public:friend, R, T, U)
#define QOPERATOR_DIV_LEFT(R, T, U)     QOPERATOR_DIV_LEFT_Q(public:friend, R, T, U)
#define QOPERATOR_DIV_RIGHT(R, T, U)    QOPERATOR_DIV_RIGHT_Q(public:friend, R, T, U)
#define QOPERATOR_DIV(R, T, U)          QOPERATOR_DIV_Q(public:friend, R, T, U)
#define QOPERATOR_MOD_LEFT(R, T, U)     QOPERATOR_MOD_LEFT_Q(public:friend, R, T, U)
#define QOPERATOR_MOD_RIGHT(R, T, U)    QOPERATOR_MOD_RIGHT_Q(public:friend, R, T, U)
#define QOPERATOR_MOD(R, T, U)          QOPERATOR_MOD_Q(public:friend, R, T, U)




////////////////////////////////////////////////////////////////////////////


template <class T, class U=int, class R=T>
struct QAddableLeft
{
    QOPERATOR_ADD_LEFT(R, T, U)
};

template <class T, class U=int, class R=T>
struct QOperatorAddRight
{
    QOPERATOR_ADD_RIGHT(R, T, U)
};

template <class T, class U=int, class R=T>
struct QAddable
{
    QOPERATOR_ADD(R, T, U)
};



template <class T, class U=T, class R=T>
struct QSubtractableLeft
{
    QOPERATOR_SUB_LEFT(R, T, U)
};

template <class T, class U=T, class R=T>
struct QOperatorSubRight
{
    QOPERATOR_SUB_RIGHT(R, T, U)
};

template <class T, class U=T, class R=T>
struct QSubtractable
{
    QOPERATOR_SUB(R, T, U)
};



template <class T, class U=int, class R=T>
struct QOperatorMulLeft
{
    QOPERATOR_MUL_LEFT(R, T, U)
};

template <class T, class U=int, class R=T>
struct QOperatorMulRight
{
    QOPERATOR_MUL_RIGHT(R, T, U)
};

template <class T, class U=int, class R=T>
struct QMultiplyable
{
    QOPERATOR_MUL(R, T, U)
};



template <class T, class U=int, class R=T>
struct QOperatorDivLeft
{
    QOPERATOR_DIV_LEFT(R, T, U)
};

template <class T, class U=int, class R=T>
struct QOperatorDivRight
{
    QOPERATOR_DIV_RIGHT(R, T, U)
};

template <class T, class U=int, class R=T>
struct QDividable
{
    QOPERATOR_DIV(R, T, U)
};



template <class T, class U=int, class R=T>
struct QOperatorModLeft
{
    QOPERATOR_MOD_LEFT(R, T, U)
};

template <class T, class U=int, class R=T>
struct QOperatorModRight
{
    QOPERATOR_MOD_RIGHT(R, T, U)
};

template <class T, class U=int, class R=T>
struct QOperatorMod
{
    QOPERATOR_MOD(R, T, U)
};

template<class T, class R=T>
struct QIncreasable
{
    inline R operator++()
    {
        return (*static_cast<T*>(this)) += 1;
    }

    inline R operator++(int)
    {
        R r = (*static_cast<T*>(this)) += 1;
        return r - 1;
    }
};

template<class T, class R=T>
struct QDecreasable
{
    inline R operator--()
    {
        return (*static_cast<T*>(this)) -= 1;
    }

    inline R operator--(int)
    {
        R r = (*static_cast<T*>(this)) -= 1;
        return r + 1;
    }
};



//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QOPERATOR_MATH_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

