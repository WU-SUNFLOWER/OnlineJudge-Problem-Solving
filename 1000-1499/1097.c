#include <stdio.h>
#include <stdlib.h>

//����N*N�ľ����������ת�þ��󡣾����ת�ò��������Ѿ������Ԫ�ر�Ϊ��Ԫ�ء���Ԫ�ر�Ϊ��Ԫ�صĹ��̡�

//�����һ��Ϊ����N��������һ��N*N�ľ���

/*
���룺
2
1 2
1 2

�����
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