#include <stdio.h>

//输入1个四位数，将其加密后输出。
//方法是将该数每一位上的数字加9，然后除以10取余，
//做为该位上的新数字，最后将第1位和第3位上的数字互换，第2位和第4位上的数字互换，组成加密后的新数。

int main() {
	int a;
	int b;
	int c;
	int d;
	int num;
	scanf("%d", &num);
	a = (num / 1000 + 9) % 10;
	b = (num / 100 % 10 + 9) % 10;
	c = (num / 10 % 10 + 9) % 10;
	d = (num % 10 + 9) % 10;
	printf("%d%d%d%d\n", c, d, a, b);
}