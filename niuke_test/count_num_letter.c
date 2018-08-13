/*输入一个字符串（字母，数字，空格）和一个字符，找出字符串中
 *该字符的个数
 */
#include <stdio.h>

int main(int argc, char **argv) {
	char buf[200] = {0};
	char char_count;

	scanf("%[^\n]s", 
