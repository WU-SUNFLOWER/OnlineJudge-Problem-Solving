#include <stdio.h>

/*
��һ���Ѿ��ź��������:int a[11]={1,4,6,9,13,16,19,28,40,100}��

������һ������Ҫ��ԭ������Ĺ��ɽ�����������У�������µ����顣����Ҫ���ٶ���ʹ���µ����顣
*/

/*
���룺
10
�����
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