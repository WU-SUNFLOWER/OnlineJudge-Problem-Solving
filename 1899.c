#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	if (n) {
		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j <= i; j++) {
				if (i >= 5 && j >= 2) {
					printf(" %d*%d=%d ", i, j, i * j);
				}
				else if (i == 4 && j == 4) {
					printf("%d*%d=%d ", i, j, i * j);
				}
			    else {
					printf(" %d*%d=%d  ", i, j, i * j);
				}
			}
			printf("\n");
		}
	}
}