#include <stdio.h>

int main() {
	int x;
	int y;
	while (1) {
		scanf("%d %d", &x, &y);
		if (x == 0 && y == 0) {
			break;
		}
		printf("%d\n\n", x + y);
	}
}