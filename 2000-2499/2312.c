#include <stdio.h>

void Bubble_sort(int arr[], int size) {
	int tem;
	for (int i = 0; i < size - 1;i ++) {
		int count = 0;
		for (int j = 0; j < size - 1 - i; j++)	{
			if (arr[j] < arr[j+1]) {
				tem = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tem;
				count = 1;
			}
		}
		if (count == 0)	{
			break;	
		}
	}
}

int main() {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    Bubble_sort(arr, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
}