//在此定义多个类实现接口，并且进行打印
public class Student implements Identical{
	public static void main(String[] args) {
		Student s = new Student();
		Teacher t = new Teacher();

		s.identifyShow();
		t.identifyShow();
		System.out.println(s.domain);
		System.out.println(t.domain);
	}

	public void identifyShow() {
		System.out.println("身份是学生");
	}

	private String id;
	private String school;
	private int    grade;
}

class Teacher implements Identical {
	public void identifyShow() {
		System.out.println("身份是老师");
	}
}

