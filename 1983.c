#include <stdio.h>

/*
有一个已经排好序的数组:int a[11]={1,4,6,9,13,16,19,28,40,100}；

今输入一个数，要求按原来排序的规律将其插入数组中，并输出新的数组。此题要求不再定义使用新的数组。
*/

/*
输入：
10
输出：
1
4
6
9
10
13
16
19
28
40
100
*/

int main() {
	int newNumber;
	int targetPoint = 0;
	int a[11]={1, 4, 6, 9, 13, 16, 19, 28, 40, 100};
	scanf("%d", &newNumber);
	for (; targetPoint <= 9; targetPoint++) {
		if (a[targetPoint] >= newNumber) {
			for (int i = 10; i > targetPoint; i--) {
				a[i] = a[i - 1];
			}
			a[targetPoint] = newNumber;
			break;
		}
	}
	for (int i = 0; i < 11; i++) {
		printf("%d\n", a[i]);
	}
}