#include <stdio.h>
#include <stdlib.h>

/*
给你2n张牌，编号为1,2,3,...,n,n+1,...,2n，这也是最初的牌的顺序。
一次洗牌是把序列变为n+1(i=0),  1(i=1),  n+2(i=2),  2(i=3),  n+3(i=4),  3,  n+4,  4, ...,  2n,  n。
可以证明，对于任意正整数n，都可以在经过m次这样的洗牌后，这幅牌重新回到初始的顺序。

编程对于2n(n从键盘输入)张牌进行洗牌，求出重新得到初始顺序的洗牌次数m的值。

输入
输入正整数n，即2n张牌。

输出
输出洗牌次数m的值。
*/

/*
输入：50
输出：经100次洗牌回到初始状态
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
	printf("经%d次洗牌回到初始状态\n", ans);
}