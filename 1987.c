#include <stdio.h>

/*
����һ��������m��1��m��6����m�׷���A�е�Ԫ�أ����жԽ����ϵ�Ԫ�ز���Ϊ0����
��A��ÿһ��Ԫ�س������еĶԽ�Ԫ�أ���Ⲣ����µķ���Ҫ��ÿ��Ԫ�ر�����λС����

����:
3
2 4 6
6 3 9
10 15 5
���:
1.00 2.00 3.00
2.00 1.00 3.00
2.00 3.00 1.00

���룺
2
2 6
8 2
���
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