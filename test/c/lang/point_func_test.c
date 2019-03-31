#include <stdio.h>

void function1(void) {
	printf("function:1\n");
}

void function2(char *string) {
	printf("function2:%s\n", string);
}

int function3(void) {
	printf("function3:\n");
	return 0;
}

int function4(void (*function)(char *), char *argv) {
	(*function)(argv);
	return 0;
}

int main(void) {
	void (*f1)(void);
	void (*f2)(char *string);
	int  (*f3)(void);
	int  (*f4)(void (*function)(char *argv), char *argv);

	f1 = function1;
	f2 = function2;
	f3 = function3;
	f4 = function4;

	(*f1)();
	(*f2)("nihao");
	printf("%d\n", (*f3)());
	(*function1)();
	function1();
	(*f4)(function2, "hey");
	return 0;
}


