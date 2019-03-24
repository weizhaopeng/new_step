#include <stdio.h>
#include <stdlib.h>

static inline int word_num(char *str) {
	int   num = 0, status = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'a' && str[i] <= 'z')
			status = 1;
		else {
			if (status == 1) {
				status = 0;
				num++;
			}
		}
	}
	return num;
}


int main(void) {
	char *str = " nihao   2323 js   wojiao weizhao os ";

	printf("%d\n", word_num(str));
	return 0;
}



