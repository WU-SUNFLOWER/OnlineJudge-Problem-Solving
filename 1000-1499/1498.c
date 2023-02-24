#include <stdio.h>
#include <stdlib.h>

int* createIntArray(int length) {
	return (int*)malloc(sizeof(int) * length);
}

int main() {
	int range = 3;
	int* matrix = createIntArray(range * range);
	int* ansMatrix = createIntArray(range * range);
	for (int i = 0; i < range * range; i++) {
		scanf("%d", &matrix[i]);
	}
	for (int i = 0; i < range * range; i++) {
		int col = i % range;
		int row = i / range;
		printf("%d ", matrix[col * range + row]);
		if (col == range - 1) {
			printf("\n");
		}
	}
}