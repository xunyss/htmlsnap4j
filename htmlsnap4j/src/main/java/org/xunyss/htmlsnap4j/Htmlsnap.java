package org.xunyss.htmlsnap4j;

import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;

import javax.imageio.ImageIO;

/**
 * 
 * @author XUNY
 */
public class Htmlsnap {
	
	/**************************************************************************/
	
	private boolean _initCom = false;
	private HtmlsnapJni _htmlsnap = null;
	
	private boolean _useOptions = false;
	private HtmlsnapOptions _options = null;
	
	private boolean _snapDone = false;
	
	/**************************************************************************/
	
	public Htmlsnap() {
		
	}
	
	public Htmlsnap(boolean useOptions) {
		_useOptions = useOptions;
	}
	
	private void validateInitComponent() {
		if (!_initCom) {
			throw new IllegalStateException("Htmlsnap Component is not created.");
		}
	}
	private void validateCallAfterSnap() {
		if (!_snapDone) {
			throw new IllegalStateException("This function must be called after snapUrl or snapHtmlString");
		}
	}
	
	public void createComponent() {
		_htmlsnap = new HtmlsnapJni();
		if (_useOptions) {
			_options = new HtmlsnapOptions();
		}
		
		try {
			if (_htmlsnap.CreateInstance()) {
				_initCom = true;
			}
			else {
				release();
				throw new Exception();
			}
		}
		catch (Throwable t) {
			throw new IllegalStateException("Htmlsnap Component can not be created.");
		}
	}
	
	public void release() {
		if (_htmlsnap != null) {
			_htmlsnap.ReleaseInstance();
		}
		_initCom = false;
		_htmlsnap = null;
		if (_useOptions) {
			_options = null;
		}
		_snapDone = false;
	}
	
	@Override
	protected void finalize() {
		release();
	}
	
	/**************************************************************************/
	
	/**
	 * the main function to convert html to image
	 * 
	 * @param url
	 *        The URL of the web page to be taken snapshot.
	 * @param picFile
	 *        The local image file to be saved. It should be a valid file name.
	 *        For example, c:\1.jpg or c:\1.bmp etc.
	 *        Currently the component supports jpg, bmp, gif, tiff and png format.
	 *        It will convert html to image in the format given by the file extension.
	 */
	public void snapUrl(String url, String picFile) {
		validateInitComponent();
		if (_useOptions) {
			_htmlsnap.Snap(0, url, picFile, _options);
		}
		else {
			_htmlsnap.SnapUrl(url, picFile);
		}
		_snapDone = true;
	}
	
	/**
	 * 
	 * @param html
	 *        A html string
	 * @param picFile
	 *        The local image file to be saved.
	 */
	public void snapHtmlString(String html, String picFile) {
		validateInitComponent();
		if (_useOptions) {
			_htmlsnap.Snap(1, html, picFile, _options);
		}
		else {
			_htmlsnap.SnapHtmlString(html, picFile);
		}
		_snapDone = true;
	}
	
	/**
	 * Capture the image again after calling SnapUrl.
	 * This function will refresh the image in the memory,
	 * then you can call SaveImage or GetBitmapHandle to get the new image.
	 */
	public void reSnap() {
		validateInitComponent();
		_htmlsnap.ReSnap();
	}
	
	/**************************************************************************/
	
	/**
	 * 
	 * @param enable Determine if ActiveX is enabled on the html page
	 */
	public void enableActiveX(boolean enable) {
		validateInitComponent();
		_htmlsnap.EnableActiveX(enable);
	}
	
	/**
	 * 
	 * @param enable Determine if Java is enabled on the html page
	 */
	public void enableJava(boolean enable) {
		validateInitComponent();
		_htmlsnap.EnableJava(enable);
	}
	
	/**
	 * 
	 * @param enable Determine if Script is enabled on the html page
	 */
	public void enableScript(boolean enable) {
		validateInitComponent();
		_htmlsnap.EnableScript(enable);
	}
	
	/**
	 * Force the captured image size to be the dimension set by SetSnapDimension.
	 * If the dimension is larger than that of the html document,
	 * the gap will be filled with background color of the page.
	 * The default value is FALSE.
	 * 
	 * @param enable
	 */
	public void enableSnapDimensionAsImageSize(boolean enable) {
		
	}
	
	/**
	 * 1 is for firefox rendering engine, 0 for IE rendering engine (default)
	 * Htmlsnapshot now supports using firefox to render html to image on Windows.
	 * The steps are: 1. Install Htmlsnapshot
	 *                2. Install Firefox Addon for HtmlSnapshot
	 *                3. In your code, call SetRenderEngine to enable firefox.
	 * Note, Firefox engine doesn't supports converting html to vector image.
	 * 
	 * @param engine rendering engine
	 */
	public void setRenderEngine(Engine engine) {
		validateInitComponent();
		_htmlsnap.SetRenderEngine(engine.ordinal());
	}
	public static enum Engine { IE, FIREFOX }
	
	/**
	 * Set the registration code to eliminate the limitation in trial version.
	 * 
	 * @param code
	 */
	public void setCode(String code) {
		validateInitComponent();
		if (_useOptions) {
			_options._code = true;
			_options.code = code;
		}
		else {
			_htmlsnap.SetCode(code);
		}
	}
	
	/**
	 * 
	 * @param timeOut The time out value in milliseconds for SnapUrl.
	 *                 Using this to avoid hang. The default TimeOut value is 30000
	 */
	public void setTimeOut(int timeOut) {
		validateInitComponent();
		if (_useOptions) {
			_options._timeOut = true;
			_options.timeOut = timeOut;
		}
		else
		{
			_htmlsnap.SetTimeOut(timeOut);			
		}
	}
	
	/**
	 * 
	 * @param delayTime
	 *        The time value in milliseconds to wait after a html document is downloaded.
	 *        Sometimes, a page contains ActiveX like flash, which takes some time to initialize.
	 *        This method can be used to control the timing to capture the content of the dynamic embeded objects.
	 *        Default nDelayTime value is 1000.
	 */
	public void setDelayTime(int delayTime) {
		validateInitComponent();
		if (_useOptions) {
			_options._delayTime = true;
			_options.delayTime = delayTime;
		}
		else {
			_htmlsnap.SetDelayTime(delayTime);
		}
	}
	
	/**
	 * This method will make the component to capture the browser image even the time is out in some case.
	 * 
	 * @param forceSnap
	 */
	public void setForceSnap(boolean forceSnap) {
		validateInitComponent();
		_htmlsnap.SetForceSnap(forceSnap ? 1 : 0);
	}
	
	/**
	 * Set the width and height of the web browser window.
	 * The browser window size will affect the html document size in some way.
	 * 
	 * @param cx
	 * @param cy
	 */
	public void setSnapDimension(int cx, int cy) {
		validateInitComponent();
		if (_useOptions) {
			_options._dimension = true;
			_options.dimension_cx = cx;
			_options.dimension_cy = cy;
		}
		else {
			_htmlsnap.SetSnapDimension(cx, cy);			
		}
	}
	
	/**
	 * Set clip rect to the image.
	 * Call this function after SnapUrl.
	 * This method affects GetBitmapHandle and SaveImage.
	 * Call this function if you want to get/save portion of the image.
	 * setClipRect(0, 0, 0, 0) will clear the clip rect.
	 * 
	 * @param x
	 * @param y
	 * @param width
	 * @param height
	 */
	public void setClipRect(int x, int y, int width, int height) {
		validateInitComponent();
		_htmlsnap.SetClipRect(x, y, width, height);
	}
	
	/**
	 * Set the zoom ratio of the html page when doing snapshot.
	 * This can result in image with larger DPI.zoomRatio: the zoon ratio of the page. it is between 1 and 5
	 * 
	 * @param ratio
	 */
	public void setZoom(double ratio) {
		validateInitComponent();
		if (_useOptions) {
			_options._zoom = true;
			_options.zoom_ratio = ratio;
		}
		else {
			_htmlsnap.SetZoom(ratio);
		}
	}
	
	/**
	 * Set the image resolution on x, y axis.
	 * Some image formats like TIFF support DPI information.
	 * 
	 * @param xDPI
	 * @param yDPI
	 */
	public void setDPI(int xDPI, int yDPI) {
		validateInitComponent();
		_htmlsnap.SetDPI(xDPI, yDPI);
	}
	
	/**
	 * Set the quality of JPEG Compression.
	 * quality is between 0 and 100
	 *  
	 * @param quality
	 */
	public void setJPEGQuality(int quality) {
		validateInitComponent();
		_htmlsnap.SetJPEGQuality(quality);
	}
	
	/**
	 * Set the dither method when converting to 1bpp image.
	 * 
	 * @param dither
	 *        0: None; 1: Floyd dithering; 2:Ordered dithering
	 */
	public void setDither(Dither dither) {
		validateInitComponent();
		_htmlsnap.SetDither(dither.ordinal());
	}
	public static enum Dither { NONE, FLOYD, ORDERED }
	
	/**
	 * Set the compression method of TIFF image.
	 * 
	 * @param compression
	 *        0: LZW; 1: CCITT3; 2:CCITT4; 3: RLE; 5: None.
	 */
	public void setTIFFEncoder(TIFFEncoder compression) {
		validateInitComponent();
		_htmlsnap.SetTIFFEncoder(compression.ordinal());
	}
	public static enum TIFFEncoder { LZW, CCITT3, CCITT4, RLE, NONE }
	
	/**
	 * Set smoothing mode of resizing. Could have below values.
	 * HtmlSnapSmoothingModeDefault = 0,
	 * HtmlSnapSmoothingModeHighSpeed = 1,
	 * HtmlSnapSmoothingModeHighQuality = 2,
	 * HtmlSnapSmoothingModeNone = 3,
	 * HtmlSnapSmoothingModeAntiAlias = 4 
	 * 
	 * @param smoothing
	 */
	public void setSmoothingMode(Smoothing smoothing) {
		validateInitComponent();
		_htmlsnap.SetSmoothingMode(smoothing.ordinal());
	}
	public static enum Smoothing { DEFAULT, HIGHSPEED, HIGHQUALITY, NONE, ANTIALIAS }
	
	/**
	 * Set interpolation mode of resizing. Could have below values.
	 * HtmlSnapInterpolationModeDefault = 0,
	 * HtmlSnapInterpolationModeLowQuality = 1,
	 * HtmlSnapInterpolationModeHighQuality = 2,
	 * HtmlSnapInterpolationModeBilinear = 3,
	 * HtmlSnapInterpolationModeBicubic = 4,
	 * HtmlSnapInterpolationModeNearestNeighbor = 5,
	 * HtmlSnapInterpolationModeHighQualityBilinear = 6,
	 * HtmlSnapInterpolationModeHighQualityBicubic = 7
	 *  
	 * @param interpolation
	 */
	public void setInterpolationMode(Interpolation interpolation) {
		validateInitComponent();
		_htmlsnap.SetInterpolationMode(interpolation.ordinal());
	}
	public static enum Interpolation { DEFAULT, LOWQUALITY, HIGHQUALITY, BILINEAR, BICUBIC, NEARESTNEIGHBOR, HIGHQUALITYBILINEAR, HIGHQUALITYBICUBIC }
	
	/**
	 * allow to set custom proxy for IE
	 * 
	 * @param host could be an IP:port pair. Like this 127.0.0.1 or 127.0.0.1:3128
	 * @param username username required by the proxy server
	 * @param password password required by the proxy server
	 * @param autoConfig indicate if the proxy is an automatic configuration script. 0 is for no, 1 is for yes.
	 */
	public void setProxy(String host, String username, String password, boolean autoConfig) {
		validateInitComponent();
		_htmlsnap.SetProxy(host, username, password, autoConfig ? 1 : 0);
	}
	
	/**
	 * 
	 * @param async
	 *        If set to True, SnapUrl function will work asynchronously,
	 *        which means it will return immediately without waiting for the results.
	 *        Application can use the event to determine if the operation is done.
	 *        If set to False, SnapUrl will wait until the operation is done or the time is out.
	 */
	public void setAsync(boolean async) {
		validateInitComponent();
		_htmlsnap.SetAsync(async);
	}
	
	/**
	 * This method will set the user name and password.
	 * SnapUrl will do impersonation with the specified user name and
	 * convert html to image under that user account.
	 * This method is useful for using html snapshot in IIS with ASP or ASP.Net etc.
	 * 
	 * @param username
	 * @param domainName
	 * @param password
	 */
	public void setLogonUser(String username, String domain, String password) {
		validateInitComponent();
		_htmlsnap.SetLogonUser(username, domain, password);
	}
	
	/**
	 * set http authentication user name and password so that
	 * SnapUrl can bypass the autentication dialog automacically.
	 * 
	 * @param username
	 * @param password
	 */
	public void setAuthUserAndPasswd(String username, String password) {
		validateInitComponent();
		if (_useOptions) {
			_options._auth = true;
			_options.auth_username = username;
			_options.auth_password = password;
		}
		else {
			_htmlsnap.SetAuthUserAndPasswd(username, password);
		}
	}
	
	/**
	 * Set the data to be posted to the URL.
	 * Use this function for some urls protected by forms.
	 * 
	 * @param data
	 */
	public void setPostData(String data) {
		validateInitComponent();
		if (_useOptions) {
			_options._postdata = true;
			_options.postdata = data;
		}
		else {
			_htmlsnap.SetPostData(data);
		}
	}
	
	/**
	 * Set cookie for the URL.
	 * 
	 * @param url
	 * @param name
	 * @param data
	 */
	public void setCookie(String url, String name, String data) {
		validateInitComponent();
		if (_useOptions) {
			_options._cookie = true;
			_options.cookie_url = url;
			_options.cookie_name = name;
			_options.cookie_data = data;
		}
		else {
			_htmlsnap.SetCookie(url, name, data);			
		}
	}
	
	/**
	 * Set the threshold value (0-255) when converting image to monochrome.
	 * 
	 * @param threshold
	 */
	public void setThreshold(int threshold) {
		validateInitComponent();
		_htmlsnap.SetThreshold(threshold);
	}
	
	/**
	 * draw watermark text on the snapped image at the specificed position with the given size, color and font
	 * 
	 * @param x
	 * @param y
	 * @param text
	 * @param size
	 * @param color
	 * @param fontName
	 */
	public void drawText(int x, int y, String text, int size, int color, String fontName) {
		validateInitComponent();
		_htmlsnap.DrawText(x, y, text, size, color, fontName);
	}
	
	/**************************************************************************/
	
	/**
	 * Save the clip rect in the image to file.
	 * Call this function after SnapUrl
	 * 
	 * @param picFile
	 */
	public void saveImage(String picFile) {
		validateInitComponent();
		validateCallAfterSnap();
		_htmlsnap.saveImage(picFile);
	}
	
	/**
	 * Save the clip rect in the image to multiple page TIFF file.
	 * The height is the page height of the TIFF file.
	 * 
	 * @param picFile
	 * @param height
	 */
	public void saveMultipageTiff(String picFile, int height) {
		validateInitComponent();
		validateCallAfterSnap();
		_htmlsnap.saveMultipageTiff(picFile, height);
	}
	
	/**
	 * Return an array of links on the webpage.
	 * Call this function after SnapUrl
	 * 
	 * @return
	 */
	public String[] getLinks() {
		validateInitComponent();
		validateCallAfterSnap();
		return _htmlsnap.GetLinks();
	}
	
	/**
	 * Return an array of frame urls on the webpage.
	 * Call this function after SnapUrl
	 * 
	 * @return
	 */
	public String[] getFrames() {
		validateInitComponent();
		validateCallAfterSnap();
		return _htmlsnap.GetFrames();
	}
	
	/**
	 * Return the title of the webpage.
	 * Call this function after SnapUrl
	 * 
	 * @return
	 */
	public String getTitle() {
		validateInitComponent();
		validateCallAfterSnap();
		return _htmlsnap.GetTitle();
	}
	
	/**
	 * Return the html source of the webpage.
	 * Call this function after SnapUrl
	 * 
	 * @return
	 */
	public String getSource() {
		validateInitComponent();
		validateCallAfterSnap();
		return _htmlsnap.GetSource();
	}
	
	/**
	 * Return the text of the webpage.
	 * Call this function after SnapUrl
	 * 
	 * @return
	 */
	public String getText() {
		validateInitComponent();
		validateCallAfterSnap();
		return _htmlsnap.GetText();
	}
	
	/**
	 * Return the image width.
	 * Call this function after SnapUrl
	 * 
	 * @return
	 */
	public int getImageWidth() {
		validateInitComponent();
		validateCallAfterSnap();
		return _htmlsnap.GetImageWidth();
	}
	
	/**
	 * Return the image width.
	 * Call this function after SnapUrl
	 * 
	 * @return
	 */
	public int getImageHeight() {
		validateInitComponent();
		validateCallAfterSnap();
		return _htmlsnap.GetImageHeight();
	}
	
	/**
	 * Get cookie of current URL.
	 * Call this function after SnapUrl
	 * 
	 * @return
	 */
	public String getCookie() {
		validateInitComponent();
		validateCallAfterSnap();
		return _htmlsnap.GetCookie();
	}
	
	/**
	 * Get cookie for the URL.
	 * 
	 * @param url
	 * @return
	 */
	public String getCookie2(String url) {
		validateInitComponent();
		validateCallAfterSnap();
		return _htmlsnap.GetCookie2(url);
	}
	
	/**
	 * Return the bitmap handle to the image (the whole image or the clip rect) in memory.
	 * Call this function after SnapUrl.
	 * 
	 * @return
	 */
//	public Object getBitmapHandle() {
//		return null;
//	}
	
	/**
	 * 
	 * @return
	 */
	public BufferedImage getBufferedImage() {
		validateInitComponent();
		validateCallAfterSnap();
	//	return _htmlsnap.GetBufferedImage();
		byte[] bytes = _htmlsnap.GetImageBytes("*.bmp");
		try {
			InputStream input = new ByteArrayInputStream(bytes);
			return ImageIO.read(input);
		}
		catch (IOException ioe) {
			return null;
		}
	}
	
	/**
	 * 
	 * @param cx
	 * @param cy
	 * @param remainRatio
	 * @return
	 */
	public BufferedImage getThumbBufferedImage(int cx, int cy, boolean remainRatio) {
		validateInitComponent();
		validateCallAfterSnap();
	//	return _htmlsnap.GetThumbBufferedImage(cx, cy, remainRatio ? 1 : 0);
		byte[] bytes = _htmlsnap.GetThumbImageBytes("*.bmp", cx, cy, remainRatio ? 1 : 0);
		try {
			InputStream input = new ByteArrayInputStream(bytes);
			return ImageIO.read(input);
		}
		catch (IOException ioe) {
			return null;
		}
	}
	
	/**
	 * Get the in memory compressed image bytes.
	 * In this way, you can convert html to image in memory.
	 * 
	 * @param imageType the file format such as *.jpg, *.gif etc
	 * @return
	 */
	public byte[] getImageBytes(String imageType) {
		validateInitComponent();
		validateCallAfterSnap();
		return _htmlsnap.GetImageBytes(imageType);
	}
	
	/**
	 * Get the in memory compressed thumbnail image bytes.
	 * In this way, you can get the thumbnail images of the html page in memory.
	 * 
	 * @param imageType the file format such as *.jpg, *.gif etc
	 * @param cx the desired width of the thumbnail
	 * @param cy the desired height of the thumbnail
	 * @param remainRatio if nozero, the thumbnail image will has the same aspect ratio with large image.
	 * @return
	 */
	public byte[] getThumbImageBytes(String imageType, int cx, int cy, boolean remainRatio) {
		validateInitComponent();
		validateCallAfterSnap();
		return _htmlsnap.GetThumbImageBytes(imageType, cx, cy, remainRatio ? 1 : 0);
	}
	
	/**
	 * Return the status code of last snap action. See OnStatus section below for the meaning of the error code
	 * 
	 * @return
	 */
	public int getErrorCode() {
		validateInitComponent();
		validateCallAfterSnap();
		return _htmlsnap.GetErrorCode();
	}
	
	/**
	 * Release the resources allocated when doing SnapUrl or SnapHtmlString.
	 */
	public void clear() {
		validateInitComponent();
	//	checkCallAfterSnap();
		_htmlsnap.Clear();
		_snapDone = false;
	}
	
	/**************************************************************************/
	
	/**
	 * return true if the url's content type is text/html, else return false
	 * 
	 * @param url
	 * @return
	 */
	public boolean isGoodUrlForSnap(String url) {
		validateInitComponent();
		return _htmlsnap.IsGoodUrlForSnap(url) == 1;
	}
	
	/**
	 * 
	 * @param inputFile The input image file
	 * @param outputFile The thumbnail image file to be saved
	 * @param cx The dimension(x) of the thumbnail image.
	 * @param cy The dimension(y) of the thumbnail image.
	 * @param remainRatio If bRemainRation is 0, the thumbnail image will be exactly the size of cx, cy;
	 *                    else then remain the original image's aspect ratio.
	 */
	public void makeThumbnailImage(String inputFile, String outputFile, int cx, int cy, boolean remainRatio) {
		validateInitComponent();
		_htmlsnap.MakeThumbnailImage(inputFile, outputFile, cx, cy, remainRatio ? 1 : 0);
	}
	
	/**
	 * convert a color image to gray or black white only.
	 * If bGrayOrBW = 0 then, the result image is black white only, else it is gray.
	 * 
	 * @param inputFile
	 * @param outputFile
	 * @param grayOrBW
	 */
	public void makeGrayImage(String inputFile, String outputFile, boolean grayOrBW) {
		validateInitComponent();
		_htmlsnap.MakeGrayImage(inputFile, outputFile, grayOrBW ? 1 : 0);
	}
	
	/**
	 * Reduce the color number in input image. nColors is in [8-256].
	 * 
	 * @param inputFile
	 * @param outputFile
	 * @param colors
	 */
	public void reduceColor(String inputFile, String outputFile, int colors) {
		validateInitComponent();
		_htmlsnap.ReduceColor(inputFile, outputFile, colors);
	}
}
