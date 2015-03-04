/**
 * HtmlSnapshot.h
 *
 * created on 2013.10.11
 * author : XUNY
 */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __HtmlSnapshot_h__
#define __HtmlSnapshot_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IHtmlSnap_FWD_DEFINED__
#define __IHtmlSnap_FWD_DEFINED__
typedef interface IHtmlSnap IHtmlSnap;
#endif 	/* __IHtmlSnap_FWD_DEFINED__ */


#ifndef ___IHtmlSnapEvents_FWD_DEFINED__
#define ___IHtmlSnapEvents_FWD_DEFINED__
typedef interface _IHtmlSnapEvents _IHtmlSnapEvents;
#endif 	/* ___IHtmlSnapEvents_FWD_DEFINED__ */


#ifndef __CHtmlSnap_FWD_DEFINED__
#define __CHtmlSnap_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHtmlSnap CHtmlSnap;
#else
typedef struct CHtmlSnap CHtmlSnap;
#endif /* __cplusplus */

#endif 	/* __CHtmlSnap_FWD_DEFINED__ */


/* header files for imported files */
#include "prsht.h"
#include "mshtml.h"
#include "mshtmhst.h"
#include "exdisp.h"
#include "objsafe.h"
/*
#include "cdoex.h"
*/

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IHtmlSnap_INTERFACE_DEFINED__
#define __IHtmlSnap_INTERFACE_DEFINED__

/* interface IHtmlSnap */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IHtmlSnap;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7EFF9499-6361-4B45-8BAC-41BBABF5CA54")
    IHtmlSnap : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SnapUrl( 
            /* [in] */ BSTR strUrl,
            /* [in] */ BSTR strPicFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetThumbnailImage( 
            /* [in] */ BSTR strInputFile,
            /* [in] */ BSTR strOutputFile,
            /* [in] */ LONG cx,
            /* [in] */ LONG cy,
            /* [in] */ LONG bRemainRatio) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCode( 
            /* [in] */ BSTR strCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAsync( 
            /* [in] */ BOOL bAsync) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetTimeOut( 
            /* [in] */ long nTimeOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDelayTime( 
            /* [in] */ long nDelayTime) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WaitUntilDone( 
            /* [in] */ long nTimeOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnableActiveX( 
            /* [in] */ BOOL bVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnableJava( 
            /* [in] */ BOOL bVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnableScript( 
            /* [in] */ BOOL bVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLinks( 
            /* [retval][out] */ VARIANT *strLinks) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTitle( 
            /* [retval][out] */ BSTR *strTitle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSource( 
            /* [retval][out] */ BSTR *strTitle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPageRank( 
            /* [in] */ BSTR strUrl,
            /* [retval][out] */ long *nPageRank) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSnapDimension( 
            /* [in] */ long cx,
            /* [in] */ long cy) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetJPEGQuality( 
            /* [in] */ long nQuality) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SnapHtmlString( 
            /* [in] */ BSTR strHtml,
            /* [in] */ BSTR strPicFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFrames( 
            /* [retval][out] */ VARIANT *strLinks) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBitmapHandle( 
            /* [retval][out] */ LONG *Handle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetImageWidth( 
            /* [retval][out] */ LONG *nVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetImageHeight( 
            /* [retval][out] */ LONG *nVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetClipRect( 
            /* [in] */ long x,
            /* [in] */ long y,
            /* [in] */ long w,
            /* [in] */ long h) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveImage( 
            /* [in] */ BSTR strPicFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetText( 
            /* [retval][out] */ BSTR *strText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPostData( 
            /* [in] */ BSTR strData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCookie( 
            /* [retval][out] */ BSTR *strCookie) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCookie( 
            /* [in] */ BSTR strUrl,
            /* [in] */ BSTR strCookieName,
            /* [in] */ BSTR strCookieValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCookie2( 
            /* [in] */ BSTR strUrl,
            /* [retval][out] */ BSTR *strCookie) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetHtmlDocument( 
            /* [retval][out] */ IDispatch **pDocDisp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReSnap( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnableSnapDimensionAsImageSize( 
            /* [in] */ BOOL bVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MakeGrayImage( 
            /* [in] */ BSTR strInputFile,
            /* [in] */ BSTR strOutputFile,
            /* [in] */ LONG bGrayOrBW) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetErrorCode( 
            /* [retval][out] */ LONG *nErr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetTIFFEncoder( 
            /* [in] */ enum HTMLSNAPTIFFCOMPRESSION nCompression) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetThreshold( 
            /* [in] */ LONG nThreshold) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReduceColor( 
            /* [in] */ BSTR strInputFile,
            /* [in] */ BSTR strOutputFile,
            /* [in] */ LONG nMaxColor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetForceSnap( 
            /* [in] */ BOOL bForceSnap) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDither( 
            /* [in] */ enum HTMLSNAPDITHER nDither) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveWebPageToMHT( 
            /* [in] */ BSTR strUrl,
            /* [in] */ BSTR strMHT) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetZoom( 
            /* [in] */ DOUBLE fZoomRatio) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetImageBytes( 
            /* [in] */ BSTR strFormat,
            /* [retval][out] */ VARIANT *pBlob) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetThumbImageBytes( 
            /* [in] */ BSTR strFormat,
            /* [in] */ LONG cx,
            /* [in] */ LONG cy,
            /* [in] */ LONG bRemainRatio,
            /* [retval][out] */ VARIANT *pBlob) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFramesEx( 
            /* [retval][out] */ VARIANT *strLinks) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFrameHtmlDocument( 
            /* [in] */ LONG iFrame,
            /* [retval][out] */ IDispatch **pDocDisp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDPI( 
            /* [in] */ LONG x,
            /* [in] */ LONG y) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetLogonUser( 
            /* [in] */ BSTR strUser,
            /* [in] */ BSTR strDomain,
            /* [in] */ BSTR strPasswd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetGIFOption( 
            /* [in] */ LONG bTrans,
            /* [in] */ LONG nColor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetGIFOption2( 
            /* [in] */ LONG nColor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConvertEMFToImage( 
            /* [in] */ BSTR strMetaFile,
            /* [in] */ BSTR strImageFile,
            /* [in] */ LONG nWidth,
            /* [in] */ LONG nHeight,
            /* [in] */ LONG nKeepRatio) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SnapWebBrowser( 
            /* [in] */ IDispatch *pBrowser,
            /* [in] */ BSTR strFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SnapWebBrowserAsBitmap( 
            /* [in] */ IDispatch *pBrowser,
            /* [retval][out] */ LONG *Handle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSnapUrlWorkingMode( 
            /* [in] */ LONG nMode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AutoClipMargin( 
            /* [in] */ LONG nMinMargin) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClipX( 
            /* [retval][out] */ LONG *nVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClipY( 
            /* [retval][out] */ LONG *nVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClipWidth( 
            /* [retval][out] */ LONG *nVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClipHeight( 
            /* [retval][out] */ LONG *nVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawTxt( 
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ BSTR strText,
            /* [in] */ LONG nFontSize,
            /* [in] */ LONG nColor,
            /* [in] */ BSTR strFontName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAuthUserAndPasswd( 
            /* [in] */ BSTR strAuthUser,
            /* [in] */ BSTR strAuthPasswd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFillColor( 
            /* [in] */ LONG nColor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsGoodUrlForSnap( 
            /* [in] */ BSTR strUrl,
            /* [retval][out] */ LONG *nVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPlacableWMF( 
            /* [in] */ LONG nPlacable) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSmoothingMode( 
            /* [in] */ LONG nValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetInterpolationMode( 
            /* [in] */ LONG nValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveMultipageTiff( 
            /* [in] */ BSTR strPicFile,
            /* [in] */ LONG nHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetImageMap( 
            /* [retval][out] */ BSTR *strTitle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLinksExtra( 
            /* [retval][out] */ VARIANT *strLinkRects) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConvertEMFToMultipleTiff( 
            /* [in] */ BSTR strMetaFile,
            /* [in] */ BSTR strImageFile,
            /* [in] */ LONG nWidth,
            /* [in] */ LONG nHeight,
            /* [in] */ LONG nPageHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetRenderEngine( 
            /* [in] */ LONG nValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TiffCommand( 
            /* [in] */ BSTR strInput,
            /* [in] */ BSTR strOutput,
            /* [in] */ BSTR command) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetProxy( 
            /* [in] */ BSTR proxyUrl,
            /* [in] */ BSTR strUser,
            /* [in] */ BSTR strPasswd,
            /* [in] */ LONG autoConfig) = 0;
        
        virtual ~IHtmlSnap() {}
    };
    
#else 	/* C style interface */

    typedef struct IHtmlSnapVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHtmlSnap * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHtmlSnap * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHtmlSnap * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHtmlSnap * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHtmlSnap * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHtmlSnap * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHtmlSnap * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SnapUrl )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strUrl,
            /* [in] */ BSTR strPicFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetThumbnailImage )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strInputFile,
            /* [in] */ BSTR strOutputFile,
            /* [in] */ LONG cx,
            /* [in] */ LONG cy,
            /* [in] */ LONG bRemainRatio);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCode )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAsync )( 
            IHtmlSnap * This,
            /* [in] */ BOOL bAsync);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetTimeOut )( 
            IHtmlSnap * This,
            /* [in] */ long nTimeOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDelayTime )( 
            IHtmlSnap * This,
            /* [in] */ long nDelayTime);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WaitUntilDone )( 
            IHtmlSnap * This,
            /* [in] */ long nTimeOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnableActiveX )( 
            IHtmlSnap * This,
            /* [in] */ BOOL bVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnableJava )( 
            IHtmlSnap * This,
            /* [in] */ BOOL bVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnableScript )( 
            IHtmlSnap * This,
            /* [in] */ BOOL bVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLinks )( 
            IHtmlSnap * This,
            /* [retval][out] */ VARIANT *strLinks);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTitle )( 
            IHtmlSnap * This,
            /* [retval][out] */ BSTR *strTitle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSource )( 
            IHtmlSnap * This,
            /* [retval][out] */ BSTR *strTitle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPageRank )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strUrl,
            /* [retval][out] */ long *nPageRank);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSnapDimension )( 
            IHtmlSnap * This,
            /* [in] */ long cx,
            /* [in] */ long cy);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetJPEGQuality )( 
            IHtmlSnap * This,
            /* [in] */ long nQuality);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SnapHtmlString )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strHtml,
            /* [in] */ BSTR strPicFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFrames )( 
            IHtmlSnap * This,
            /* [retval][out] */ VARIANT *strLinks);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBitmapHandle )( 
            IHtmlSnap * This,
            /* [retval][out] */ LONG *Handle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetImageWidth )( 
            IHtmlSnap * This,
            /* [retval][out] */ LONG *nVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetImageHeight )( 
            IHtmlSnap * This,
            /* [retval][out] */ LONG *nVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetClipRect )( 
            IHtmlSnap * This,
            /* [in] */ long x,
            /* [in] */ long y,
            /* [in] */ long w,
            /* [in] */ long h);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveImage )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strPicFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetText )( 
            IHtmlSnap * This,
            /* [retval][out] */ BSTR *strText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPostData )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCookie )( 
            IHtmlSnap * This,
            /* [retval][out] */ BSTR *strCookie);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCookie )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strUrl,
            /* [in] */ BSTR strCookieName,
            /* [in] */ BSTR strCookieValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCookie2 )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strUrl,
            /* [retval][out] */ BSTR *strCookie);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetHtmlDocument )( 
            IHtmlSnap * This,
            /* [retval][out] */ IDispatch **pDocDisp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReSnap )( 
            IHtmlSnap * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnableSnapDimensionAsImageSize )( 
            IHtmlSnap * This,
            /* [in] */ BOOL bVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MakeGrayImage )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strInputFile,
            /* [in] */ BSTR strOutputFile,
            /* [in] */ LONG bGrayOrBW);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IHtmlSnap * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetErrorCode )( 
            IHtmlSnap * This,
            /* [retval][out] */ LONG *nErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetTIFFEncoder )( 
            IHtmlSnap * This,
            /* [in] */ enum HTMLSNAPTIFFCOMPRESSION nCompression);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetThreshold )( 
            IHtmlSnap * This,
            /* [in] */ LONG nThreshold);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReduceColor )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strInputFile,
            /* [in] */ BSTR strOutputFile,
            /* [in] */ LONG nMaxColor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetForceSnap )( 
            IHtmlSnap * This,
            /* [in] */ BOOL bForceSnap);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDither )( 
            IHtmlSnap * This,
            /* [in] */ enum HTMLSNAPDITHER nDither);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveWebPageToMHT )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strUrl,
            /* [in] */ BSTR strMHT);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetZoom )( 
            IHtmlSnap * This,
            /* [in] */ DOUBLE fZoomRatio);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetImageBytes )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strFormat,
            /* [retval][out] */ VARIANT *pBlob);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetThumbImageBytes )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strFormat,
            /* [in] */ LONG cx,
            /* [in] */ LONG cy,
            /* [in] */ LONG bRemainRatio,
            /* [retval][out] */ VARIANT *pBlob);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFramesEx )( 
            IHtmlSnap * This,
            /* [retval][out] */ VARIANT *strLinks);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFrameHtmlDocument )( 
            IHtmlSnap * This,
            /* [in] */ LONG iFrame,
            /* [retval][out] */ IDispatch **pDocDisp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDPI )( 
            IHtmlSnap * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetLogonUser )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strUser,
            /* [in] */ BSTR strDomain,
            /* [in] */ BSTR strPasswd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetGIFOption )( 
            IHtmlSnap * This,
            /* [in] */ LONG bTrans,
            /* [in] */ LONG nColor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetGIFOption2 )( 
            IHtmlSnap * This,
            /* [in] */ LONG nColor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConvertEMFToImage )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strMetaFile,
            /* [in] */ BSTR strImageFile,
            /* [in] */ LONG nWidth,
            /* [in] */ LONG nHeight,
            /* [in] */ LONG nKeepRatio);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SnapWebBrowser )( 
            IHtmlSnap * This,
            /* [in] */ IDispatch *pBrowser,
            /* [in] */ BSTR strFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SnapWebBrowserAsBitmap )( 
            IHtmlSnap * This,
            /* [in] */ IDispatch *pBrowser,
            /* [retval][out] */ LONG *Handle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSnapUrlWorkingMode )( 
            IHtmlSnap * This,
            /* [in] */ LONG nMode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AutoClipMargin )( 
            IHtmlSnap * This,
            /* [in] */ LONG nMinMargin);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetClipX )( 
            IHtmlSnap * This,
            /* [retval][out] */ LONG *nVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetClipY )( 
            IHtmlSnap * This,
            /* [retval][out] */ LONG *nVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetClipWidth )( 
            IHtmlSnap * This,
            /* [retval][out] */ LONG *nVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetClipHeight )( 
            IHtmlSnap * This,
            /* [retval][out] */ LONG *nVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DrawTxt )( 
            IHtmlSnap * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ BSTR strText,
            /* [in] */ LONG nFontSize,
            /* [in] */ LONG nColor,
            /* [in] */ BSTR strFontName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAuthUserAndPasswd )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strAuthUser,
            /* [in] */ BSTR strAuthPasswd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetFillColor )( 
            IHtmlSnap * This,
            /* [in] */ LONG nColor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsGoodUrlForSnap )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strUrl,
            /* [retval][out] */ LONG *nVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPlacableWMF )( 
            IHtmlSnap * This,
            /* [in] */ LONG nPlacable);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSmoothingMode )( 
            IHtmlSnap * This,
            /* [in] */ LONG nValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetInterpolationMode )( 
            IHtmlSnap * This,
            /* [in] */ LONG nValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveMultipageTiff )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strPicFile,
            /* [in] */ LONG nHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetImageMap )( 
            IHtmlSnap * This,
            /* [retval][out] */ BSTR *strTitle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLinksExtra )( 
            IHtmlSnap * This,
            /* [retval][out] */ VARIANT *strLinkRects);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConvertEMFToMultipleTiff )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strMetaFile,
            /* [in] */ BSTR strImageFile,
            /* [in] */ LONG nWidth,
            /* [in] */ LONG nHeight,
            /* [in] */ LONG nPageHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetRenderEngine )( 
            IHtmlSnap * This,
            /* [in] */ LONG nValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TiffCommand )( 
            IHtmlSnap * This,
            /* [in] */ BSTR strInput,
            /* [in] */ BSTR strOutput,
            /* [in] */ BSTR command);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetProxy )( 
            IHtmlSnap * This,
            /* [in] */ BSTR proxyUrl,
            /* [in] */ BSTR strUser,
            /* [in] */ BSTR strPasswd,
            /* [in] */ LONG autoConfig);
        
        END_INTERFACE
    } IHtmlSnapVtbl;

    interface IHtmlSnap
    {
        CONST_VTBL struct IHtmlSnapVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHtmlSnap_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHtmlSnap_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHtmlSnap_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHtmlSnap_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IHtmlSnap_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IHtmlSnap_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IHtmlSnap_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IHtmlSnap_SnapUrl(This,strUrl,strPicFile)	\
    (This)->lpVtbl -> SnapUrl(This,strUrl,strPicFile)

#define IHtmlSnap_GetThumbnailImage(This,strInputFile,strOutputFile,cx,cy,bRemainRatio)	\
    (This)->lpVtbl -> GetThumbnailImage(This,strInputFile,strOutputFile,cx,cy,bRemainRatio)

#define IHtmlSnap_SetCode(This,strCode)	\
    (This)->lpVtbl -> SetCode(This,strCode)

#define IHtmlSnap_SetAsync(This,bAsync)	\
    (This)->lpVtbl -> SetAsync(This,bAsync)

#define IHtmlSnap_SetTimeOut(This,nTimeOut)	\
    (This)->lpVtbl -> SetTimeOut(This,nTimeOut)

#define IHtmlSnap_SetDelayTime(This,nDelayTime)	\
    (This)->lpVtbl -> SetDelayTime(This,nDelayTime)

#define IHtmlSnap_WaitUntilDone(This,nTimeOut)	\
    (This)->lpVtbl -> WaitUntilDone(This,nTimeOut)

#define IHtmlSnap_EnableActiveX(This,bVal)	\
    (This)->lpVtbl -> EnableActiveX(This,bVal)

#define IHtmlSnap_EnableJava(This,bVal)	\
    (This)->lpVtbl -> EnableJava(This,bVal)

#define IHtmlSnap_EnableScript(This,bVal)	\
    (This)->lpVtbl -> EnableScript(This,bVal)

#define IHtmlSnap_GetLinks(This,strLinks)	\
    (This)->lpVtbl -> GetLinks(This,strLinks)

#define IHtmlSnap_GetTitle(This,strTitle)	\
    (This)->lpVtbl -> GetTitle(This,strTitle)

#define IHtmlSnap_GetSource(This,strTitle)	\
    (This)->lpVtbl -> GetSource(This,strTitle)

#define IHtmlSnap_GetPageRank(This,strUrl,nPageRank)	\
    (This)->lpVtbl -> GetPageRank(This,strUrl,nPageRank)

#define IHtmlSnap_SetSnapDimension(This,cx,cy)	\
    (This)->lpVtbl -> SetSnapDimension(This,cx,cy)

#define IHtmlSnap_SetJPEGQuality(This,nQuality)	\
    (This)->lpVtbl -> SetJPEGQuality(This,nQuality)

#define IHtmlSnap_SnapHtmlString(This,strHtml,strPicFile)	\
    (This)->lpVtbl -> SnapHtmlString(This,strHtml,strPicFile)

#define IHtmlSnap_GetFrames(This,strLinks)	\
    (This)->lpVtbl -> GetFrames(This,strLinks)

#define IHtmlSnap_GetBitmapHandle(This,Handle)	\
    (This)->lpVtbl -> GetBitmapHandle(This,Handle)

#define IHtmlSnap_GetImageWidth(This,nVal)	\
    (This)->lpVtbl -> GetImageWidth(This,nVal)

#define IHtmlSnap_GetImageHeight(This,nVal)	\
    (This)->lpVtbl -> GetImageHeight(This,nVal)

#define IHtmlSnap_SetClipRect(This,x,y,w,h)	\
    (This)->lpVtbl -> SetClipRect(This,x,y,w,h)

#define IHtmlSnap_SaveImage(This,strPicFile)	\
    (This)->lpVtbl -> SaveImage(This,strPicFile)

#define IHtmlSnap_GetText(This,strText)	\
    (This)->lpVtbl -> GetText(This,strText)

#define IHtmlSnap_SetPostData(This,strData)	\
    (This)->lpVtbl -> SetPostData(This,strData)

#define IHtmlSnap_GetCookie(This,strCookie)	\
    (This)->lpVtbl -> GetCookie(This,strCookie)

#define IHtmlSnap_SetCookie(This,strUrl,strCookieName,strCookieValue)	\
    (This)->lpVtbl -> SetCookie(This,strUrl,strCookieName,strCookieValue)

#define IHtmlSnap_GetCookie2(This,strUrl,strCookie)	\
    (This)->lpVtbl -> GetCookie2(This,strUrl,strCookie)

#define IHtmlSnap_GetHtmlDocument(This,pDocDisp)	\
    (This)->lpVtbl -> GetHtmlDocument(This,pDocDisp)

#define IHtmlSnap_ReSnap(This)	\
    (This)->lpVtbl -> ReSnap(This)

#define IHtmlSnap_EnableSnapDimensionAsImageSize(This,bVal)	\
    (This)->lpVtbl -> EnableSnapDimensionAsImageSize(This,bVal)

#define IHtmlSnap_MakeGrayImage(This,strInputFile,strOutputFile,bGrayOrBW)	\
    (This)->lpVtbl -> MakeGrayImage(This,strInputFile,strOutputFile,bGrayOrBW)

#define IHtmlSnap_Clear(This)	\
    (This)->lpVtbl -> Clear(This)

#define IHtmlSnap_GetErrorCode(This,nErr)	\
    (This)->lpVtbl -> GetErrorCode(This,nErr)

#define IHtmlSnap_SetTIFFEncoder(This,nCompression)	\
    (This)->lpVtbl -> SetTIFFEncoder(This,nCompression)

#define IHtmlSnap_SetThreshold(This,nThreshold)	\
    (This)->lpVtbl -> SetThreshold(This,nThreshold)

#define IHtmlSnap_ReduceColor(This,strInputFile,strOutputFile,nMaxColor)	\
    (This)->lpVtbl -> ReduceColor(This,strInputFile,strOutputFile,nMaxColor)

#define IHtmlSnap_SetForceSnap(This,bForceSnap)	\
    (This)->lpVtbl -> SetForceSnap(This,bForceSnap)

#define IHtmlSnap_SetDither(This,nDither)	\
    (This)->lpVtbl -> SetDither(This,nDither)

#define IHtmlSnap_SaveWebPageToMHT(This,strUrl,strMHT)	\
    (This)->lpVtbl -> SaveWebPageToMHT(This,strUrl,strMHT)

#define IHtmlSnap_SetZoom(This,fZoomRatio)	\
    (This)->lpVtbl -> SetZoom(This,fZoomRatio)

#define IHtmlSnap_GetImageBytes(This,strFormat,pBlob)	\
    (This)->lpVtbl -> GetImageBytes(This,strFormat,pBlob)

#define IHtmlSnap_GetThumbImageBytes(This,strFormat,cx,cy,bRemainRatio,pBlob)	\
    (This)->lpVtbl -> GetThumbImageBytes(This,strFormat,cx,cy,bRemainRatio,pBlob)

#define IHtmlSnap_GetFramesEx(This,strLinks)	\
    (This)->lpVtbl -> GetFramesEx(This,strLinks)

#define IHtmlSnap_GetFrameHtmlDocument(This,iFrame,pDocDisp)	\
    (This)->lpVtbl -> GetFrameHtmlDocument(This,iFrame,pDocDisp)

#define IHtmlSnap_SetDPI(This,x,y)	\
    (This)->lpVtbl -> SetDPI(This,x,y)

#define IHtmlSnap_SetLogonUser(This,strUser,strDomain,strPasswd)	\
    (This)->lpVtbl -> SetLogonUser(This,strUser,strDomain,strPasswd)

#define IHtmlSnap_SetGIFOption(This,bTrans,nColor)	\
    (This)->lpVtbl -> SetGIFOption(This,bTrans,nColor)

#define IHtmlSnap_SetGIFOption2(This,nColor)	\
    (This)->lpVtbl -> SetGIFOption2(This,nColor)

#define IHtmlSnap_ConvertEMFToImage(This,strMetaFile,strImageFile,nWidth,nHeight,nKeepRatio)	\
    (This)->lpVtbl -> ConvertEMFToImage(This,strMetaFile,strImageFile,nWidth,nHeight,nKeepRatio)

#define IHtmlSnap_SnapWebBrowser(This,pBrowser,strFile)	\
    (This)->lpVtbl -> SnapWebBrowser(This,pBrowser,strFile)

#define IHtmlSnap_SnapWebBrowserAsBitmap(This,pBrowser,Handle)	\
    (This)->lpVtbl -> SnapWebBrowserAsBitmap(This,pBrowser,Handle)

#define IHtmlSnap_SetSnapUrlWorkingMode(This,nMode)	\
    (This)->lpVtbl -> SetSnapUrlWorkingMode(This,nMode)

#define IHtmlSnap_AutoClipMargin(This,nMinMargin)	\
    (This)->lpVtbl -> AutoClipMargin(This,nMinMargin)

#define IHtmlSnap_GetClipX(This,nVal)	\
    (This)->lpVtbl -> GetClipX(This,nVal)

#define IHtmlSnap_GetClipY(This,nVal)	\
    (This)->lpVtbl -> GetClipY(This,nVal)

#define IHtmlSnap_GetClipWidth(This,nVal)	\
    (This)->lpVtbl -> GetClipWidth(This,nVal)

#define IHtmlSnap_GetClipHeight(This,nVal)	\
    (This)->lpVtbl -> GetClipHeight(This,nVal)

#define IHtmlSnap_DrawTxt(This,x,y,strText,nFontSize,nColor,strFontName)	\
    (This)->lpVtbl -> DrawTxt(This,x,y,strText,nFontSize,nColor,strFontName)

#define IHtmlSnap_SetAuthUserAndPasswd(This,strAuthUser,strAuthPasswd)	\
    (This)->lpVtbl -> SetAuthUserAndPasswd(This,strAuthUser,strAuthPasswd)

#define IHtmlSnap_SetFillColor(This,nColor)	\
    (This)->lpVtbl -> SetFillColor(This,nColor)

#define IHtmlSnap_IsGoodUrlForSnap(This,strUrl,nVal)	\
    (This)->lpVtbl -> IsGoodUrlForSnap(This,strUrl,nVal)

#define IHtmlSnap_SetPlacableWMF(This,nPlacable)	\
    (This)->lpVtbl -> SetPlacableWMF(This,nPlacable)

#define IHtmlSnap_SetSmoothingMode(This,nValue)	\
    (This)->lpVtbl -> SetSmoothingMode(This,nValue)

#define IHtmlSnap_SetInterpolationMode(This,nValue)	\
    (This)->lpVtbl -> SetInterpolationMode(This,nValue)

#define IHtmlSnap_SaveMultipageTiff(This,strPicFile,nHeight)	\
    (This)->lpVtbl -> SaveMultipageTiff(This,strPicFile,nHeight)

#define IHtmlSnap_GetImageMap(This,strTitle)	\
    (This)->lpVtbl -> GetImageMap(This,strTitle)

#define IHtmlSnap_GetLinksExtra(This,strLinkRects)	\
    (This)->lpVtbl -> GetLinksExtra(This,strLinkRects)

#define IHtmlSnap_ConvertEMFToMultipleTiff(This,strMetaFile,strImageFile,nWidth,nHeight,nPageHeight)	\
    (This)->lpVtbl -> ConvertEMFToMultipleTiff(This,strMetaFile,strImageFile,nWidth,nHeight,nPageHeight)

#define IHtmlSnap_SetRenderEngine(This,nValue)	\
    (This)->lpVtbl -> SetRenderEngine(This,nValue)

#define IHtmlSnap_TiffCommand(This,strInput,strOutput,command)	\
    (This)->lpVtbl -> TiffCommand(This,strInput,strOutput,command)

#define IHtmlSnap_SetProxy(This,proxyUrl,strUser,strPasswd,autoConfig)	\
    (This)->lpVtbl -> SetProxy(This,proxyUrl,strUser,strPasswd,autoConfig)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SnapUrl_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strUrl,
    /* [in] */ BSTR strPicFile);


void __RPC_STUB IHtmlSnap_SnapUrl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetThumbnailImage_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strInputFile,
    /* [in] */ BSTR strOutputFile,
    /* [in] */ LONG cx,
    /* [in] */ LONG cy,
    /* [in] */ LONG bRemainRatio);


void __RPC_STUB IHtmlSnap_GetThumbnailImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetCode_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strCode);


void __RPC_STUB IHtmlSnap_SetCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetAsync_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BOOL bAsync);


void __RPC_STUB IHtmlSnap_SetAsync_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetTimeOut_Proxy( 
    IHtmlSnap * This,
    /* [in] */ long nTimeOut);


void __RPC_STUB IHtmlSnap_SetTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetDelayTime_Proxy( 
    IHtmlSnap * This,
    /* [in] */ long nDelayTime);


void __RPC_STUB IHtmlSnap_SetDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_WaitUntilDone_Proxy( 
    IHtmlSnap * This,
    /* [in] */ long nTimeOut);


void __RPC_STUB IHtmlSnap_WaitUntilDone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_EnableActiveX_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BOOL bVal);


void __RPC_STUB IHtmlSnap_EnableActiveX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_EnableJava_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BOOL bVal);


void __RPC_STUB IHtmlSnap_EnableJava_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_EnableScript_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BOOL bVal);


void __RPC_STUB IHtmlSnap_EnableScript_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetLinks_Proxy( 
    IHtmlSnap * This,
    /* [retval][out] */ VARIANT *strLinks);


void __RPC_STUB IHtmlSnap_GetLinks_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetTitle_Proxy( 
    IHtmlSnap * This,
    /* [retval][out] */ BSTR *strTitle);


void __RPC_STUB IHtmlSnap_GetTitle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetSource_Proxy( 
    IHtmlSnap * This,
    /* [retval][out] */ BSTR *strTitle);


void __RPC_STUB IHtmlSnap_GetSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetPageRank_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strUrl,
    /* [retval][out] */ long *nPageRank);


void __RPC_STUB IHtmlSnap_GetPageRank_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetSnapDimension_Proxy( 
    IHtmlSnap * This,
    /* [in] */ long cx,
    /* [in] */ long cy);


void __RPC_STUB IHtmlSnap_SetSnapDimension_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetJPEGQuality_Proxy( 
    IHtmlSnap * This,
    /* [in] */ long nQuality);


void __RPC_STUB IHtmlSnap_SetJPEGQuality_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SnapHtmlString_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strHtml,
    /* [in] */ BSTR strPicFile);


void __RPC_STUB IHtmlSnap_SnapHtmlString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetFrames_Proxy( 
    IHtmlSnap * This,
    /* [retval][out] */ VARIANT *strLinks);


void __RPC_STUB IHtmlSnap_GetFrames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetBitmapHandle_Proxy( 
    IHtmlSnap * This,
    /* [retval][out] */ LONG *Handle);


void __RPC_STUB IHtmlSnap_GetBitmapHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetImageWidth_Proxy( 
    IHtmlSnap * This,
    /* [retval][out] */ LONG *nVal);


void __RPC_STUB IHtmlSnap_GetImageWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetImageHeight_Proxy( 
    IHtmlSnap * This,
    /* [retval][out] */ LONG *nVal);


void __RPC_STUB IHtmlSnap_GetImageHeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetClipRect_Proxy( 
    IHtmlSnap * This,
    /* [in] */ long x,
    /* [in] */ long y,
    /* [in] */ long w,
    /* [in] */ long h);


void __RPC_STUB IHtmlSnap_SetClipRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SaveImage_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strPicFile);


void __RPC_STUB IHtmlSnap_SaveImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetText_Proxy( 
    IHtmlSnap * This,
    /* [retval][out] */ BSTR *strText);


void __RPC_STUB IHtmlSnap_GetText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetPostData_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strData);


void __RPC_STUB IHtmlSnap_SetPostData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetCookie_Proxy( 
    IHtmlSnap * This,
    /* [retval][out] */ BSTR *strCookie);


void __RPC_STUB IHtmlSnap_GetCookie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetCookie_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strUrl,
    /* [in] */ BSTR strCookieName,
    /* [in] */ BSTR strCookieValue);


void __RPC_STUB IHtmlSnap_SetCookie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetCookie2_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strUrl,
    /* [retval][out] */ BSTR *strCookie);


void __RPC_STUB IHtmlSnap_GetCookie2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetHtmlDocument_Proxy( 
    IHtmlSnap * This,
    /* [retval][out] */ IDispatch **pDocDisp);


void __RPC_STUB IHtmlSnap_GetHtmlDocument_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_ReSnap_Proxy( 
    IHtmlSnap * This);


void __RPC_STUB IHtmlSnap_ReSnap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_EnableSnapDimensionAsImageSize_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BOOL bVal);


void __RPC_STUB IHtmlSnap_EnableSnapDimensionAsImageSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_MakeGrayImage_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strInputFile,
    /* [in] */ BSTR strOutputFile,
    /* [in] */ LONG bGrayOrBW);


void __RPC_STUB IHtmlSnap_MakeGrayImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_Clear_Proxy( 
    IHtmlSnap * This);


void __RPC_STUB IHtmlSnap_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetErrorCode_Proxy( 
    IHtmlSnap * This,
    /* [retval][out] */ LONG *nErr);


void __RPC_STUB IHtmlSnap_GetErrorCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetTIFFEncoder_Proxy( 
    IHtmlSnap * This,
    /* [in] */ enum HTMLSNAPTIFFCOMPRESSION nCompression);


void __RPC_STUB IHtmlSnap_SetTIFFEncoder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetThreshold_Proxy( 
    IHtmlSnap * This,
    /* [in] */ LONG nThreshold);


void __RPC_STUB IHtmlSnap_SetThreshold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_ReduceColor_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strInputFile,
    /* [in] */ BSTR strOutputFile,
    /* [in] */ LONG nMaxColor);


void __RPC_STUB IHtmlSnap_ReduceColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetForceSnap_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BOOL bForceSnap);


void __RPC_STUB IHtmlSnap_SetForceSnap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetDither_Proxy( 
    IHtmlSnap * This,
    /* [in] */ enum HTMLSNAPDITHER nDither);


void __RPC_STUB IHtmlSnap_SetDither_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SaveWebPageToMHT_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strUrl,
    /* [in] */ BSTR strMHT);


void __RPC_STUB IHtmlSnap_SaveWebPageToMHT_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetZoom_Proxy( 
    IHtmlSnap * This,
    /* [in] */ DOUBLE fZoomRatio);


void __RPC_STUB IHtmlSnap_SetZoom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetImageBytes_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strFormat,
    /* [retval][out] */ VARIANT *pBlob);


void __RPC_STUB IHtmlSnap_GetImageBytes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetThumbImageBytes_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strFormat,
    /* [in] */ LONG cx,
    /* [in] */ LONG cy,
    /* [in] */ LONG bRemainRatio,
    /* [retval][out] */ VARIANT *pBlob);


void __RPC_STUB IHtmlSnap_GetThumbImageBytes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetFramesEx_Proxy( 
    IHtmlSnap * This,
    /* [retval][out] */ VARIANT *strLinks);


void __RPC_STUB IHtmlSnap_GetFramesEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetFrameHtmlDocument_Proxy( 
    IHtmlSnap * This,
    /* [in] */ LONG iFrame,
    /* [retval][out] */ IDispatch **pDocDisp);


void __RPC_STUB IHtmlSnap_GetFrameHtmlDocument_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetDPI_Proxy( 
    IHtmlSnap * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y);


void __RPC_STUB IHtmlSnap_SetDPI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetLogonUser_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strUser,
    /* [in] */ BSTR strDomain,
    /* [in] */ BSTR strPasswd);


void __RPC_STUB IHtmlSnap_SetLogonUser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetGIFOption_Proxy( 
    IHtmlSnap * This,
    /* [in] */ LONG bTrans,
    /* [in] */ LONG nColor);


void __RPC_STUB IHtmlSnap_SetGIFOption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetGIFOption2_Proxy( 
    IHtmlSnap * This,
    /* [in] */ LONG nColor);


void __RPC_STUB IHtmlSnap_SetGIFOption2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_ConvertEMFToImage_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strMetaFile,
    /* [in] */ BSTR strImageFile,
    /* [in] */ LONG nWidth,
    /* [in] */ LONG nHeight,
    /* [in] */ LONG nKeepRatio);


void __RPC_STUB IHtmlSnap_ConvertEMFToImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SnapWebBrowser_Proxy( 
    IHtmlSnap * This,
    /* [in] */ IDispatch *pBrowser,
    /* [in] */ BSTR strFile);


void __RPC_STUB IHtmlSnap_SnapWebBrowser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SnapWebBrowserAsBitmap_Proxy( 
    IHtmlSnap * This,
    /* [in] */ IDispatch *pBrowser,
    /* [retval][out] */ LONG *Handle);


void __RPC_STUB IHtmlSnap_SnapWebBrowserAsBitmap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetSnapUrlWorkingMode_Proxy( 
    IHtmlSnap * This,
    /* [in] */ LONG nMode);


void __RPC_STUB IHtmlSnap_SetSnapUrlWorkingMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_AutoClipMargin_Proxy( 
    IHtmlSnap * This,
    /* [in] */ LONG nMinMargin);


void __RPC_STUB IHtmlSnap_AutoClipMargin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetClipX_Proxy( 
    IHtmlSnap * This,
    /* [retval][out] */ LONG *nVal);


void __RPC_STUB IHtmlSnap_GetClipX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetClipY_Proxy( 
    IHtmlSnap * This,
    /* [retval][out] */ LONG *nVal);


void __RPC_STUB IHtmlSnap_GetClipY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetClipWidth_Proxy( 
    IHtmlSnap * This,
    /* [retval][out] */ LONG *nVal);


void __RPC_STUB IHtmlSnap_GetClipWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetClipHeight_Proxy( 
    IHtmlSnap * This,
    /* [retval][out] */ LONG *nVal);


void __RPC_STUB IHtmlSnap_GetClipHeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_DrawTxt_Proxy( 
    IHtmlSnap * This,
    /* [in] */ LONG x,
    /* [in] */ LONG y,
    /* [in] */ BSTR strText,
    /* [in] */ LONG nFontSize,
    /* [in] */ LONG nColor,
    /* [in] */ BSTR strFontName);


void __RPC_STUB IHtmlSnap_DrawTxt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetAuthUserAndPasswd_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strAuthUser,
    /* [in] */ BSTR strAuthPasswd);


void __RPC_STUB IHtmlSnap_SetAuthUserAndPasswd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetFillColor_Proxy( 
    IHtmlSnap * This,
    /* [in] */ LONG nColor);


void __RPC_STUB IHtmlSnap_SetFillColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_IsGoodUrlForSnap_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strUrl,
    /* [retval][out] */ LONG *nVal);


void __RPC_STUB IHtmlSnap_IsGoodUrlForSnap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetPlacableWMF_Proxy( 
    IHtmlSnap * This,
    /* [in] */ LONG nPlacable);


void __RPC_STUB IHtmlSnap_SetPlacableWMF_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetSmoothingMode_Proxy( 
    IHtmlSnap * This,
    /* [in] */ LONG nValue);


void __RPC_STUB IHtmlSnap_SetSmoothingMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetInterpolationMode_Proxy( 
    IHtmlSnap * This,
    /* [in] */ LONG nValue);


void __RPC_STUB IHtmlSnap_SetInterpolationMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SaveMultipageTiff_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strPicFile,
    /* [in] */ LONG nHeight);


void __RPC_STUB IHtmlSnap_SaveMultipageTiff_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetImageMap_Proxy( 
    IHtmlSnap * This,
    /* [retval][out] */ BSTR *strTitle);


void __RPC_STUB IHtmlSnap_GetImageMap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_GetLinksExtra_Proxy( 
    IHtmlSnap * This,
    /* [retval][out] */ VARIANT *strLinkRects);


void __RPC_STUB IHtmlSnap_GetLinksExtra_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_ConvertEMFToMultipleTiff_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strMetaFile,
    /* [in] */ BSTR strImageFile,
    /* [in] */ LONG nWidth,
    /* [in] */ LONG nHeight,
    /* [in] */ LONG nPageHeight);


void __RPC_STUB IHtmlSnap_ConvertEMFToMultipleTiff_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetRenderEngine_Proxy( 
    IHtmlSnap * This,
    /* [in] */ LONG nValue);


void __RPC_STUB IHtmlSnap_SetRenderEngine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_TiffCommand_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR strInput,
    /* [in] */ BSTR strOutput,
    /* [in] */ BSTR command);


void __RPC_STUB IHtmlSnap_TiffCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IHtmlSnap_SetProxy_Proxy( 
    IHtmlSnap * This,
    /* [in] */ BSTR proxyUrl,
    /* [in] */ BSTR strUser,
    /* [in] */ BSTR strPasswd,
    /* [in] */ LONG autoConfig);


void __RPC_STUB IHtmlSnap_SetProxy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHtmlSnap_INTERFACE_DEFINED__ */



#ifndef __HtmlSnap2_LIBRARY_DEFINED__
#define __HtmlSnap2_LIBRARY_DEFINED__

/* library HtmlSnap2 */
/* [helpstring][uuid][version] */ 

/* [helpstring][custom] */ 
enum HTMLSNAPSTATUS
    {	ERR_FINISH	= 1,
	ERR_NONE	= 0,
	ERR_SNAPHTML	= -1,
	ERR_SAVEFILE	= -2,
	ERR_NAVIGATE	= -3,
	ERR_TIMEOUT	= -4
    } ;
/* [helpstring][custom] */ 
enum HTMLSNAPDITHER
    {	DITHER_NONE	= 0,
	DITHER_FLOYD	= 1,
	DITHER_ORDERED	= 2
    } ;
/* [helpstring][custom] */ 
enum HTMLSNAPTIFFCOMPRESSION
    {	TIFF_LZW	= 0,
	TIFF_CCITT3	= 1,
	TIFF_CCITT4	= 2,
	TIFF_RLE	= 3,
	TIFF_NONE	= 4
    } ;
/* [helpstring][custom] */ 
enum HtmlSnapSmoothingMode
    {	HtmlSnapSmoothingModeDefault	= 0,
	HtmlSnapSmoothingModeHighSpeed	= 1,
	HtmlSnapSmoothingModeHighQuality	= 2,
	HtmlSnapSmoothingModeNone	= 3,
	HtmlSnapSmoothingModeAntiAlias	= 4
    } ;
/* [helpstring][custom] */ 
enum HtmlSnapInterpolationMode
    {	HtmlSnapInterpolationModeDefault	= 0,
	HtmlSnapInterpolationModeLowQuality	= 1,
	HtmlSnapInterpolationModeHighQuality	= 2,
	HtmlSnapInterpolationModeBilinear	= 3,
	HtmlSnapInterpolationModeBicubic	= 4,
	HtmlSnapInterpolationModeNearestNeighbor	= 5,
	HtmlSnapInterpolationModeHighQualityBilinear	= 6,
	HtmlSnapInterpolationModeHighQualityBicubic	= 7
    } ;

EXTERN_C const IID LIBID_HtmlSnap2;

#ifndef ___IHtmlSnapEvents_DISPINTERFACE_DEFINED__
#define ___IHtmlSnapEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IHtmlSnapEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IHtmlSnapEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("91B46E87-4CBE-4C1D-BEAC-51342BE2B2E1")
    _IHtmlSnapEvents : public IDispatch
    {
    	virtual ~_IHtmlSnapEvents() {}
    };
    
#else 	/* C style interface */

    typedef struct _IHtmlSnapEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IHtmlSnapEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IHtmlSnapEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IHtmlSnapEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IHtmlSnapEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IHtmlSnapEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IHtmlSnapEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IHtmlSnapEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IHtmlSnapEventsVtbl;

    interface _IHtmlSnapEvents
    {
        CONST_VTBL struct _IHtmlSnapEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IHtmlSnapEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IHtmlSnapEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IHtmlSnapEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IHtmlSnapEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IHtmlSnapEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IHtmlSnapEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IHtmlSnapEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IHtmlSnapEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CHtmlSnap;

#ifdef __cplusplus

class DECLSPEC_UUID("ADF55FB4-E4A0-47C8-A7B4-89C7328A9AB5")
CHtmlSnap;
#endif
#endif /* __HtmlSnap2_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


