#include <stdio.h>

int main() {
	int a;
	int b;
	int temp;
	int multip;
	scanf("%d %d", &a, &b);
	multip = a * b;
	if (a > b) {
		temp = a;
		a = b;
		b = temp;
	}
	while (b > 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	printf("%d %d", a, multip / a);
}