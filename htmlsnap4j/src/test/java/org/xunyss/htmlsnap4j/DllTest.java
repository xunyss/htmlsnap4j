package org.xunyss.htmlsnap4j;

import org.junit.Test;

public class DllTest {
	
	@Test
	public void callDllTest() {
		
		HtmlsnapJni jni = new HtmlsnapJni();
		
		System.out.println(jni.CreateInstance());
		
		System.out.println(jni.IsGoodUrlForSnap("http://www.naver.com/"));
	}
}
