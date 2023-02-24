#include <stdio.h>

int main() {
	int n;
	int f[1001];
	f[1] = 1;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		f[i] = (f[i - 1] + 3) % i + 1;
	}
	printf("%d\n", f[n]);
}