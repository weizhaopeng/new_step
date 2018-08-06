package stack import java.util;

class Stack extends java.util.ArrayList {
	private java.util.ArrayList stackBuffer;

	Stack() {
		stackBuffer = new java.util.ArrayList();
	}

	void push(Object o) {
		if (super.isEmpty())
			super.add(o);
		else
			System.out.println("the stack is full");
	}

	Object pop() {
		Object returnValue = 
		return 



