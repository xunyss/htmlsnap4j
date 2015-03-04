package org.xunyss.htmlsnap4j;

import org.junit.Test;

public class Tests {
	
	@Test
	public void test() {
		System.out.println("test");
	}
	
//	@Test
	public void testHtmlsnap() throws Exception {
		Htmlsnap htmlsnap = new Htmlsnap();
		htmlsnap.createComponent();
		
		htmlsnap.setCode("349D3B6C3B09317F");
		htmlsnap.drawText(10, 10, "12A34321234", 50, 9999, "Arial");
		htmlsnap.snapUrl("http://www.google.com/", "D:/Downloads/가나다.png");
		
		String title = htmlsnap.getTitle();
		System.out.println(title);
		
		int width = htmlsnap.getImageWidth();
		int height = htmlsnap.getImageHeight();
		System.out.println("width : " + width + " , height : " + height);
		
		System.out.println(htmlsnap.isGoodUrlForSnap("http://www.google.com/"));
		
		htmlsnap.release();
	}
	
//	@Test
	public void testHtmlsnapOptions() throws Exception {
//		Htmlsnap htmlsnap = new Htmlsnap();
//		htmlsnap.createComponent();
//		htmlsnap.setCode("349D3B6C3B09317F");
//		htmlsnap.snapUrl("http://www.naver.com/", "D:/Downloads/가나다.png");
//		
//		String title = htmlsnap.getTitle();
//		System.out.println(title);
//		
//		BufferedImage image = htmlsnap.getBufferedImage();
//		ImageIO.write(image, "jpg", new File("D:/Downloads/라마바.jpg"));
//		
//		htmlsnap.release();
	}
	
//	@Test
	public void testHtmlsnapStatic() throws Exception {
//		Htmlsnap htmlsnap = new Htmlsnap();
//		htmlsnap.createComponent();
//		htmlsnap.makeThumbnailImage("D:/Downloads/가나다.png", "D:/Downloads/가나다2.png", 100, 80, true);
//		htmlsnap.release();
	}
	
//	@Test
	public void testHtmlsnapImage() throws Exception {
//		Htmlsnap htmlsnap = new Htmlsnap();
//		htmlsnap.createComponent();
//		htmlsnap.setCode("349D3B6C3B09317F");
//		htmlsnap.snapUrl("http://www.google.com/", "D:/Downloads/가나다.png");
//		
//	//	byte[] bytes = htmlsnap.getImageBytes("*.png");
////		byte[] bytes = htmlsnap.getThumbImageBytes("*.png", 200, 800, true);
////		InputStream input = new ByteArrayInputStream(bytes);
////		BufferedImage image = ImageIO.read(input);
////		ImageIO.write(image, "png", new File("D:/Downloads/메롱.png"));
//		
//		BufferedImage image = htmlsnap.getThumbBufferedImage(200, 800, true);
//		ImageIO.write(image, "png", new File("D:/Downloads/메롱.png"));
//		
//		htmlsnap.release();
	}
}
