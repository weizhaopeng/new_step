public class Test {
	public static void main(String[] args) {
		Circle circle1 = new Circle();
		Circle circle2 = new Circle();
		System.out.println(circle1.equals(circle2));
	}
}

class Circle {
	double radius;

	public boolean equals(Circle circle) {
		return this.radius == (circle).radius;
	}
}


