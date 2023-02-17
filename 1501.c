#include <stdio.h>

int main() {
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF) {
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			printf("%c", ch);
		}
	}
}