#include <stdio.h>
#include <stdlib.h>
/*
 ����ÿƥ���к㶨���ٶȣ������ٶ�
 �����һ�����ٶ�С�����ȵ��յ㣨û�����⣡���������������ƽ�֡����˭Ӯ�ĳ�������һ��(������һ��)��
 ˭����Ӯ��(����û��Ӯ��)��Ԩ����N(1��N��1000)ƥ��μӱ��������ֵ����������Ԩ���������һ��������֪��
 ���е�����ٶȡ�����������Ԥ��һ���ⳡ����֮ս�Ľ��������Ԩ���ܷ�Ӯ�ñ�����
*/

/*
���룺
5
2 3 3 4 5 ���ҷ���
1 2 3 4 5 �����֣�
4
2 2 1 2
2 2 3 1
0
�����
YES
NO
*/

//ð������
//k����1���򣬴���-1��ʾ����
int* BubbleSort(int* arr, int startPoint, int endPoint, int k) {
	int temp;
	for (int i = 0; i <= endPoint - startPoint; i++) {
		for (int j = startPoint; j < endPoint - i; j++) {
			if (arr[j] * k > arr[j + 1] * k) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return arr;
}

int getMinInArray(int* arr, int length) {
	int ans = arr[0];
	for (int i = 1; i < length; i++) {
		arr[i] < ans && (ans = arr[i]);
	}
	return ans;
}

int getMaxInArray(int* arr, int length) {
	int ans = arr[0];
	for (int i = 1; i < length; i++) {
		arr[i] > ans && (ans = arr[i]);
	}
	return ans;
}

int* createIntArray(int length) {
	int* arr = (int*)malloc(sizeof(int) * length);
	return arr;
}

int main() {
	int N;
	while (scanf("%d", &N) != EOF) {
		if (N <= 0) {
			break;
		}
		int startPoint = N / 2;
		int* SpeedArr_Self = createIntArray(N);
		int* SpeedArr_Opponent = createIntArray(N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &SpeedArr_Self[i]);
		}
		for (int i = 0; i < N; i++) {
			scanf("%d", &SpeedArr_Opponent[i]);
		}
		if (getMinInArray(SpeedArr_Self, N) > getMaxInArray(SpeedArr_Opponent, N)) {
			printf("YES\n");
		}
		else if (getMaxInArray(SpeedArr_Self, N) < getMinInArray(SpeedArr_Opponent, N)) {
			printf("NO\n");
		}
		else {
			BubbleSort(SpeedArr_Self, 0, N - 1, 1);
			BubbleSort(SpeedArr_Opponent, 0, N - 1, -1);
			BubbleSort(SpeedArr_Opponent, startPoint, N - 1, 1);
			while (startPoint < N) {
				if (SpeedArr_Self[startPoint] <= SpeedArr_Opponent[startPoint]) {
					break;	
				} else {
					startPoint++;
				}
			}
			printf(startPoint < N ? "NO\n" : "YES\n");			
		}
	}
	return 0;
}