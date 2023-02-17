#include <stdio.h>

/*
解不等式 n < 1+1/2+1/3+…+1/m <n+1，其中正整数n从键盘输入，m也为正整数，可取的范围待定。

输入
输入正整数n的值。

输出
输出正整数m的解区间。

样例输入
5
样例输出
83<=m<=226
*/

int main() {
	double n;
	double m = 1;
	double sum = 0;
	int leftBordar = -1;
	int rightBordar = -1;
	scanf("%lf", &n);
	while (1) {
		sum += 1/m;
		if (n < sum && leftBordar < 0) {
			leftBordar = (int)m;
		}
		if (sum >= n + 1) {
			rightBordar = (int)(m - 1);
			break;
		}
		m++;
	}
	printf("%d<=m<=%d\n", leftBordar, rightBordar);
}