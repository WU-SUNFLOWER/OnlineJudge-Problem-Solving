#include <stdio.h>

/*
所谓回文数，即顺序与逆序均为相同的整数。如292、10301均为回文数。

有人猜测：任意一个十进制整数n(n不为回文数)，经有限次“顺逆求和”操作可得到一个回文数。
这里的“顺逆求和”操作就是把一个数与其逆序数相加。
例如，对于n=69，有(1)69+96=165 (2)165+561=726 
(3)726+627=1353 (4) 1353+ 3531=4884(回文数)。

试设计程序，验证某一区间[x1,x2]中的每一个数n是否为回文数，
若不是，请展示n通过以上“顺逆求和”操作转化为回文数的步骤数。
例如n=69时经4次操作得到回文数，输出69(4)及得到的回文数4884。
如果超过15步还未能转化为回文数，则终止操作，输出n(?)，表明该数可能不满足猜测。
*/

/*
输入：
输入两个整数(第一个小于第二个)。

输出：
输出回文数的步骤数及相应的回文数。
*/

/*
输入：
86 90
输出：
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