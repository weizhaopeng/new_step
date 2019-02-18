//测试普通的内部类：内部类的出现是使得内部类可以访问外部类的私有的变量方法
public InternalClassDemo {
	public static void main(String[] args) {
		ExternalClass ec = new ExternalClass();
		InternalClass ic = new ExternalClass.InternalClass();
	}
}

class ExternalClass {
	private String className = "外部类";

	private void methodExternal() {
		System.out.println("外部类的私有方法");
	}

	class InternalClass {
		InternalClass() {
			methodExternal();
		}

		private String classNameIn = new String(className);
		public void externalShow() {
			System.out.println(className);
		}
	}
}

