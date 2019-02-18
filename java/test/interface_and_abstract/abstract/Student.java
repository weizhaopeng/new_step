//从这里出创建Student类用于继承IdentifyAbstract类，从而验证其实抽象类就是只允许实现一次的接口
public class Student extends IdentifyAbstract {
	public static void main(String[] args) {
		Student s = new Student();

		s.identifyShow();
		System.out.println(s.getDomain());
	}
	
	Student() {
		this.domain = "student";
	}

	public void identifyShow(int a) {
		System.out.println("身份是学生");
	}
}
