//我们想知道几件事：java的方法中可以使用C语言的值结果参数吗？java可以返回字符串数组吗？
package method.method_return;

public class MethodDemo {
	public static void main(String[] args) {
		Demo1 d1 = new Demo1();
		String[] array = new String[10], retArray = null, array1 = new String[10];

		for (int i = 0; i < 10; i++)
			array1[i] = new String("yes");
		retArray = d1.method1();
		d1.method2(array);
		for (int i = 0; i < 10; i++) {
			//System.out.println(retArray[i]);
			//System.out.println(array[i]);
			System.out.println(array1[i]);
		}
	}
}

class Demo1 {
	//是否可以返回在方法中定义的堆变量
	public String[] method1() {
		String[] stringArray = new String[10];
		for (int i = 0; i < 10; i++)
			stringArray[i] = new String("nihao");

		return(stringArray);
	}
	//是否可以将在方法中分配的堆变量挂到形参引用上
	public void method2(String[] array) {
		for (int i = 0; i < 10; i++)
			array[i] = new String("weizhaopeng");
	}
	//是否可以满足值-结果参数，改变形参内容
	public void method3(String[] array) {
		array[5] = "no";
	}
}


