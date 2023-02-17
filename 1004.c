#include <stdio.h>
#include <stdlib.h>
/*
 假设每匹马都有恒定的速度，所以速度
 大的马一定比速度小的马先到终点（没有意外！！）。不允许出现平局。最后谁赢的场数多于一半(不包括一半)，
 谁就是赢家(可能没有赢家)。渊子有N(1≤N≤1000)匹马参加比赛。对手的马的数量与渊子马的数量一样，并且知道
 所有的马的速度。聪明的你来预测一下这场世纪之战的结果，看看渊子能否赢得比赛。
*/

/*
输入：
5
2 3 3 4 5 （我方）
1 2 3 4 5 （对手）
4
2 2 1 2
2 2 3 1
0
输出：
YES
NO
*/

//冒泡排序
//k传入1升序，传入-1表示降序
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