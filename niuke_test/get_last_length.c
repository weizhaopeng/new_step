#include <stdio.h>
#include <string.h>

int is_letter(const char ch) {
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return 1;
	else
		return 0;
}

int main(int argc, char **argv) {
	char buf[5000] = {0};
	int  len_str, len_word = 0;

	scanf("%[^\n]s", buf);
	len_str = strlen(buf);

	for (int i = len_str-1; i >= 0; i--) {
		if (is_letter(buf[i]) == 1)
			len_word++;
		else {
			if (len_word == 0)
				continue;
			else
				break;
		}
	}
	printf("%d", len_word);
	return 0;
}

