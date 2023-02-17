#include <stdio.h>
#include <math.h>

//求任何一个两位整数3次方的最后三位数字构成的数
//输入一个大于等于10，小于等于99的整数
//输出由整数3次方的最后三个数字构成的数

//输入：11
//输出：331

int main() {
	int a;
	int b;
	int c;
	int num;
	//初始化num
	scanf("%d", &num);
	num = pow(num, 3);
	a = num / 100 % 10;
	b = num / 10 % 10;
	c = num % 10;
	printf("%d%d%d", a, b, c);
}