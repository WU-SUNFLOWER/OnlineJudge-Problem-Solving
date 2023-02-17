#include <stdio.h>
#include <stdlib.h>

//输入N*N的矩阵，输出它的转置矩阵。矩阵的转置操作，即把矩阵的行元素变为列元素、列元素变为行元素的过程。

//输入第一行为整数N。接着是一个N*N的矩阵。

/*
输入：
2
1 2
1 2

输出：
1 1
2 2
*/

int* createIntArray(int length) {
	return (int*)malloc(sizeof(int) * length);
}

int main() {
	int range;
	scanf("%d", &range);
	int* matrix = createIntArray(range * range);
	int* ansMatrix = createIntArray(range * range);
	for (int i = 0; i < range * range; i++) {
		scanf("%d", &matrix[i]);
	}
	for (int i = 0; i < range * range; i++) {
		int col = i % range;
		int row = i / range;
		printf("%d", matrix[col * range + row]);
		if (col == range - 1) {
			printf("\n");
		} else {
			printf(" ");
		}
	}
}