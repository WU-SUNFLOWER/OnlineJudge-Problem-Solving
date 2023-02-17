#include <stdio.h>
#include <stdlib.h>

//给你一组数(未排序)，请你写设计一个程序：求出里面个数最多的数（可以不连续出现），
//并输出这个数的长度。例如：给你的数是：1、 2、 3、 3、 4、 4、 5、 5、 5 、6,
//其中只有6组数：1, 2, 3-3, 4-4, 5-5-5 and 6. 最长的是5那组，长度为3。所以输出3。

//第一行为整数t((1 ≤ t ≤ 10))，表示有n组测试数据。
//每组测试数据包括两行，第一行位数组的长度n (1 ≤ n ≤ 10000)。
//第二行为n个整数，所有整数Mi的范围都是(1 ≤ Mi ≤ 2^32)

//输入：
//1
//10
//1 2 3 3 4 4 5 5 5 6
//输出：
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