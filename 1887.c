#include <stdio.h>

//输入一个字符串，统计其中英文字母（包括大小写）、空格、数字和其它字符（上述几种外的其它字符）的个数。

int main() {
	char ch;
	int letterNum = 0;
	int spaceNum = 0;
	int numberNum = 0;
	int otherNum = 0;
	while ((ch = getchar()) != EOF && ch != '\n') {
		if ('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z') {
			letterNum++;
		}
		else if (ch == ' ') {
			spaceNum++;
		}
		else if ('0' <= ch && ch <= '9') {
			numberNum++;
		}
		else {
			otherNum++;
		}
	}
	printf("%d,%d,%d,%d", letterNum, spaceNum, numberNum, otherNum);
}