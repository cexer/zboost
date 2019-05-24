//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QBIND_PARAMS_H__
#define __QBIND_PARAMS_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QTypeList.h"


////////////////////////////////////////////////////////////////////////////



template<class ParamsOld, class T, int indexOld, class ParamsNew>
struct QBindParamsUpdate
{
    typedef ParamsNew Result;
};

template<class ParamsOld, int indexNew, int indexOld, class ParamsNew>
struct QBindParamsUpdate<ParamsOld, QPlaceHolder<indexNew>, indexOld, ParamsNew>
{
    typedef typename QTypeListAt<ParamsOld, indexOld>::Result Param;
    typedef typename QTypeListSet<ParamsNew, indexNew, Param>::Result Result;  
};


typedef QTypeListCreate<void,void,void,void,void,void,void,void,void>::Result Params10Void;
template<class ParamsOld, class ParamsBind, int indexBind = 0, class ParamsOut = Params10Void>
struct QBindFindParams;

template<class ParamsOld, class Head, int indexBind, class ParamsOut>
struct QBindFindParams<ParamsOld, QTypeList<Head,QNull>, indexBind, ParamsOut>
{
    typedef typename QBindParamsUpdate<ParamsOld, Head, indexBind, ParamsOut>::Result ParamsTemp1;
    typedef typename QTypeListEraseAll<ParamsTemp1,void>::Result Result;
};

template<class ParamsOld, class Head, class Tail, int indexBind, class ParamsOut>
struct QBindFindParams<ParamsOld, QTypeList<Head,Tail>, indexBind, ParamsOut>
{
    typedef typename QBindParamsUpdate<ParamsOld, Head, indexBind, ParamsOut>::Result ParamsTemp1;
    typedef typename QBindFindParams<ParamsOld, Tail, indexBind + 1, ParamsTemp1>::Result Result;
};

template<int indexBind, class ParamsOut>
struct QBindFindParams<QNull,QNull,indexBind,ParamsOut>
{
    typedef QNull Result;
};


//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QBIND_PARAMS_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
