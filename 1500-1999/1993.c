#include <stdio.h>
#include <math.h>

/*
绝对素数是指本身是素数，其逆序数也是素数的数。
例如：10321与12301是绝对素数。编写一个程序，求出所有m~n（m≥11，n≤1000）之间的绝对素数。
程序要求实现两个自定义函数，prime(n)用于判断一个整数n是否是素数，是则返回1，否则返回0；
inv(n)用于对整数n进行逆序，函数返回逆序后的整数。主函数通过调用上述两个自定义函数实现绝对素数的判断和输出。

输入:
m n

输出:
m~n之间的绝对素数，每个输出整数占5位，每行输出10个
*/

/*
输入：
11 1000

输出：
   11   13   17   31   37   71   73   79   97  101
  107  113  131  149  151  157  167  179  181  191
  199  311  313  337  347  353  359  373  383  389
  701  709  727  733  739  743  751  757  761  769
  787  797  907  919  929  937  941  953  967  971
  983  991
*/

int isPrimeNumber(int num) {
	if (num == 1) {
		return 0;
	}
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int reverseNumber(int num) {
	int ans = 0;
	while (num > 0) {
		ans = ans * 10 + num % 10;
		num /= 10;
	}
	return ans;
}

int main() {
	int m;
	int n;
	int count = 0;
	scanf("%d %d", &m, &n);
	for (; m <= n; m++) {
		if (isPrimeNumber(m) && isPrimeNumber(reverseNumber(m))) {
			printf("%5d", m);
			if ((++count) % 10 == 0) {
				printf("\n");
			}
		}
	}
}