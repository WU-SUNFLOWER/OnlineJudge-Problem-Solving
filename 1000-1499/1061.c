#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int* createIntArray(int length) {
	int* arr = (int*)malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++) {
		arr[i] = 0;
	}
	return arr;
}

void printYhsj(int n) {
	int* dataUp = createIntArray(30);
	int* dataDown = createIntArray(30);
	dataUp[0] = 1;
	for (int row = 1; row <= n; row++) {
		for (int col = 0; col < row; col++) {
			if (col == 0 || col == row - 1) {
				dataDown[col] = 1;
			} else {
				dataDown[col] = dataUp[col - 1] + dataUp[col];
			}
			printf(col == row - 1 ? "%d" : "%d ", dataDown[col]);
		}
		printf("\n");
		free(dataUp);
		dataUp = dataDown;
		dataDown = createIntArray(30);
	}
	free(dataDown);
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) {
			break;
		}
		printYhsj(n);
		printf("\n");
	}
}