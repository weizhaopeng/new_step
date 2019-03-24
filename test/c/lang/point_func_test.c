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

int main(void) {
	void (*f1)(void);
	void (*f2)(char *string);
	int  (*f3)(void);

	f1 = function1;
	f2 = function2;
	f3 = function3;

	(*f1)();
	(*f2)("nihao");
	printf("%d\n", (*f3)());
	(*function1)();
	function1();
	return 0;
}


