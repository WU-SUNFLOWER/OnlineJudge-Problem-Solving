#include <stdio.h>

/*
如果一个数列中的某一段（至少有两个元素）的各元素值均相同，则称之为等值数列段。
等值数列段中元素的个数叫做等值数列段的长度。

输入
由N个元素组成的整数数列A（其中N<=50)
首先输入一个数字，表示这个数列有几个数字组成，然后回车
依次输入这个数列每个数字(0-9)，输入一个数字，回车一下。


输出
A中长度最大的所有等值数列段的始末位置，以The longest equal number list is from打头
如果没有等值数列段，则输出 No equal number list.
说明：始末位置是指数组下标，即0表示第一个元素。 如果有多个同等长度的等值数列，只输出第一个等值数列的起始位置。 当在一个LIST中出现两个等长的连续串的时候，我们的答案应该是第一个等长串。
*/

/*
输入：
5
1
1
1
2
2
输出：
The longest equal number list is from 0 to 2.
*/

int main() {
	int length;
	int arr[50];
	int ansLen = 0;
	int ansLeftBordar;
	int ansRightBordar;
	int tempLen = 1;
	int tempLeftBordar = 0;
	int tempRightBordar;
	scanf("%d", &length);
	for (int i = 0; i < length; i++) {
		scanf("%d", &arr[i]);
		if (i == 0) {
			continue;
		}
		if (arr[i] == arr[i - 1]) {
			tempLen++;
			tempRightBordar = i;
			if (i == length - 1 && tempLen > ansLen) {
				ansLen = tempLen;
				ansLeftBordar = tempLeftBordar;
				ansRightBordar = tempRightBordar;
			}
		}
		else {
			if (tempLen > ansLen) {
				ansLen = tempLen;
				ansLeftBordar = tempLeftBordar;
				ansRightBordar = tempRightBordar;
			}
			tempLen = 1;
			tempLeftBordar = i;
		}
	}
	if (ansLen > 1) {
		printf("The longest equal number list is from %d to %d.\n", ansLeftBordar, ansRightBordar);
	} else {
		printf("No equal number list.");
	}
}