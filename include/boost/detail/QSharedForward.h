//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QSHARED_FORWARD_H__
#define __QSHARED_FORWARD_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QAtomic.h"
#include "QTraits.h"


////////////////////////////////////////////////////////////////////////////



template<class T>
class QShared;

template<class T>
class QShareable;
class QSharableId;


template<class T>
class QWatch;


class QSharedHolder;
class QWatchHolder;



template <class T>
struct IsSharable : public QTraits<T>::template convertableTo<QSharableId>
{

};


//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QSHARED_FORWARD_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

