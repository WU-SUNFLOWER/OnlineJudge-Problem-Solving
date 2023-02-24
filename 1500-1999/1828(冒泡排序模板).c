#include <stdio.h>

int main() {
	int n;
	int idx;
	int arr[100];
	while (scanf("%d", &n) != EOF) {
		for (idx = 0; idx < n; idx++) {
			scanf("%d", &arr[idx]);
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = n; j >= 1 + i; j--) {
				if (arr[j] < 0) {
					int temp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = temp;
				}
			}
		}
		for (idx = 0; idx < n; idx++) {
			printf(idx == n - 1 ? "%d\n" : "%d ", arr[idx]);
		}
	}
}