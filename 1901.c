#include <stdio.h>

//输入整数a，若s = 1+1/2+1/3+…+1/n，求当s大于a的n的最小值。

/*
样例输入
3
样例输出
s=3.0199,n=11
*/

double s(int n) {
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += 1.0 / i;
	}
	return ans;
}

int main() {
	int n = 1;
	double a;
	scanf("%lf", &a);
	while (s(n++) <= a);
	printf("s=%.4lf,n=%d", s(n - 1), n - 1);
}