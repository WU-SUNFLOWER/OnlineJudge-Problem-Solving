#include<stdio.h>
#include<string.h>

int main() {
	int i;
	int n;
	int num = 0;
	int t = 0;
	char a[1000];
	gets(a);
	n = strlen(a);
	for (i = 0; i < n; i++) {
		if (a[i] == ' ') {
			t = 0;
		}
		else if (t == 0) {
			t = 1;
			num++;
		}
	}
	printf("%d", num);
	return 0;
}