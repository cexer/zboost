//premake.vpath=boost/detail

#if defined(QCXX_CALLCONV_AFFECT_SIGNATURE)
#   define __CALLING     __stdcall
#   define __CALLING_ID  QFUNCTION_STDCALL
#   include "QMethodTraitsTemplate2.h"
#
#   define __CALLING     __cdecl
#   define __CALLING_ID  QFUNCTION_CDECL
#   include "QMethodTraitsTemplate2.h"
#
//warning C4561: '__fastcall' incompatible with the '/clr' option: converting to '__stdcall'
//#   define __CALLING     __fastcall
//#   define __CALLING_ID  QFUNCTION_PASCAL
//#   include "QMethodTraitsTemplate2.h"
#
#   define __CALLING     __thiscall
#   define __CALLING_ID  QFUNCTION_THISCALL
#   include "QMethodTraitsTemplate2.h"
#
#else
#   define __CALLING
#   define __CALLING_ID  QFUNCTION_UNKNOWNCALL
#   include "QMethodTraitsTemplate2.h"
#endif//defined(QCXX_CALLCONV_AFFECT_SIGNATURE)


#undef __QUALIFICATION
#undef __IS_CONST_Q
#undef __IS_VOLATILE_Q