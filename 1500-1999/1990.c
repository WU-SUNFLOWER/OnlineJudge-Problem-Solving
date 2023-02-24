#include <stdio.h>

int zh(m, n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return m;
	}
	if (2 * n > m) {
		return zh(m, m - n);
	} else {
		return zh(m - 1, n - 1) + zh(m - 1, n);
	}
}

int main() {
	int m;
	int n;
	scanf("%d %d", &m, &n);
	printf("%d\n", zh(m, n));
}