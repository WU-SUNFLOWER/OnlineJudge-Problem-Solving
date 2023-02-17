#include <stdio.h>
#include <math.h>

int isSymNumber(int num) {
	int olderNum = num;
	int reverseNum = 0;
	while (olderNum > 0) {
		reverseNum = reverseNum * 10 + olderNum % 10;
		olderNum /= 10;
	}
	return num == reverseNum;
}

int main() {
	int m;
	scanf("%d", &m);
	if (isSymNumber(m) && isSymNumber(pow(m, 2)) && isSymNumber(pow(m, 3))) {
		printf("%d�����ػ�����\n", m);
	} else {
		printf("%d�������ػ�����\n", m);
	}
}