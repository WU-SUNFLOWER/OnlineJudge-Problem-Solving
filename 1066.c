#include <stdio.h>
#include <math.h>

/*
如果a的因子和等于b，b的因子和等于a，且a≠b，则称a，b为亲密数对。 
比如220的所有真约数(即不是自身的约数)之和为: 1+2+4+5+10+11+20+22+44+55+110＝284。 
284的所有真约数和为: 1+2+4+71+142=220。 你的任务就编写一个程序，判断给定的两个数是否是亲和数。
*/

/*
输入：
2
220 284
100 200
输出：
YES
NO
*/

int getSubSum(int num) {
	int sum = 1;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			if (i == num / i) {
				sum += i;
			} else {
				sum += i + num / i;
			}
		}
	}
	return sum;
}

int main() {
	int TestNum;
	scanf("%d", &TestNum);
	while (TestNum-- > 0) {
		int x;
		int y;
		scanf("%d %d", &x, &y);
		if (getSubSum(x) == y && getSubSum(y) == x) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}