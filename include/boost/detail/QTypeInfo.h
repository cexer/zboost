//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QTYPE_INFO_H__
#define __QTYPE_INFO_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QBooleanable.h"
#include <typeinfo>


////////////////////////////////////////////////////////////////////////////



class QTypeInfo : public QValidCheckable<QTypeInfo>
{
public:
    QTypeInfo() 
        : m_info(NULL) 
    {
    }

    QTypeInfo(const std::type_info& info)
        : m_info(&info) 
    {
    }

    QTypeInfo(const std::type_info* info)
        : m_info(info) 
    {
    }

    QTypeInfo(const QTypeInfo& that) 
        : m_info(that.m_info) 
    {
    }

    QTypeInfo& operator= (const QTypeInfo& that) 
    {
        m_info = that.m_info;
        return *this;
    }

    bool operator == (const QTypeInfo& that) const 
    {
        return !operator<(that) && !that.operator<(*this);
    }

    bool operator != (const QTypeInfo& that) const 
    {
        return !operator==(that);
    }

    bool operator < (const QTypeInfo& that) const 
    {
        if (!m_info && !that.m_info)
            return false;

        if (m_info && that.m_info)
            return !!m_info->before(*that.m_info);

        return m_info ? true : false;
    }

    bool valid() const 
    {
        return NULL != m_info;
    }

    void clear()
    {
        m_info = NULL;
    }

    const std::type_info* standardInfo() const 
    {
        return m_info;
    }

protected:
    const std::type_info* m_info;
};






//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QTYPE_INFO_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
