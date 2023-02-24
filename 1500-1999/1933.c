#include <stdio.h>
#include <math.h>

int main() {
	int num;
	int step;
	int ans = 0;
	scanf("%d %d", &num, &step);
	for (int i = 0; i < step; i++) {
		int s = 0;
		for (int j = 0; j <= i; j++) {
			s += num * pow(10, j);
		}
		ans += s;
	}
	printf("%d", ans);
}