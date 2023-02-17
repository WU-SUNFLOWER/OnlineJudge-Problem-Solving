#include <stdio.h>
#include <math.h>

/*
输入两个正整数m和n（m≥1，n≤10000），从小到大输出m~n(包括m,n)之间的所有完数。
完数就是因子和与它本身相等的数。要求定义并调用函数factorsum(number)，它的功能是返回number的因子和。
例如：factorsum(12)的返回值是16，即1+2+3+4+6。

输入：
10 500
输出：
28 496

输入：
1 20
输出：
6
*/

int factorsum(int num) {
	int sum = 1;
	//由于1的因子只有本身，且因子和不能包括数自己，故需进行特殊处理
	if (num == 1) {
		return 0;
	}
	for (int x = 2; x <= sqrt(num); x++) { 
		if (num % x == 0) {
			sum += (x == num / x ? x : (x + num / x));
		}
	}
	return sum;
}

int main() {
	int m;
	int n;
	int idx = 0;
	int ansArr[10000];
	scanf("%d %d", &m, &n);
	for (; m <= n; m++) {
		if (factorsum(m) == m) {
			ansArr[idx++] = m;
		}
	}
	for (int i = 0; i <= idx - 1; i++) {
		printf(i < idx - 1 ? "%d " : "%d", ansArr[i]);
	}
}