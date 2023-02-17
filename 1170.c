#include <stdio.h>
#include <math.h>

int main() {
	int x;
	int y;
	int z;
	double average;
	scanf("%d %d %d", &x, &y, &z);
	average = (x + y + z) / 3.0;
	printf("%d %d %.2lf", x + y + z, x * y * z, average);
}