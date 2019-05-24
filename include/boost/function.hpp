//premake.vpath=boost
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QFUNCTION_H__
#define __QFUNCTION_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "detail/QFunctionCaller.h"
#include "shared_ptr.hpp"


////////////////////////////////////////////////////////////////////////////


namespace boost
{

template<class TSignature>
class function;

}


#define __ARGS 0
#define __COMMA
#define __class_Tn
#define __typedef_Pn
#define __Tn
#define __Tn_an
#define __Pn
#define __Pn_pn
#define __pn
#define __rn
#define __an
#include "detail/QFunctionTemplate.h"


#define __ARGS 1
#define __COMMA      ,
#define __class_Tn   class T0
#define __typedef_Pn typedef typename QTraits<T0>::NonReference P0
#define __Tn         T0
#define __Tn_an      T0 a0
#define __Pn         P0*
#define __Pn_pn      P0* p0
#define __pn         p0
#define __rn        *p0
#define __an         &a0
#include "detail/QFunctionTemplate.h"


#define __ARGS 2
#define __COMMA      ,
#define __class_Tn   class T0, class T1
#define __typedef_Pn                                   \
    typedef typename QTraits<T0>::NonReference P0;    \
    typedef typename QTraits<T1>::NonReference P1
#define __Tn         T0, T1
#define __Tn_an      T0 a0, T1 a1
#define __Pn         P0*, P1*
#define __Pn_pn      P0* p0, P1* p1
#define __pn         p0, p1
#define __rn        *p0, *p1
#define __an         &a0, &a1
#include "detail/QFunctionTemplate.h"


#define __ARGS 3
#define __COMMA      ,
#define __class_Tn   class T0, class T1, class T2
#define __typedef_Pn                                   \
    typedef typename QTraits<T0>::NonReference P0;    \
    typedef typename QTraits<T1>::NonReference P1;    \
    typedef typename QTraits<T2>::NonReference P2
#define __Tn         T0, T1, T2
#define __Tn_an      T0 a0, T1 a1, T2 a2
#define __Pn         P0*, P1*, P2*
#define __Pn_pn      P0* p0, P1* p1, P2* p2
#define __pn         p0, p1, p2
#define __rn        *p0, *p1, *p2
#define __an         &a0, &a1, &a2
#include "detail/QFunctionTemplate.h"

#define __ARGS 4
#define __COMMA      ,
#define __class_Tn   class T0, class T1, class T2, class T3
#define __typedef_Pn                                   \
    typedef typename QTraits<T0>::NonReference P0;    \
    typedef typename QTraits<T1>::NonReference P1;    \
    typedef typename QTraits<T2>::NonReference P2;    \
    typedef typename QTraits<T3>::NonReference P3
#define __Tn         T0, T1, T2, T3
#define __Tn_an      T0 a0, T1 a1, T2 a2, T3 a3
#define __Pn         P0*, P1*, P2*, P3*
#define __Pn_pn      P0* p0, P1* p1, P2* p2, P3* p3
#define __pn         p0, p1, p2, p3
#define __rn        *p0, *p1, *p2, *p3
#define __an         &a0, &a1, &a2, &a3
#include "detail/QFunctionTemplate.h"

#define __ARGS 5
#define __COMMA      ,
#define __class_Tn   class T0, class T1, class T2, class T3, class T4
#define __typedef_Pn                                   \
    typedef typename QTraits<T0>::NonReference P0;    \
    typedef typename QTraits<T1>::NonReference P1;    \
    typedef typename QTraits<T2>::NonReference P2;    \
    typedef typename QTraits<T3>::NonReference P3;    \
    typedef typename QTraits<T4>::NonReference P4
#define __Tn         T0, T1, T2, T3, T4
#define __Tn_an      T0 a0, T1 a1, T2 a2, T3 a3, T4 a4
#define __Pn         P0*, P1*, P2*, P3*, P4*
#define __Pn_pn      P0* p0, P1* p1, P2* p2, P3* p3, P4* p4
#define __pn         p0, p1, p2, p3, p4
#define __rn        *p0, *p1, *p2, *p3, *p4
#define __an         &a0, &a1, &a2, &a3, &a4
#include "detail/QFunctionTemplate.h"

#define __ARGS 6
#define __COMMA      ,
#define __class_Tn   class T0, class T1, class T2, class T3, class T4, class T5
#define __typedef_Pn                                   \
    typedef typename QTraits<T0>::NonReference P0;    \
    typedef typename QTraits<T1>::NonReference P1;    \
    typedef typename QTraits<T2>::NonReference P2;    \
    typedef typename QTraits<T3>::NonReference P3;    \
    typedef typename QTraits<T4>::NonReference P4;    \
    typedef typename QTraits<T5>::NonReference P5
#define __Tn         T0, T1, T2, T3, T4, T5
#define __Tn_an      T0 a0, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5
#define __Pn         P0*, P1*, P2*, P3*, P4*, P5*
#define __Pn_pn      P0* p0, P1* p1, P2* p2, P3* p3, P4* p4, P5* p5
#define __pn         p0, p1, p2, p3, p4, p5
#define __rn        *p0, *p1, *p2, *p3, *p4, *p5
#define __an         &a0, &a1, &a2, &a3, &a4, &a5
#include "detail/QFunctionTemplate.h"

#define __ARGS 7
#define __COMMA      ,
#define __class_Tn   class T0, class T1, class T2, class T3, class T4, class T5, class T6
#define __typedef_Pn                                   \
    typedef typename QTraits<T0>::NonReference P0;    \
    typedef typename QTraits<T1>::NonReference P1;    \
    typedef typename QTraits<T2>::NonReference P2;    \
    typedef typename QTraits<T3>::NonReference P3;    \
    typedef typename QTraits<T4>::NonReference P4;    \
    typedef typename QTraits<T5>::NonReference P5;    \
    typedef typename QTraits<T6>::NonReference P6
#define __Tn         T0, T1, T2, T3, T4, T5, T6
#define __Tn_an      T0 a0, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6
#define __Pn         P0*, P1*, P2*, P3*, P4*, P5*, P6*
#define __Pn_pn      P0* p0, P1* p1, P2* p2, P3* p3, P4* p4, P5* p5, P6* p6
#define __pn         p0, p1, p2, p3, p4, p5, p6
#define __rn        *p0, *p1, *p2, *p3, *p4, *p5, *p6
#define __an         &a0, &a1, &a2, &a3, &a4, &a5, &a6
#include "detail/QFunctionTemplate.h"


#define __ARGS 8
#define __COMMA      ,
#define __class_Tn   class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7
#define __typedef_Pn                                   \
    typedef typename QTraits<T0>::NonReference P0;    \
    typedef typename QTraits<T1>::NonReference P1;    \
    typedef typename QTraits<T2>::NonReference P2;    \
    typedef typename QTraits<T3>::NonReference P3;    \
    typedef typename QTraits<T4>::NonReference P4;    \
    typedef typename QTraits<T5>::NonReference P5;    \
    typedef typename QTraits<T6>::NonReference P6;    \
    typedef typename QTraits<T7>::NonReference P7
#define __Tn         T0, T1, T2, T3, T4, T5, T6, T7
#define __Tn_an      T0 a0, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7
#define __Pn         P0*, P1*, P2*, P3*, P4*, P5*, P6*, P7*
#define __Pn_pn      P0* p0, P1* p1, P2* p2, P3* p3, P4* p4, P5* p5, P6* p6, P7* p7
#define __pn         p0, p1, p2, p3, p4, p5, p6, p7
#define __rn        *p0, *p1, *p2, *p3, *p4, *p5, *p6, *p7
#define __an         &a0, &a1, &a2, &a3, &a4, &a5, &a6, &a7
#include "detail/QFunctionTemplate.h"


#define __ARGS 9
#define __COMMA      ,
#define __class_Tn   class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8
#define __typedef_Pn                                   \
    typedef typename QTraits<T0>::NonReference P0;    \
    typedef typename QTraits<T1>::NonReference P1;    \
    typedef typename QTraits<T2>::NonReference P2;    \
    typedef typename QTraits<T3>::NonReference P3;    \
    typedef typename QTraits<T4>::NonReference P4;    \
    typedef typename QTraits<T5>::NonReference P5;    \
    typedef typename QTraits<T6>::NonReference P6;    \
    typedef typename QTraits<T7>::NonReference P7;    \
    typedef typename QTraits<T8>::NonReference P8
#define __Tn         T0, T1, T2, T3, T4, T5, T6, T7, T8
#define __Tn_an      T0 a0, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8
#define __Pn         P0*, P1*, P2*, P3*, P4*, P5*, P6*, P7*, P8*
#define __Pn_pn      P0* p0, P1* p1, P2* p2, P3* p3, P4* p4, P5* p5, P6* p6, P7* p7, P8* p8
#define __pn         p0, p1, p2, p3, p4, p5, p6, p7, p8
#define __rn        *p0, *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8
#define __an         &a0, &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8
#include "detail/QFunctionTemplate.h"



//template <class TSignature>
//struct QFunctionTraits< QFunction<TSignature> >
//{
//    typedef typename QFunction<TSignature>::Params Params;
//    typedef typename QFunction<TSignature>::Return Return;
//    typedef typename QFunction<TSignature> Wrapper;
//
//    enum
//    {
//		isKnownCallable = 1,
//        isFunction = 1,
//        isFunctionObject = 1,
//        functionParamCount = QTypeListLength<Params>::value
//    };
//};
//
//
//typedef QFunction<void ()> QVoidFunction;
//typedef QFunction<bool ()> QBoolFunction;



//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QFUNCTION_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

