#include <stdio.h>

/*
��ν����������˳���������Ϊ��ͬ����������292��10301��Ϊ��������

���˲²⣺����һ��ʮ��������n(n��Ϊ������)�������޴Ρ�˳����͡������ɵõ�һ����������
����ġ�˳����͡��������ǰ�һ����������������ӡ�
���磬����n=69����(1)69+96=165 (2)165+561=726 
(3)726+627=1353 (4) 1353+ 3531=4884(������)��

����Ƴ�����֤ĳһ����[x1,x2]�е�ÿһ����n�Ƿ�Ϊ��������
�����ǣ���չʾnͨ�����ϡ�˳����͡�����ת��Ϊ�������Ĳ�������
����n=69ʱ��4�β����õ������������69(4)���õ��Ļ�����4884��
�������15����δ��ת��Ϊ������������ֹ���������n(?)�������������ܲ�����²⡣
*/

/*
���룺
������������(��һ��С�ڵڶ���)��

�����
����������Ĳ���������Ӧ�Ļ�������
*/

/*
���룺
86 90
�����
86(3):1111
87(4):4884
88(0):88
89(?):
90(1):99
*/

int reverseNumber(int num) {
	int ans = 0;
	while (num > 0) {
		ans = ans * 10 + num % 10;
		num /= 10;
	}
	return ans;
}

int isSymNumber(int num) {
	return reverseNumber(num) == num;
}

int main() {
	int leftBorder;
	int rightBorder;
	scanf("%d %d", &leftBorder, &rightBorder);
	for (int x = leftBorder; x <= rightBorder; x++) {
		int curX = x;
		int step = 0;
		int giveup = 0;
		while (!isSymNumber(curX)) {
			if (step > 15) {
				giveup = 1;
				break;
			}
			curX += reverseNumber(curX);
			step++;
		}
		if (giveup) {
			printf("%d(?):\n", x);
		} else {
			printf("%d(%d):%d\n", x, step, curX);
		}
	}
}