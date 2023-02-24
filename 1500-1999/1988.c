#include <stdio.h>
#include <math.h>

/*
��������������m��n��m��1��n��10000������С�������m~n(����m,n)֮�������������
�����������Ӻ�����������ȵ�����Ҫ���岢���ú���factorsum(number)�����Ĺ����Ƿ���number�����Ӻ͡�
���磺factorsum(12)�ķ���ֵ��16����1+2+3+4+6��

���룺
10 500
�����
28 496

���룺
1 20
�����
6
*/

int factorsum(int num) {
	int sum = 1;
	//����1������ֻ�б��������ӺͲ��ܰ������Լ�������������⴦��
	if (num == 1) {
		return 0;
	}
	for (int x = 2; x <= sqrt(num); x++) { 
		if (num % x == 0) {
			sum += (x == num / x ? x : (x + num / x));
		}
	}
	return sum;
}

int main() {
	int m;
	int n;
	int idx = 0;
	int ansArr[10000];
	scanf("%d %d", &m, &n);
	for (; m <= n; m++) {
		if (factorsum(m) == m) {
			ansArr[idx++] = m;
		}
	}
	for (int i = 0; i <= idx - 1; i++) {
		printf(i < idx - 1 ? "%d " : "%d", ansArr[i]);
	}
}