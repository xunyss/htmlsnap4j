/*
 * org_xunyss_htmlsnap4j_HtmlsnapJni.cpp
 *
 * created on 2013.09.30
 * author : XUNY
 */

#include <windows.h>
#include <assert.h>
#include <process.h>

#pragma comment(lib,"atl.lib")
#include <atlbase.h>
#include <exdisp.h>

#include "NativeTypeUtil.h"
#include "HtmlSnapshot.h"
#include "org_xunyss_htmlsnap4j_HtmlsnapJni.h"


/**
 *
 */
static IHtmlSnap *_pHtmlsnap;


////////////////////////////////////////////////////////////////////////////////

static jclass class_HtmlsnapOptions;

BOOL IsOptionSet(JNIEnv *pEnv, jobject options, LPSTR fieldName)
{
	if (class_HtmlsnapOptions == NULL)
	{
		class_HtmlsnapOptions = pEnv->GetObjectClass(options);
	}
	jfieldID bfield = pEnv->GetFieldID(class_HtmlsnapOptions, fieldName, "Z");
	return pEnv->GetBooleanField(options, bfield);
}

jvalue GetOptionValue(JNIEnv *pEnv, jobject options, LPSTR fieldName, ULONG jtype, BOOL force = false)
{
	if (class_HtmlsnapOptions == NULL)
	{
		class_HtmlsnapOptions = pEnv->GetObjectClass(options);
	}

	char sig[64];
	jfieldID optField = pEnv->GetFieldID(class_HtmlsnapOptions, fieldName, getJtypeSig(jtype, sig));
	jvalue value;

	if (jtype >= jtype_Object)
	{
		value.l = pEnv->GetObjectField(options, optField);
	}
	else
	{
//		switch (jtype)
//		{
//		case jtype_int:
//			value.i = pEnv->GetIntField(options, optField);
//			break;
//		case jtype_double:
//			value.d = pEnv->GetDoubleField(options, optField);
//			break;
//		default:
//			return NULL;
//		}
		value.d = pEnv->GetDoubleField(options, optField);
	}
	return value;
}

////////////////////////////////////////////////////////////////////////////////


/**
 *
 */
JNIEXPORT jboolean JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_CreateInstance
(JNIEnv *pEnv, jobject thiz)
{
	CoInitialize(NULL);
	IHtmlSnap *pSnap = NULL;
	HRESULT hr = CoCreateInstance(CLSID_CHtmlSnap, 0, CLSCTX_INPROC_SERVER, IID_IHtmlSnap, (LPVOID*) &pSnap);

	if (SUCCEEDED(hr) && (pSnap != NULL))
	{
		_pHtmlsnap = pSnap;
		return TRUE;
	}
	else
	{
		_pHtmlsnap = NULL;
		return FALSE;
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_ReleaseInstance
(JNIEnv *pEnv, jobject thiz)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->Release();
	}
	CoUninitialize();
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_Snap
(JNIEnv *pEnv, jobject thiz, jint target, jstring source, jstring picFile, jobject options)
{
	if (_pHtmlsnap != NULL)
	{
		if (options == NULL)
		{
			return;
		}

		if (IsOptionSet(pEnv, options, "_code"))
		{
			jvalue opt_code = GetOptionValue(pEnv, options, "code", jtype_String);
			_pHtmlsnap->SetCode(jstr2bstr(pEnv, (jstring) opt_code.l));
		}
		if (IsOptionSet(pEnv, options, "_timeOut"))
		{
			jvalue opt_timeOut = GetOptionValue(pEnv, options, "timeOut", jtype_int);
			_pHtmlsnap->SetTimeOut(opt_timeOut.i);
		}
		if (IsOptionSet(pEnv, options, "_delayTime"))
		{
			jvalue opt_delayTime = GetOptionValue(pEnv, options, "delayTime", jtype_int);
			_pHtmlsnap->SetDelayTime(opt_delayTime.i);
		}
		if (IsOptionSet(pEnv, options, "_dimension"))
		{
			jvalue opt_dimension_cx = GetOptionValue(pEnv, options, "dimension_cx", jtype_int);
			jvalue opt_dimension_cy = GetOptionValue(pEnv, options, "dimension_cy", jtype_int);
			_pHtmlsnap->SetSnapDimension(opt_dimension_cx.i, opt_dimension_cy.i);
		}
		if (IsOptionSet(pEnv, options, "_zoom"))
		{
			jvalue opt_zooz_ratio = GetOptionValue(pEnv, options, "zoom_ratio", jtype_double);
			_pHtmlsnap->SetZoom(opt_zooz_ratio.d);
		}
		if (IsOptionSet(pEnv, options, "_postdata"))
		{
			jvalue opt_postdata = GetOptionValue(pEnv, options, "postdata", jtype_String);
			_pHtmlsnap->SetPostData(jstr2bstr(pEnv, (jstring) opt_postdata.l));
		}
		if (IsOptionSet(pEnv, options, "_cookie"))
		{
			jvalue opt_cookie_url = GetOptionValue(pEnv, options, "cookie_url", jtype_String);
			jvalue opt_cookie_name = GetOptionValue(pEnv, options, "cookie_name", jtype_String);
			jvalue opt_cookie_data = GetOptionValue(pEnv, options, "cookie_data", jtype_String);
			_pHtmlsnap->SetCookie(jstr2bstr(pEnv, (jstring) opt_cookie_url.l),
								  jstr2bstr(pEnv, (jstring) opt_cookie_name.l),
								  jstr2bstr(pEnv, (jstring) opt_cookie_data.l));
		}
		if (IsOptionSet(pEnv, options, "_auth"))
		{
			jvalue opt_auth_username = GetOptionValue(pEnv, options, "auth_username", jtype_String);
			jvalue opt_auth_password = GetOptionValue(pEnv, options, "auth_password", jtype_String);
			_pHtmlsnap->SetAuthUserAndPasswd(jstr2bstr(pEnv, (jstring) opt_auth_username.l),
											 jstr2bstr(pEnv, (jstring) opt_auth_password.l));
		}

		CComBSTR bstrSource = jstr2bstr(pEnv, source);
		CComBSTR bstrPicFile = jstr2bstr(pEnv, picFile);
		switch (target)
		{
			case 0:
				_pHtmlsnap->SnapUrl(bstrSource, bstrPicFile);
				break;
			case 1:
				_pHtmlsnap->SnapHtmlString(bstrSource, bstrPicFile);
				break;
		}
	}
}


/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SnapUrl
(JNIEnv *pEnv, jobject thiz, jstring url, jstring picFile)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrUrl = jstr2bstr(pEnv, url);
		CComBSTR bstrPicFile = jstr2bstr(pEnv, picFile);
		_pHtmlsnap->SnapUrl(bstrUrl, bstrPicFile);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SnapHtmlString
(JNIEnv *pEnv, jobject thiz, jstring html, jstring picFile)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrHtml = jstr2bstr(pEnv, html);
		CComBSTR bstrPicFile = jstr2bstr(pEnv, picFile);
		_pHtmlsnap->SnapHtmlString(bstrHtml, bstrPicFile);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_ReSnap
(JNIEnv *pEnv, jobject thiz)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->ReSnap();
	}
}


/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_EnableActiveX
(JNIEnv *pEnv, jobject thiz, jboolean enable)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->EnableActiveX(enable);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_EnableJava
(JNIEnv *pEnv, jobject thiz, jboolean enable)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->EnableJava(enable);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_EnableScript
(JNIEnv *pEnv, jobject thiz, jboolean enable)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->EnableScript(enable);
	}
}


/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetRenderEngine
(JNIEnv *pEnv, jobject thiz, jint engine)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->SetRenderEngine(engine);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetCode
(JNIEnv *pEnv, jobject thiz, jstring code)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrCode = jstr2bstr(pEnv, code);
		_pHtmlsnap->SetCode(bstrCode);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetTimeOut
(JNIEnv *pEnv, jobject thiz, jint timeOut)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->SetTimeOut(timeOut);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetDelayTime
(JNIEnv *pEnv, jobject thiz, jint delayTime)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->SetDelayTime(delayTime);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetForceSnap
(JNIEnv *pEnv, jobject thiz, jint forceSnap)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->SetForceSnap(forceSnap);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetSnapDimension
(JNIEnv *pEnv, jobject thiz, jint cx, jint cy)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->SetSnapDimension(cx, cy);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetClipRect
(JNIEnv *pEnv, jobject thiz, jint x, jint y, jint width, jint height)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->SetClipRect(x, y, width, height);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetZoom
(JNIEnv *pEnv, jobject thiz, jdouble ratio)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->SetZoom(ratio);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetDPI
(JNIEnv *pEnv, jobject thiz, jint xDPI, jint yDPI)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->SetDPI(xDPI, yDPI);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetJPEGQuality
(JNIEnv *pEnv, jobject thiz, jint quality)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->SetJPEGQuality(quality);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetDither
(JNIEnv *pEnv, jobject thiz, jint dither)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->SetDither((HTMLSNAPDITHER) dither);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetTIFFEncoder
(JNIEnv *pEnv, jobject thiz, jint compression)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->SetTIFFEncoder((HTMLSNAPTIFFCOMPRESSION) compression);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetSmoothingMode
(JNIEnv *pEnv, jobject thiz, jint smoothing)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->SetSmoothingMode(smoothing);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetInterpolationMode
(JNIEnv *pEnv, jobject thiz, jint interpolation)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->SetInterpolationMode(interpolation);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetProxy
(JNIEnv *pEnv, jobject thiz, jstring host, jstring username, jstring password, jint autoConfig)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrHost = jstr2bstr(pEnv, host);
		CComBSTR bstrUsername = jstr2bstr(pEnv, username);
		CComBSTR bstrPassword = jstr2bstr(pEnv, password);
		_pHtmlsnap->SetProxy(bstrHost, bstrUsername, bstrPassword, autoConfig);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetAsync
(JNIEnv *pEnv, jobject thiz, jboolean async)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->SetAsync(async);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetLogonUser
(JNIEnv *pEnv, jobject thiz, jstring username, jstring domain, jstring password)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrUsername = jstr2bstr(pEnv, username);
		CComBSTR bstrDomain = jstr2bstr(pEnv, domain);
		CComBSTR bstrPassword = jstr2bstr(pEnv, password);
		_pHtmlsnap->SetLogonUser(bstrUsername, bstrDomain, bstrPassword);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetAuthUserAndPasswd
(JNIEnv *pEnv, jobject thiz, jstring username, jstring password)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrUsername = jstr2bstr(pEnv, username);
		CComBSTR bstrPassword = jstr2bstr(pEnv, password);
		_pHtmlsnap->SetAuthUserAndPasswd(bstrUsername, bstrPassword);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetPostData
(JNIEnv *pEnv, jobject thiz, jstring data)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrData = jstr2bstr(pEnv, data);
		_pHtmlsnap->SetPostData(bstrData);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetCookie
(JNIEnv *pEnv, jobject thiz, jstring url, jstring name, jstring data)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrUrl = jstr2bstr(pEnv, url);
		CComBSTR bstrName = jstr2bstr(pEnv, name);
		CComBSTR bstrData = jstr2bstr(pEnv, data);
		_pHtmlsnap->SetCookie(bstrUrl, bstrName, bstrData);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_SetThreshold
(JNIEnv *pEnv, jobject thiz, jint threshold)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->SetThreshold(threshold);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_DrawText
(JNIEnv *pEnv, jobject thiz, jint x, jint y, jstring text, jint size, jint color, jstring fontName)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrText = jstr2bstr(pEnv, text);
		CComBSTR bstrFontName = jstr2bstr(pEnv, fontName);
		_pHtmlsnap->DrawTxt(x, y, bstrText, size, color, bstrFontName);
	}
}


/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_saveImage
(JNIEnv *pEnv, jobject thiz, jstring picFile)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrPicFile = jstr2bstr(pEnv, picFile);
		_pHtmlsnap->SaveImage(bstrPicFile);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_saveMultipageTiff
(JNIEnv *pEnv, jobject thiz, jstring picFile, jint height)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrPicFile = jstr2bstr(pEnv, picFile);
		_pHtmlsnap->SaveMultipageTiff(bstrPicFile, height);
	}
}


/**
 *
 */
JNIEXPORT jobjectArray JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_GetLinks
(JNIEnv *pEnv, jobject thiz)
{
	if (_pHtmlsnap != NULL)
	{
		CComVariant variLinks;
		_pHtmlsnap->GetLinks(&variLinks);
		return vari2jsar(pEnv, &variLinks);
	}

	return NULL;
}

/**
 *
 */
JNIEXPORT jobjectArray JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_GetFrames
(JNIEnv *pEnv, jobject thiz)
{
	if (_pHtmlsnap != NULL)
	{
		CComVariant variFrames;
		_pHtmlsnap->GetFrames(&variFrames);
		return vari2jsar(pEnv, &variFrames);
	}

	return NULL;
}

/**
 *
 */
JNIEXPORT jstring JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_GetTitle
(JNIEnv *pEnv, jobject thiz)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrTitle;
		_pHtmlsnap->GetTitle(&bstrTitle);
		return bstr2jstr(pEnv, &bstrTitle);
	}

	return NULL;
}


/**
 *
 */
JNIEXPORT jstring JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_GetSource
(JNIEnv *pEnv, jobject thiz)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrSource;
		_pHtmlsnap->GetSource(&bstrSource);
		return bstr2jstr(pEnv, &bstrSource);
	}

	return NULL;
}

/**
 *
 */
JNIEXPORT jstring JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_GetText
(JNIEnv *pEnv, jobject thiz)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrText;
		_pHtmlsnap->GetText(&bstrText);
		return bstr2jstr(pEnv, &bstrText);
	}

	return NULL;
}

/**
 *
 */
JNIEXPORT jint JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_GetImageWidth
(JNIEnv *pEnv, jobject thiz)
{
	if (_pHtmlsnap != NULL)
	{
		jint width;
		_pHtmlsnap->GetImageWidth(&width);
		return width;
	}

	return -1;
}

/**
 *
 */
JNIEXPORT jint JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_GetImageHeight
(JNIEnv *pEnv, jobject thiz)
{
	if (_pHtmlsnap != NULL)
	{
		jint height;
		_pHtmlsnap->GetImageHeight(&height);
		return height;
	}

	return -1;
}

/**
 *
 */
JNIEXPORT jstring JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_GetCookie
(JNIEnv *pEnv, jobject thiz)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrCookie;
		_pHtmlsnap->GetCookie(&bstrCookie);
		return bstr2jstr(pEnv, &bstrCookie);
	}

	return NULL;
}

/**
 *
 */
JNIEXPORT jstring JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_GetCookie2
(JNIEnv *pEnv, jobject thiz, jstring url)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrUrl = jstr2bstr(pEnv, url);
		CComBSTR bstrCookie;
		_pHtmlsnap->GetCookie2(bstrUrl, &bstrCookie);
		return bstr2jstr(pEnv, &bstrCookie);
	}

	return NULL;
}


/*
 *
 */
JNIEXPORT jobject JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_GetBufferedImage
(JNIEnv *pEnv, jobject thiz)
{
	return NULL;
}

/**
 *
 */
JNIEXPORT jobject JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_GetThumbBufferedImage
(JNIEnv *pEnv, jobject thiz, jint cx, jint cy, jint remainRatio)
{
	return NULL;
}

/*
 *
 */
JNIEXPORT jbyteArray JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_GetImageBytes
(JNIEnv *pEnv, jobject thiz, jstring imageType)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrImageType = jstr2bstr(pEnv, imageType);
		CComVariant variImageBytes;
		_pHtmlsnap->GetImageBytes(bstrImageType, &variImageBytes);
		return vari2jbar(pEnv, &variImageBytes);
	}

	return NULL;
}

/*
 *
 */
JNIEXPORT jbyteArray JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_GetThumbImageBytes
(JNIEnv *pEnv, jobject thiz, jstring imageType, jint cx, jint cy, jint remainRatio)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrImageType = jstr2bstr(pEnv, imageType);
		CComVariant variThumbImageBytes;
		_pHtmlsnap->GetThumbImageBytes(bstrImageType, cx, cy, remainRatio, &variThumbImageBytes);
		return vari2jbar(pEnv, &variThumbImageBytes);
	}

	return NULL;
}


/**
 *
 */
JNIEXPORT jint JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_GetErrorCode
(JNIEnv *pEnv, jobject thiz)
{
	if (_pHtmlsnap != NULL)
	{
		jint errorCode;
		_pHtmlsnap->GetErrorCode(&errorCode);
		return errorCode;
	}

	return -1;
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_Clear
(JNIEnv *pEnv, jobject thiz)
{
	if (_pHtmlsnap != NULL)
	{
		_pHtmlsnap->Clear();
	}
}


/**
 *
 */
JNIEXPORT jint JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_IsGoodUrlForSnap
(JNIEnv *pEnv, jobject thiz, jstring url)
{
	if (_pHtmlsnap != NULL)
	{
		jint value;
		CComBSTR bstrUrl = jstr2bstr(pEnv, url);
		_pHtmlsnap->IsGoodUrlForSnap(bstrUrl, &value);
		return value;
	}

	return -1;
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_MakeThumbnailImage
(JNIEnv *pEnv, jobject thiz, jstring inputFile, jstring outputFile, jint cx, jint cy, jint remainRatio)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrInputFile = jstr2bstr(pEnv, inputFile);
		CComBSTR bstrOutputFile = jstr2bstr(pEnv, outputFile);
		_pHtmlsnap->GetThumbnailImage(bstrInputFile, bstrOutputFile, cx, cy, remainRatio);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_MakeGrayImage
(JNIEnv *pEnv, jobject thiz, jstring inputFile, jstring outputFile, jint grayOrBW)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrInputFile = jstr2bstr(pEnv, inputFile);
		CComBSTR bstrOutputFile = jstr2bstr(pEnv, outputFile);
		_pHtmlsnap->MakeGrayImage(bstrInputFile, bstrOutputFile, grayOrBW);
	}
}

/**
 *
 */
JNIEXPORT void JNICALL
Java_org_xunyss_htmlsnap4j_HtmlsnapJni_ReduceColor
(JNIEnv *pEnv, jobject thiz, jstring inputFile, jstring outputFile, jint colors)
{
	if (_pHtmlsnap != NULL)
	{
		CComBSTR bstrInputFile = jstr2bstr(pEnv, inputFile);
		CComBSTR bstrOutputFile = jstr2bstr(pEnv, outputFile);
		_pHtmlsnap->ReduceColor(bstrInputFile, bstrOutputFile, colors);
	}
}

