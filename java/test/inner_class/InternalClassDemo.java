//测试普通的内部类：内部类的出现是使得内部类可以访问外部类的私有的变量方法
class Outer {
	class Inner {
		void printName() {
			System.out.println("weizhaopeng");
		}
	}

	public Inner getInner(){
		return(new Inner());
	}

	public static void main(String[] args) {
		Outer out = new Outer();
		Outer.Inner in1 = out.getInner();
		Outer.Inner in = new Outer.Inner();
		in1.printName();
	}
}


