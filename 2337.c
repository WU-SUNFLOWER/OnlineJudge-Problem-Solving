#include <stdio.h>

int isSymNumber(int num, int k) {
	int tempNum = num;
	int reversNum = 0;
	while (tempNum > 0) {
		reversNum = reversNum * k + tempNum % k;
		tempNum /= k;
	}
	return reversNum == num;
}

int main() {
	int num;
	while (scanf("%d", &num) != EOF) {
		int flag = 1;
		for (int k = 2; k <= 10; k++) {
			if (isSymNumber(num, k)) {
				printf("Yes\n");
				flag = 0;
				break;
			}
		}
		flag && printf("No\n");
	}
}