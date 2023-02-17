#include <stdio.h>
#include <math.h>

/*
从小到大输出两个正整数m和n（m≥6，n≤5000）之间的亲密数对。
说明：若a和b为一对亲密数，则a的因子和等于b，b的因子和等于a，且a不等于b。例如，220与284是一对亲密数。
*/

/*
输入：
100  2000
输出：
220 284
1184 1210
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
	int m;
	int n;
	scanf("%d %d", &m, &n);
	for (int x = m; x <= n; x++) {
		/*
		本题直接如直接使用暴力枚举寻找与x互为亲密数的y（比如下面的代码）
		虽然也能出结果，但是程序会严重超时
		for (int y = x + 1; y <= n; y++) {
			if (getSubSum(x) == y && getSubSum(y) == x) {
				printf("%d %d\n", x, y);
				break;
			}
		}
		*/
		/*
		本题的正确处理方法为利用亲密数定义进行寻找：
		根据getSubSum(x)=y可知假设x、y互为亲密数的前提下，由x求y的方法
		根据getSubSum(y)=x可知判定x、y是否互为亲密数的方法
		*/
		int y = getSubSum(x);
		if (x < y && getSubSum(y) == x) {
			printf("%d %d\n", x, y);
		}
	}
}