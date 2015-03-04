package org.xunyss.htmlsnap4j;

/**
 * 
 * @author XUNY
 */
class HtmlsnapOptions {
	
	/**
	 * 
	 */
	boolean _code			= false;			String	code;
	
	/**
	 * 
	 */
	boolean _timeOut		= false;			int		timeOut;
	
	/**
	 * 
	 */
	boolean _delayTime		= false;			int		delayTime;
	
	/**
	 * 
	 */
	boolean _dimension		= false;			int		dimension_cx;
												int		dimension_cy;
	boolean _zoom			= false;			double	zoom_ratio;
	boolean _auth			= false;			String	auth_username;
												String	auth_password;
	boolean _postdata		= false;			String	postdata;
	boolean _cookie			= false;			String	cookie_url;
												String	cookie_name;
												String	cookie_data;
}
