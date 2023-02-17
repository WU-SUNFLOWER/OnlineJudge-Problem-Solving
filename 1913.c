#include <stdio.h>

/*
输入2个整数time1和time2，表示火车的出发时间和到达时间，计算并输出旅途时间。
有效的时间范围是0000到2359，不需要考虑出发时间晚于到达时间的情况。

输入:
712   1411（出发时间是7：12，到达时间是14：11）

输出:
6 hrs 59 mins
*/

int main() {
	int time1;
	int time2;
	int deltaTime;
	scanf("%d %d", &time1, &time2);
	time1 = (time1 / 100) * 60 + (time1 % 100);
	time2 = (time2 / 100) * 60 + (time2 % 100);
	deltaTime = time2 - time1;
	printf("%d hrs %d mins\n", deltaTime / 60, deltaTime % 60);
}