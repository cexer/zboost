//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __IABSTRACT_H__
#define __IABSTRACT_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QSharedForward.h"


//////////////////////////////////////////////////////////////////////////



class IAbstract
{
public:
    virtual ~IAbstract() = 0;
};

inline IAbstract::~IAbstract()
{}


#define dynamicCast dynamic_cast

typedef QShared<IAbstract>  IAbstractPtr;
typedef QWatch<IAbstract> IAbstractWeakPtr;




//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__IABSTRACT_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
