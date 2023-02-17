#include <stdio.h>
#include <math.h>

/*
��ѧ�ϰ����Ϊ2�����������������������������������������ټ���3��5,5��7,11��13.�����Ѿ�֪����
С��100000����Ȼ������1224����������
С��1000000����Ȼ������8164����������
С��33000000����Ȼ������152892����������
Ŀǰ��֪�������������������ǣ�1000000009649��1000000009651
��ô�����������᲻���������ԣ�
�����������û�н�������������дһ��������������ѧ�ҽ�������⣬������ѧ�������һ����Χ�������÷�Χ�����е�����������
*/

/*
���룺
1 13
�����
3 5
5 7
11 13
*/

int isPrimeNumber(unsigned int num) {
	if (num == 1) {
		return 0;
	}
	for (int x = 2; x <= sqrt(num); x++) {
		if (num % x == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	unsigned int leftBordar;
	unsigned int rightBordar;
	scanf("%u %u", &leftBordar, &rightBordar);
	for (; leftBordar <= rightBordar - 2; leftBordar++) {
		if (isPrimeNumber(leftBordar) && isPrimeNumber(leftBordar + 2)) {
			printf("%d %d\n", leftBordar, leftBordar + 2);
		}
	}
}