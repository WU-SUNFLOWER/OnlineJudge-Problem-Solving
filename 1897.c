#include <stdio.h>

int main() {
	int num;
	int idx = 0;
	int ans = 0;
	scanf("%d", &num);
	while (num > 0) {
		if (idx++ == 2) {
			ans = num % 2;
			break;
		}
		num /= 2;
	}
	printf("%d\n", ans);
}