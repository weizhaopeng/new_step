abstract class HourseAbstract {
	private int height;

	HourseAbstract() {
	}
	HourseAbstract(int inHeight) {
		height = inHeight;
	}

	public int getHeight() {
		return height;
	}
	public void setHeight(int newHeight) {
		this.height = newHeight;
	}

	public abstract void testAbstract();
}

class HourseChild extends HourseAbstract {
	HourseChild(int hei) {
		super(hei);
	}

	public void testAbstract() {
		System.out.println("this in the no variate testAbstract1");
	}
}

class HourseChild1 extends HourseAbstract {
	HourseChild1(int hei) {
		super(hei);
	}

	public void testAbstract() {
		System.out.println("this is in the with variate testAbstract1");
	}
}

public class AbstractTest {
	public static void main(String[] args) {
		HourseChild  hc  = new HourseChild(20);
		HourseChild1 hc1 = new HourseChild1(30);

		hc.testAbstract();
		hc1.testAbstract();
	}
}
		


