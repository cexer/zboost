//premake.vpath=boost/detail
//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#ifndef __QMACROS_H__
#define __QMACROS_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}


#include "QKernelConfig.h"

////////////////////////////////////////////////////////////////////////////


#define QEMPTY


#define QEXPAND(x)       QEXPAND_I(x)
#define QEXPAND_I(x)     #x


#define QJOIN(a, b)       QJOIN_I(a, b)
#define QJOIN_I(a, b)     QJOIN_II(a, b)
#define QJOIN_II(a, b)    a##b

#define QJOIN3(a, b, c)       QJOIN3_I(a, b, c)
#define QJOIN3_I(a, b, c)     QJOIN3_II(a, b, c)
#define QJOIN3_II(a, b, c)    a##b##c

#define QJOIN4(a, b, c, d)       QJOIN4_I(a, b, c, d)
#define QJOIN4_I(a, b, c, d)     QJOIN4_II(a, b, c, d)
#define QJOIN4_II(a, b, c, d)    a##b##c##d


#define QSTRINGLIZE(x)    QSTRINGLIZE_I(x)
#define QSTRINGLIZE_I(x)  QSTRINGLIZE_II(x)
#define QSTRINGLIZE_II(x) #x



//NO_DOC{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
#endif//__QMACROS_H__
//NO_DOC}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}