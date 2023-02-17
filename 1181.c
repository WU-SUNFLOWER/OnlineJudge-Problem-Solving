#include<stdio.h>
int main()
{
	int i;
	int a[10];
	for (i = 0; i <= 9; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 9; i >= 0; i--) {
		printf("%d", a[i]);
		if (i != 0) {
			printf(" ");
		}
	}
	return 0;
}
