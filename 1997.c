#include <stdio.h>
#include <string.h>

int main() {
	int m;
	int i;
	int len;
	char str1[100];
	char str2[100];
	gets(str1);
	scanf("%d", &m);
	if (m > (len = strlen(str1))) {
		printf("Data error!");
	} else {
		for (i = 0; i <= len - m; i++) {
			str2[i] = str1[m + i - 1];
		}
		str2[i] = '\0';
		printf("%s\n", str2);		
	}
}