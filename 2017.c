#include <stdio.h>
#include <stdlib.h>

/*
����2n���ƣ����Ϊ1,2,3,...,n,n+1,...,2n����Ҳ��������Ƶ�˳��
һ��ϴ���ǰ����б�Ϊn+1(i=0),  1(i=1),  n+2(i=2),  2(i=3),  n+3(i=4),  3,  n+4,  4, ...,  2n,  n��
����֤������������������n���������ھ���m��������ϴ�ƺ���������»ص���ʼ��˳��

��̶���2n(n�Ӽ�������)���ƽ���ϴ�ƣ�������µõ���ʼ˳���ϴ�ƴ���m��ֵ��

����
����������n����2n���ơ�

���
���ϴ�ƴ���m��ֵ��
*/

/*
���룺50
�������100��ϴ�ƻص���ʼ״̬
*/

int isConfused(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		if (arr[i] != i + 1) {
			return 1;
		}
	}
	return 0;
}

int* createIntArray(int length) {
	return (int*)malloc(sizeof(int) * length);
}

int main() {
	int n;
	int ans = 0;
	int length;
	int* arr;
	int* newArr;
	scanf("%d", &n);
	length = 2 * n;
	arr = createIntArray(length);
	for (int i = 0; i < length; i++) {
		arr[i] = i + 1;
	}
	do {
		newArr = createIntArray(length);
		for (int i = 0; i < length; i++) {
			if (i % 2 == 0) {
				newArr[i] = arr[n + i / 2];
			} else {
				newArr[i] = arr[(i + 1) / 2 - 1];
			}
		}
		free(arr);
		arr = newArr;
		ans++;
	} while (isConfused(arr, length));
	printf("��%d��ϴ�ƻص���ʼ״̬\n", ans);
}