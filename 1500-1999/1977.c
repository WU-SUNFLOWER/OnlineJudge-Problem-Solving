#include <stdio.h>

/*
һ���100m�߶��������£�ÿ����غ�����ԭ�߶ȵ�һ�룬�����¡�
�����ڵ�n�����ʱ�������������ף���n�η�����ߣ���С�������5λ��

����һ��������n��
���С�򾭹���·�̺͵�n�η����ĸ߶ȡ�
*/

/*
���룺
10
�����
������299.60938��
��n�η���0.09766��
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
	printf("������%.5lf��\n��n�η���%.5lf��", distance, height / 2);
}