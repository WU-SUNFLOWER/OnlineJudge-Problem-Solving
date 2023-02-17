#include <stdio.h>
#include <math.h>

int main() {
	int count = 0;
	int ans[100];
	for (int i = 100; i <= 200; i++) {
		int flag = 1;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			count++;
			ans[count - 1] = i;
		}
	}
	printf("%d\n", count);
	for (int i = 0; i < count; i++) {
		printf(i == count - 1 ? "%d" : "%d ", ans[i]);
	}
}