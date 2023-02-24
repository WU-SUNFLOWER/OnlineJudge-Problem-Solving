#include <stdio.h>

int convertHexToDec(char ch) {
	if ('0' <= ch && ch <= '9') {
		return (int)(ch - '0');
	}
	else if ('a' <= ch && ch <= 'f') {
		return 10 + (int)(ch - 'a');
	}
	else if ('A' <= ch && ch <= 'F') {
		return 10 + (int)(ch - 'A');
	}
}

int main() {
	char ch;
	int ans = 0;
	while ((ch = getchar()) != EOF && ch != '\n') {
		if (('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'f') || ('A' <= ch && ch <= 'F')) {
			ans = ans * 16 + convertHexToDec(ch);
		}
	}
	printf("%d", ans);
}