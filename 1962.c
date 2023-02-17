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
    scanf("%d", &num);
    printf(isSymNumber(num, 10) ? "yes" : "no");
}