//测试11.2，验证父类的私有方法和静态方法能否被重写
public class Parent {
	private void func() {
		System.out.println("这是父类的私有方法");
	}

	static void func1() {
		System.out.println("这是父类的静态方法");
	}

	public static void main(String[] args) {
		Children c = new Children();
		c.func();
		c.func1();
	}
}

class Children extends Parent {
	private int length = 1;

	void func() {
		System.out.println("这是子类的覆盖的私有方法");
	}

	//override
	static void func1() {
		System.out.println("这是子类的覆盖的静态方法");
	}
}


