#include <stdio.h>
#include <string.h>

int main() {
	char str[81];
	scanf("%s", &str[0]);
	for (int i = 0; i < strlen(str); i++) {
		if ('a' <= str[i] && str[i] <= 'z' || 'A' <= str[i] && str[i] <= 'Z') {
			printf("%c", str[i]);
		}
	}
	printf("\n");
}