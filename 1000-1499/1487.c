#include <stdio.h>

int main() {
	int time = 1;
	int n;
	double height;
	scanf("%lf %d", &height, &n);
	double distance = height;
	while (time <= n - 1) {
		height /= 2;
		distance += 2 * height;
		time++;
	}
    printf("%.2lf %.2lf", height / 2, distance);
}