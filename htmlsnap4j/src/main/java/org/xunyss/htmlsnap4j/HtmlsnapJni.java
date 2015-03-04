package org.xunyss.htmlsnap4j;

import java.awt.image.BufferedImage;


/**
 * 
 * @author XUNY
 */
class HtmlsnapJni {
	
	static {
		System.loadLibrary("htmlsnap4j-jni");
	}
	
	native boolean CreateInstance();
	native void ReleaseInstance();
	native void Snap(int target, String source, String picFile, HtmlsnapOptions options);
	
	
	native void SnapUrl(String url, String picFile);
	native void SnapHtmlString(String html, String picFile);
	native void ReSnap();
	
	
	native void EnableActiveX(boolean enable);
	native void EnableJava(boolean enable);
	native void EnableScript(boolean enable);
	
	native void SetRenderEngine(int engine);
	native void SetCode(String code);
	native void SetTimeOut(int timeOut);
	native void SetDelayTime(int delayTime);
	native void SetForceSnap(int forceSnap);
	native void SetSnapDimension(int cx, int cy);
	native void SetClipRect(int x, int y, int width, int height);
	native void SetZoom(double ratio);
	native void SetDPI(int xDPI, int yDPI);
	native void SetJPEGQuality(int quality);
	native void SetDither(int dither);
	native void SetTIFFEncoder(int compression);
	native void SetSmoothingMode(int smoothing);
	native void SetInterpolationMode(int interpolation);
	native void SetProxy(String host, String username, String password, int autoConfig);
	native void SetAsync(boolean async);
	native void SetLogonUser(String username, String domain, String password);
	native void SetAuthUserAndPasswd(String username, String password);
	native void SetPostData(String data);
	native void SetCookie(String url, String name, String data);
	native void SetThreshold(int threshold);
	native void DrawText(int x, int y, String text, int size, int color, String fontName);
	
	
	native void saveImage(String picFile);
	native void saveMultipageTiff(String picFile, int height);
	
	native String[] GetLinks();
	native String[] GetFrames();
	native String GetTitle();
	native String GetSource();
	native String GetText();
	native int GetImageWidth();
	native int GetImageHeight();
	native String GetCookie();
	native String GetCookie2(String url);
	
//	native Object GetBitmapHandle();
	native BufferedImage GetBufferedImage();
	native BufferedImage GetThumbBufferedImage(int cx, int cy, int remainRatio);
	native byte[] GetImageBytes(String imageType);
	native byte[] GetThumbImageBytes(String imageType, int cx, int cy, int remainRatio);
	
	native int GetErrorCode();
	native void Clear();
	
	
	native int IsGoodUrlForSnap(String url);
	native void MakeThumbnailImage(String inputFile, String outputFile, int cx, int cy, int remainRatio);
	native void MakeGrayImage(String inputFile, String outputFile, int grayOrBW);
	native void ReduceColor(String inputFile, String outputFile, int colors);
}
