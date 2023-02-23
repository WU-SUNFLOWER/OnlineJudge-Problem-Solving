#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	scanf("%d", &n);
	int* a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int x;
	scanf("%d ", &x); 
	int i;
	if (a[0] > x) {
		printf("%d ", x);
		for (int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}

	}
	else if (a[n - 1] < x) {
		for (int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		printf("%d", x);

	}
	else {
		int i;
		for (i = 0;a[i] <= x; i++) {
			printf("%d ", a[i]);
		}
		printf("%d", x);
		for (i; a[i] > x; i++) {
			printf("%d ", a[i]);
		}
	}
	return 0;
}