#include <stdio.h>
#include <math.h>

/*
考虑到传入的数据可能足够大，如果开char数组逐个存字符再逆序，程序会直接崩掉！
*/

int main() {
	int num;
	scanf("%d", &num);
	if (num == 0) {
		printf("0");
	}
	while (num > 0) {
		printf("%d", num % 10);
		num /= 10;
	}
}