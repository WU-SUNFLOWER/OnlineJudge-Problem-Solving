#include <stdio.h>

void QuickSort(double* arr, int startPoint, int endPoint, int k) {
	int i = startPoint;
	int j = endPoint;
	int refNum = arr[startPoint];
	if (startPoint < endPoint) {
		while (i < j) {
			while (i < j && arr[j] * k >= refNum * k) {
				j--;
			}
			while (i < j && arr[i] * k <= refNum * k) {
				i++;
			}
			if (i < j) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		arr[startPoint] = arr[i];
		arr[i] = refNum;
		QuickSort(arr, startPoint, i - 1, k);
		QuickSort(arr, i + 1, endPoint, k);
	}
}

int main() {
	double scores[10];
	double sum = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%lf", &scores[i]);
	}
	QuickSort(&scores[0], 0, 9, 1);
	for (int i = 1; i <= 8; i++) {
		sum += scores[i];
	}
	printf("%.2lf\n", sum / 8);
}