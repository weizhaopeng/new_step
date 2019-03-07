//java编程思想测试内部类，可以访问外部类的私有变量
interface Selector {
	boolean end();
	Object  current();
	void 	next();
}

class Sequence {
	private Object[] items;
	private int 	 next = 0;
	public Sequence(int size) {
		items = new Object[size];
	}
	public void add(Object x) {
		if (next < items.length)
			items[next++] = x;
	}
	
	private class SequenceSelector implements Selector {
		private int i = 0;

		public boolean end() {
			return i == items.length;
		}
		public Object current() {
			if(this.end() == false)
				return items[i];
			else
				return null;
		}
		public void next() {
			if (i < items.length)
				i++;
		}
	}
	//TODO 这里创建的方法返回值是接口，实际上是返回了实现了接口的类
	//我们可以看到接口和类其实是一种东西
	public Selector selector() {
		return(new SequenceSelector());
	}

	public static void main(String[] args) {
		Sequence sequence = new Sequence(10);
		for (int i = 0; i < 10; i++) {
			sequence.add(Integer.toString(i));
		}
		Selector s = sequence.selector();
		while (!s.end()) {
			System.out.println(s.current());
			s.next();
		}
	}
}

class StringClass {
	private String s;

	public StringClass(String sIn) {
		s = new String(sIn);
	}
	public void printString() {
		System.out.println(s);
	}
}

