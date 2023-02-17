#include <stdio.h>
#include <math.h>

/*
数学上把相差为2的两个质数叫做“孪生质数”。孪生质数并不少见，3和5,5和7,11和13.人们已经知道：
小于100000的自然数中有1224对孪生质数
小于1000000的自然数中有8164对孪生质数
小于33000000的自然数中有152892对孪生质数
目前所知道的最大的孪生质数对是：1000000009649和1000000009651
那么，孪生质数会不会有无穷多对？
这个问题至今没有解决。现在请你编写一个程序，来帮助数学家解决该问题，根据数学家输入的一个范围，给出该范围内所有的孪生质数。
*/

/*
输入：
1 13
输出：
3 5
5 7
11 13
*/

int isPrimeNumber(unsigned int num) {
	if (num == 1) {
		return 0;
	}
	for (int x = 2; x <= sqrt(num); x++) {
		if (num % x == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	unsigned int leftBordar;
	unsigned int rightBordar;
	scanf("%u %u", &leftBordar, &rightBordar);
	for (; leftBordar <= rightBordar - 2; leftBordar++) {
		if (isPrimeNumber(leftBordar) && isPrimeNumber(leftBordar + 2)) {
			printf("%d %d\n", leftBordar, leftBordar + 2);
		}
	}
}