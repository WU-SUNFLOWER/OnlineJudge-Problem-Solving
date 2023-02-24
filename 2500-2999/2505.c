#include <stdio.h>
#include <stdlib.h>

//输入n个实数，将数据归一化，并输入。
//归一化是指，对每一个数x，按公式 (x-min)/(max-min)进行转换，
//其中min为这组数中的最小者，max为最大者。

int main() {
	int n;
	double min;
	double max;
	double arr[50];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &arr[i]);
		if (i == 0) {
			min = max = arr[i];
		} else {
			arr[i] < min && (min = arr[i]);
			arr[i] > max && (max = arr[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%.3lf", (arr[i] - min) / (max - min));
		if (i != n - 1) {
			printf(" ");
		}
	}
}