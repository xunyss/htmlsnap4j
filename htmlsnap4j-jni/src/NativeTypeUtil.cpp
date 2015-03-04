/**
 * NativeTypeUtil.cpp
 *
 * created on 2013.10.11
 * author : XUNY
 */

#include <stdlib.h>
#include <string.h>

#include "NativeTypeUtil.h"


/**
 *
 */
char* getJtypeSig(ULONG jtype, char* buffer)
{
	switch (jtype)
	{
		case jtype_void:	strcpy(buffer, "V");	break;
		case jtype_boolean:	strcpy(buffer, "Z");	break;
		case jtype_byte:	strcpy(buffer, "B");	break;
		case jtype_char:	strcpy(buffer, "C");	break;
		case jtype_short:	strcpy(buffer, "S");	break;
		case jtype_int:		strcpy(buffer, "I");	break;
		case jtype_long:	strcpy(buffer, "J");	break;
		case jtype_float:	strcpy(buffer, "F");	break;
		case jtype_double:	strcpy(buffer, "D");	break;
		case jtype_Object:	strcpy(buffer, "Ljava/lang/Object;");	break;
		case jtype_String:	strcpy(buffer, "Ljava/lang/String;");	break;
	}
	return buffer;
}


/**
 * when define "static" variable
 *   "jclass", subclasses of "jobject"
 *     : need to [NewGlobalRef]
 *   "jfieldID", "jmethodID"
 *     : need NOT to [NewGlobalRef]
 */
static jclass class_String;
static jmethodID mid_getBytes, mid_getBytesEncoding;
static jmethodID mid_newString, mid_newStringEncoding;

/**
 *
 */
BOOL init_class_String(JNIEnv *env)
{
	if (class_String != NULL)
	{
		return TRUE;
	}
	jclass cls = env->FindClass("java/lang/String");
	class_String = cls != NULL ? (jclass) env->NewGlobalRef(cls) : NULL;
	return class_String != NULL;
}


/**
 *
 */
char* jbyteArray2cstr(JNIEnv *env, jbyteArray jbytes)
{
	size_t len = env->GetArrayLength(jbytes);
	jbyte *jstr = env->GetByteArrayElements(jbytes, NULL);
	char *cstr = (char*) malloc(len + 1);

	strncpy(cstr, (char*) jstr, len);
	cstr[len] = NULL;

	env->ReleaseByteArrayElements(jbytes, jstr, JNI_ABORT);
	return cstr; /* ML(Memory Loss) 발생 */
}

/**
 *
 */
jbyteArray cstr2jbyteArray(JNIEnv *env, /*const*/ char *cstr)
{
	size_t len = strlen(cstr);
	jbyteArray jbytes = env->NewByteArray(len);

	env->SetByteArrayRegion(jbytes, 0, len, (jbyte*) cstr);
	return jbytes;
}

/**
 * jstr.getBytes();
 */
jbyteArray javaGetBytes(JNIEnv *env, jstring jstr)
{
	if (mid_getBytes == NULL)
	{
		if (!init_class_String(env))
		{
			return NULL;
		}
		mid_getBytes = env->GetMethodID(class_String, "getBytes", "()[B");
		if (mid_getBytes == NULL) return NULL;
	}

	return (jbyteArray) env->CallObjectMethod(jstr, mid_getBytes);
}

/**
 * jstr.getBytes(encoding);
 */
jbyteArray javaGetBytesEncoding(JNIEnv *env, jstring jstr, const char *encoding)
{
	if (mid_getBytesEncoding == NULL)
	{
		if (!init_class_String(env))
		{
			return NULL;
		}
		mid_getBytesEncoding = env->GetMethodID(class_String, "getBytes", "(Ljava/lang/String;)[B");
		if (mid_getBytesEncoding == NULL) return NULL;
	}

	return (jbyteArray) env->CallObjectMethod(jstr, mid_getBytesEncoding, env->NewStringUTF(encoding));
}

/**
 * new String(jbytes);
 */
jstring javaNewString(JNIEnv *env, jbyteArray jbytes)
{
	if (mid_newString == NULL)
	{
		if (!init_class_String(env))
		{
			return NULL;
		}
		mid_newString = env->GetMethodID(class_String, "<init>", "([B)V");
		if (mid_newString == NULL) return NULL;
	}

	return (jstring) env->NewObject(class_String, mid_newString, jbytes);
}

/**
 * new String(jbytes, encoding);
 */
jstring javaNewStringEncoding(JNIEnv *env, jbyteArray jbytes, const char *encoding)
{
	if (mid_newStringEncoding == NULL)
	{
		if (!init_class_String(env))
		{
			return NULL;
		}
		mid_newStringEncoding = env->GetMethodID(class_String, "<init>", "([BLjava/lang/String;)V");
		if (mid_newStringEncoding == NULL) return NULL;
	}

	return (jstring) env->NewObject(class_String, mid_newStringEncoding, jbytes, env->NewStringUTF(encoding));
}


/**
 *
 */
char* jstr2cstr(JNIEnv *env, jstring jstr)
{
	return jbyteArray2cstr(env, javaGetBytes(env, jstr)); /* ML(Memory Loss) 발생 */
}

/**
 *
 */
jstring cstr2jstr(JNIEnv *env, char *cstr)
{
	return javaNewString(env, cstr2jbyteArray(env, cstr));
}

/**
 *
 */
CComBSTR jstr2bstr(JNIEnv *env, jstring jstr)
{
	char *cstr = jstr2cstr(env, jstr);
	CComBSTR bstr(cstr);
	free(cstr);
	return bstr;
}

/**
 *
 */
jstring bstr2jstr(JNIEnv *env, BSTR *bstr)
{
	return cstr2jstr(env, CW2A(*bstr));
}

/**
 *
 */
jbyteArray vari2jbar(JNIEnv *env, VARIANT *vari)
{
	if (vari->vt != (VT_ARRAY | VT_UI1) || vari->parray == NULL) return NULL;

	SAFEARRAY *array = vari->parray;
	ULONG lcount = array->rgsabound->cElements;
	LONG lstart = array->rgsabound->lLbound;

	jbyteArray jbar = env->NewByteArray(lcount);
	env->SetByteArrayRegion(jbar, 0, lcount, (jbyte*) array->pvData);

	return jbar;
}

/**
 *
 */
jobjectArray vari2jsar(JNIEnv *env, VARIANT *vari)
{
	if (vari->vt != (VT_ARRAY | VT_VARIANT) || vari->parray == NULL) return NULL;

	if (!init_class_String(env))
	{
		return NULL;
	}

	SAFEARRAY *array = vari->parray;
	ULONG lcount = array->rgsabound->cElements;
	LONG lstart = array->rgsabound->lLbound;

	jobjectArray jsar = env->NewObjectArray(lcount, class_String, NULL);
	CComVariant item;
	HRESULT hr;

	for (LONG idx = lstart; idx < lstart + lcount; idx++)
	{
		hr = SafeArrayGetElement(array, &idx, &item);
		if (FAILED(hr)) break;

		if (item.vt != VT_BSTR) item.ChangeType(VT_BSTR);
		env->SetObjectArrayElement(jsar, (idx - lstart), bstr2jstr(env, (BSTR*) &item.bstrVal));
	}

	return jsar;
}
