#include <stdio.h>
#include <stdlib.h>

int main() {
    int length;
    int arr[100];
    scanf("%d", &length);
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j <= length - 2 - i; j++) {
            if (
                arr[j] % 2 == 1 && arr[j + 1] % 2 == 0 || 
                arr[j] % 2 == arr[j + 1] % 2 && arr[j] > arr[j + 1]
            ) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < length; i++) {
        printf(i == length - 1 ? "%d\n" : "%d ", arr[i]);
    }
}