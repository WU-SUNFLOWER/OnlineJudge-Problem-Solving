#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
*/

int* createIntArray(int length) {
	int* arr = (int*)malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++) {
		arr[i] = 0;
	}
	return arr;
}

int main() {
	int n;
	int* dataUp = createIntArray(15);
	int* dataDown = createIntArray(15);
	dataUp[0] = 1;
	scanf("%d", &n);
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
		dataDown = createIntArray(15);
	}
}