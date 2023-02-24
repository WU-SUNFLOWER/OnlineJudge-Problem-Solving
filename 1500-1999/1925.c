#include <stdio.h>
#include <string.h>

//输入20个字符，统计其中英文字母、数字字符、空格或回车、其他字符的个数。

int main() {
	char ch;
	char str[21];
	int idx = 0;
	int englishTime = 0;
	int numberTime = 0;
	int spaceTime = 0;
	int otherTime = 0;
	while (idx < 20) {
		ch = getchar();
		if ('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z') {
			englishTime++;
		} 
		else if ('0' <= ch && ch <= '9') {
			numberTime++;
		}
		else if (ch == ' ' || ch == '\n') {
			spaceTime++;
		}
		else {
			otherTime++;
		}		
		idx++;
	}
	printf("%d个英文字母\n", englishTime);
	printf("%d个数字字符\n", numberTime);
	printf("%d个空格或回车\n", spaceTime);
	printf("%d个其他字符\n", otherTime);
}