//练习11.11：验证是否调用Object的无参构造方法
public class Test {
	public static void main(String[] args) {
		A a = new A(3);
		B b = new B();
		boolean is = a instanceof A,
				is1 = b instanceof B,
				is2 = a instanceof B,
				is3 = b instanceof A;

		System.out.println(is);
		System.out.println(is1);
		System.out.println(is2);
		System.out.println(is3);

		//A a1 = (A)b;
		B b1 = (B)a;
	}
}

class A extends B {
	public A(int t) {
		System.out.println("A's constructor is invoked");
	}
}

class B {
	public B() {
		System.out.println("B's constructor is invoked");
	}
}

