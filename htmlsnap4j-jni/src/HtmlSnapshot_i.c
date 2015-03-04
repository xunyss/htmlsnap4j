/**
 * HtmlSnapshot_i.c
 *
 * created on 2013.10.11
 * author : XUNY
 */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_


MIDL_DEFINE_GUID(IID, IID_IHtmlSnap,0x7EFF9499,0x6361,0x4B45,0x8B,0xAC,0x41,0xBB,0xAB,0xF5,0xCA,0x54);

MIDL_DEFINE_GUID(IID, LIBID_HtmlSnap2,0x144732A7,0xD135,0x46DB,0xB2,0x71,0x72,0xEF,0xC7,0x44,0x18,0xFE);

MIDL_DEFINE_GUID(IID, DIID__IHtmlSnapEvents,0x91B46E87,0x4CBE,0x4C1D,0xBE,0xAC,0x51,0x34,0x2B,0xE2,0xB2,0xE1);

MIDL_DEFINE_GUID(CLSID, CLSID_CHtmlSnap,0xADF55FB4,0xE4A0,0x47C8,0xA7,0xB4,0x89,0xC7,0x32,0x8A,0x9A,0xB5);


#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



