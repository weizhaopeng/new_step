//测试java中在实例化外部类的时候内部类会实例化吗？
class Outer {
	private int a;
	class Inner {
		private int b = 3;
		public void printName() {
			System.out.println(Outer.Inner.this.b+"weizhaopeng"+Outer.this.a);
		}
	}
	
	public static void main(String[] args) {
		Outer out = new Outer();
		Outer.Inner in = out.new Inner();
		in.printName();
		
	}
}


