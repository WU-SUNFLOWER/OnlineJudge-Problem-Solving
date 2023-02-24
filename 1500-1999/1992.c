#include <stdio.h>
#include <math.h>

/*
求m~n（m≥10，n≤10000）之间的回文素数，所谓回文素数，即这个数既是回文又是素数。
程序首先要判断某个数是否是回文，再判断是否是素数。
如果是回文素数，则保存于数组中，并按6位域宽输出，每行输出5个。
*/

/*
输入：m n
输出：m~n之间的回文素数，每个数占6位，每行限输出5个
*/

/*
输入：
10 10000

输出：
    11   101   131   151   181
   191   313   353   373   383
   727   757   787   797   919
   929
*/

int isSymNumber(int num) {
	int tempNum = num;
	int reserveNum = 0;
	while (tempNum > 0) {
		reserveNum = reserveNum * 10 + tempNum % 10;
		tempNum /= 10;
	}
	return num == reserveNum;
}

int isPrimeNumber(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int m;
	int n;
	int idx1 = 0;
	int arr[9990];
	scanf("%d %d", &m, &n);
	//寻找符合题意的数字
	for (int num = m; num <= n; num++) {
		if (isSymNumber(num) && isPrimeNumber(num)) {
			arr[idx1++] = num;
		}
	}
	//输出结果
	for (int idx2 = 0; idx2 < idx1; idx2++) {
		printf("%6d", arr[idx2]);
		if ((idx2 + 1) % 5 == 0) {
			printf("\n");
		}
	}
}