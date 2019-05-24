//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QSHARABLE_H__
#define __QSHARABLE_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "shared_ptr.hpp"


////////////////////////////////////////////////////////////////////////////



//class QSharableId{};


namespace boost
{

template<class T>
class enable_shared_from_this //: public QSharableId
{
public:
	const shared_ptr<T> shared_from_this()
	{
		return shared_ptr<T>(static_cast<T*>(this), weak_this_);
	}

	shared_ptr<const T> shared_from_this() const
	{
		return shared_ptr<const T>(static_cast<const T*>(this), weak_this_);
	}

protected:
	template<class U>
	friend class shared_ptr;
	mutable QWatchHolder weak_this_;
};



};//namespace boost



//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QSHARABLE_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
