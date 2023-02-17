#include <stdio.h>

int main() {
	int a;
	int b;
	int c;
	int d;
	int num;
	scanf("%d", &num);
	a = num / 1000;
	b = num / 100 % 10;
	c = num / 10 % 10;
	d = num % 10;
	printf("%d\n", c + d + a + b);
}