#include <stdio.h>

int hasCharInArray(char arr[], int endPoint, char ch) {
	for (int i = 0; i <= endPoint; i++) {
		if (arr[i] == ch) {
			return 1;
		}
	}
	return 0;
}

int main() {
	char ch;
	int endPoint = -1;
	char BlackList[101];
	while ((ch = getchar()) != '\n' && ch != EOF) {
		if (!hasCharInArray(BlackList, endPoint, ch)) {
			printf("%c", ch);
			BlackList[++endPoint] = ch;
		}
	}
}