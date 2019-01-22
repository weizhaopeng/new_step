//练习8.8
public class Fan {
	public static void main(String[] args) {
		Fan fun1 = new Fan(Fan.FAST, true, 10.0, "yellow"),
			fun2 = new Fan(Fan.MEDIUM, false, 5.0, "blue");
		System.out.println(fun1.toSring());	
		System.out.println(fun2.toSring());	
	}

	int getSpeed() {
		return(speed);
	}
	boolean getOn() {
		return(on);
	}
	double getRadius() {
		return(radius);
	}
	String getColor() {
		return(color);
	}
	void setSpeed(int aSpeed) {
		this.speed = aSpeed;
	}
	void setOn(boolean aOn) {
		this.on = aOn;
	}
	void setRadius(double aRadius) {
		this.radius = aRadius;
	}
	void setColor(String aColor) {
		//TODO 字符串赋值不是这样的
		this.color = new String(aColor);
	}

	public String toSring() {
		String returnString = null;

		if (on)
			//TODO 如何将数值转化为字符串
			returnString = new String("speed = "
				+String.valueOf(this.speed)
				+", on = "+String.valueOf(this.on)
				+", radius = "+String.valueOf(this.radius)
				+", color = "+this.color);
		else
			returnString = new String("fan is off, radius = "
				+String.valueOf(this.radius)
				+", color = "+this.color);

		return(returnString);
	}

	public Fan() {
		this.speed  = SLOW;
		this.on	   = false;
		this.radius = 5;
		this.color  = new String("blue");
	}
	public Fan(int aSpeed, boolean aOn, double aRadius, String aColor) {
		this.speed = aSpeed;
		this.on	   = aOn;
		this.radius = aRadius;
		this.color = new String(aColor);
	}
	
	static final int SLOW = 1, MEDIUM = 2, FAST = 3;
	private int speed 	  = SLOW;
	private boolean on 	  = false;
	private double radius = 5.0;
	private String color  = "blue";
}

	

