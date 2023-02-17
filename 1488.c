#include <stdio.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);
	printf("%.0lf\n", 3 * pow(2, n - 1) - 2);
}