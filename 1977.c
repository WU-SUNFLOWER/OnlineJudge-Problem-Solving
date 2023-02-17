#include <stdio.h>

/*
一球从100m高度自由落下，每次落地后反跳回原高度的一半，再落下。
求它在第n次落地时，共经过多少米？第n次反弹多高？（小数点后保留5位）

输入一个正整数n。
输出小球经过的路程和第n次反弹的高度。
*/

/*
输入：
10
输出：
共经过299.60938米
第n次反弹0.09766米
*/

int main() {
	int time = 1;
	int n;
	double height = 100;
	double distance = height;
	scanf("%d", &n);
	while (time <= n - 1) {
		height /= 2;
		distance += 2 * height;
		time++;
	}
	printf("共经过%.5lf米\n第n次反弹%.5lf米", distance, height / 2);
}