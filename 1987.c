#include <stdio.h>

/*
输入一个正整数m（1≤m≤6）和m阶方阵A中的元素（其中对角线上的元素不能为0），
以A的每一行元素除以其中的对角元素，求解并输出新的方阵，要求每个元素保留两位小数。

输入:
3
2 4 6
6 3 9
10 15 5
输出:
1.00 2.00 3.00
2.00 1.00 3.00
2.00 3.00 1.00

输入：
2
2 6
8 2
输出
1.00 3.00
4.00 1.00
*/

int main() {
	int range;
	double matrix[36];
	double DiagonalArr[6];
	scanf("%d", &range);
	for (int i = 0; i < range * range; i++) {
		scanf("%lf", &matrix[i]);
		if (i % range == i / range) {
			DiagonalArr[i / range] = matrix[i];
		}
	}
	for (int i = 0; i < range * range; i++) {
		matrix[i] = matrix[i] / DiagonalArr[i / range];
		if (i % range == range - 1) {
			printf("%.2lf\n", matrix[i]);
		} else {
			printf("%.2lf ", matrix[i]);
		}
	}
}