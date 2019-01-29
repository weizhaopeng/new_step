//XXX 习题11.1
class A {
	public A(int a) {
		System.out.println("A's no-arg constructor is invoked");
	}
}

class B extends A {
	public B(int a) {
		super(a);
	}
}

public class C {
	public static void main(String[] args) {
		B b = new B(5);
	}
}

