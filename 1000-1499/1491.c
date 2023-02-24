#include <stdio.h>

int main() {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 9; i++) {
        int k = i;
        for (int j = i; j <= 9; j++) {
            arr[j] < arr[k] && (k = j);
        }
        if (k != i) {
            int temp = arr[k];
            arr[k] = arr[i];
            arr[i] = temp;
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
}