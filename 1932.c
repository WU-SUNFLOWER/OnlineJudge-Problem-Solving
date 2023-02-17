#include <stdio.h>
#include <math.h>

/*
验证哥德巴赫猜想：任何一个大于6的偶数均可表示为两个素数之和。输入一个大于6的偶数，要求输出所有的验证组合（不能重复）。
输出格式要求每个验证组合中的第一个素数小于后面累加的第二个素数，先输出的验证组合的第一个素数小于后面输出的验证组合的第一个素数，
且每行至多输出5个验证组合。

输入
90
输出
90=7+83 90=11+79 90=17+73 90=19+71 90=23+67
90=29+61 90=31+59 90=37+53 90=43+47

样例输入
56
样例输出
56=3+53 56=13+43 56=19+37
*/

int isPrimeNumber(int num) {
	for (int x = 2; x <= sqrt(num); x++) {
		if (num % x == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int n;
	int idx = 1;
	scanf("%d", &n);
	for (int i = 2; i < n; i++) {
		for (int j = i + 1; j <= n - i; j++) {
			if (i + j == n && isPrimeNumber(i) && isPrimeNumber(j)) {
				printf(idx % 5 == 1 ? "%d=%d+%d" : " %d=%d+%d", n, i, j);
				idx % 5 == 0 && printf("\n");
				idx++;
			}
		}
	}
}