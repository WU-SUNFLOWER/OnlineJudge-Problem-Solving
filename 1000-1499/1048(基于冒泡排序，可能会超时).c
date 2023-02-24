#include <stdio.h>
#include <stdlib.h>

//����һ����(δ����)������д���һ���������������������������Բ��������֣���
//�����������ĳ��ȡ����磺��������ǣ�1�� 2�� 3�� 3�� 4�� 4�� 5�� 5�� 5 ��6,
//����ֻ��6������1, 2, 3-3, 4-4, 5-5-5 and 6. �����5���飬����Ϊ3���������3��

//��һ��Ϊ����t((1 �� t �� 10))����ʾ��n��������ݡ�
//ÿ��������ݰ������У���һ��λ����ĳ���n (1 �� n �� 10000)��
//�ڶ���Ϊn����������������Mi�ķ�Χ����(1 �� Mi �� 2^32)

//���룺
//1
//10
//1 2 3 3 4 4 5 5 5 6
//�����
//3

int* createIntArray(int length) {
	return (int*)malloc(sizeof(int) * length);
}

int* BubbleSort(int* arr, int startPoint, int endPoint, int k) {
	int temp;
    int lastPoint = endPoint;
    while (1) {
        int newLastPoint = startPoint;
		for (int j = startPoint; j < lastPoint; j++) {
			if (arr[j] * k > arr[j + 1] * k) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
                newLastPoint = j;
			}
		}
        if (newLastPoint == startPoint) {
            break;
        } else {
            lastPoint = newLastPoint;
        }
    }
	return arr;
}

int getMax(int x, int y) {
	return x > y ? x : y;
}

int main() {
	int TestNum;
	scanf("%d", &TestNum);
	while ((TestNum--) > 0) {
		int length;
		int ans = 1;
		int curAns = 1;
		scanf("%d", &length);
		int* MyArray = createIntArray(length);
		for (int i = 0; i < length; i++) {
			scanf("%d", &MyArray[i]);
		}
		BubbleSort(MyArray, 0, length - 1, 1);
		for (int i = 1; i < length; i++) {
			if (MyArray[i] == MyArray[i - 1]) {
				curAns++;
			} else {	
				curAns = 1;
			}
			ans = getMax(ans, curAns);
		}
		free(MyArray);
		printf("%d\n", ans);
	}
}