#include <stdio.h>
#include <math.h>

/*
输入一个正整数m（1≤m≤6）和m阶方阵A中的元素，如果A是上三角矩阵，则输出“YES”，否则输出“NO”
（上三角矩阵即主对角线以下的元素都为0的矩阵，主对角线为从矩阵的左上角至右下角的连线）。
*/

/*
输入：
3
1 2 3
0 1 2
0 0 1
输出：
YES
*/

/*
输入：
4
1 2 3 4
0 1 1 3
0 0 1 2
1 0 0 1
输出：
NO
*/

int main() {
	int range;
	int flag = 1;
	scanf("%d", &range);
	for (int i = 1; i <= range * range; i++) {
		int ele;
		int col = (i - 1) % range + 1;
		int row = ceil(i / (double)range);
		scanf("%d", &ele);
		if (col < row && ele != 0) {
			flag = 0;
		}
	}
	printf(flag ? "YES\n" : "NO\n");
	return 0;
}