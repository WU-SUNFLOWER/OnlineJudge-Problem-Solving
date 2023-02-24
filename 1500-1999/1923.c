#include <stdio.h>

int main() {
	double a;
	double b;
	char myOperator;
	while (scanf("%lf%c%lf", &a, &myOperator, &b) != EOF) {
		switch (myOperator) {
			case '+':
				printf("%.2lf\n", a + b);
				break;
			case '-':
				printf("%.2lf\n", a - b);
				break;
			case '*':
				printf("%.2lf\n", a * b);
				break;
			case '/':
				printf("%.2lf\n", a / b);
				break;
			default:
				printf("Unknown operator!\n");
		}
	}
}