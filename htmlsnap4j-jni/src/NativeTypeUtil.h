/**
 * NativeTypeUtil.h
 *
 * created on 2013.10.11
 * author : XUNY
 */

#include <jni.h>

#include <atlbase.h>

#ifndef _Included_NativeStringUtil
#define _Included_NativeStringUtil
#ifdef __cplusplus
extern "C" {
#endif

#define jtype_void    0
#define jtype_boolean 1
#define jtype_byte    2
#define jtype_char    3
#define jtype_short   4
#define jtype_int     5
#define jtype_long    6
#define jtype_float   7
#define jtype_double  8
#define jtype_Object  100
#define jtype_String  101

char* getJtypeSig(ULONG jtype, char* buffer);


char*
jbyteArray2cstr
(JNIEnv *env, jbyteArray jbytes);

jbyteArray
cstr2jbyteArray
(JNIEnv *env, /*const*/ char *cstr);

jbyteArray
javaGetBytes
(JNIEnv *env, jstring jstr);

jbyteArray
javaGetBytesEncoding
(JNIEnv *env, jstring jstr, const char *encoding);

jstring
javaNewString
(JNIEnv *env, jbyteArray jbytes);

jstring
javaNewStringEncoding
(JNIEnv *env, jbyteArray jbytes, const char *encoding);

#ifdef __cplusplus
}
#endif

char* jstr2cstr(JNIEnv *env, jstring jstr);
jstring cstr2jstr(JNIEnv *env, char *cstr);
CComBSTR jstr2bstr(JNIEnv *env, jstring jstr);
jstring bstr2jstr(JNIEnv *env, BSTR *bstr);
jbyteArray vari2jbar(JNIEnv *env, VARIANT *vari);
jobjectArray vari2jsar(JNIEnv *env, VARIANT *vari);

#endif
