#include <stdio.h>

int main() {
	int x;
	int ans = 0;
	scanf("%d", &x);
	while (x > 0) {
		int y = x % 10;
		y % 2 == 0 && (ans += y);
		x /= 10;
	}
	printf("%d", ans);
}