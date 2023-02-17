#include <stdio.h>
#include <math.h>

int main() {
	int leftBordar;
	int rightBordar;
	scanf("%d,%d", &leftBordar, &rightBordar);
	for (int i = leftBordar; i <= rightBordar; i++) {
		for (int j = i; j <= rightBordar; j++) {
			int sqrtSum = pow(i, 2) + pow(j, 2);
			int p = (int)sqrt(sqrtSum);
			if (leftBordar <= p && p <= rightBordar && pow(p, 2) == sqrtSum) {
				printf("%d^2+%d^2=%d^2\n", i, j, p);
			}
		}
	}
}