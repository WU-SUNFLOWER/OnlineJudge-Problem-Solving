#include <stdio.h>
#include <stdlib.h>

//����n��ʵ���������ݹ�һ���������롣
//��һ����ָ����ÿһ����x������ʽ (x-min)/(max-min)����ת����
//����minΪ�������е���С�ߣ�maxΪ����ߡ�

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