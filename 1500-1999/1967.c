#include <stdio.h>

/*
�ⲻ��ʽ n < 1+1/2+1/3+��+1/m <n+1������������n�Ӽ������룬mҲΪ����������ȡ�ķ�Χ������

����
����������n��ֵ��

���
���������m�Ľ����䡣

��������
5
�������
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