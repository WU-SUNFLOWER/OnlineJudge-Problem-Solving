#include <stdio.h>
#include <math.h>

/*
��m~n��m��10��n��10000��֮��Ļ�����������ν��������������������ǻ�������������
��������Ҫ�ж�ĳ�����Ƿ��ǻ��ģ����ж��Ƿ���������
����ǻ����������򱣴��������У�����6λ��������ÿ�����5����
*/

/*
���룺m n
�����m~n֮��Ļ���������ÿ����ռ6λ��ÿ�������5��
*/

/*
���룺
10 10000

�����
    11   101   131   151   181
   191   313   353   373   383
   727   757   787   797   919
   929
*/

int isSymNumber(int num) {
	int tempNum = num;
	int reserveNum = 0;
	while (tempNum > 0) {
		reserveNum = reserveNum * 10 + tempNum % 10;
		tempNum /= 10;
	}
	return num == reserveNum;
}

int isPrimeNumber(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int m;
	int n;
	int idx1 = 0;
	int arr[9990];
	scanf("%d %d", &m, &n);
	//Ѱ�ҷ������������
	for (int num = m; num <= n; num++) {
		if (isSymNumber(num) && isPrimeNumber(num)) {
			arr[idx1++] = num;
		}
	}
	//������
	for (int idx2 = 0; idx2 < idx1; idx2++) {
		printf("%6d", arr[idx2]);
		if ((idx2 + 1) % 5 == 0) {
			printf("\n");
		}
	}
}