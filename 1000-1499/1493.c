#include <stdio.h>

int main() {
    int num;
    int arr[10];
    for (int i = 0; i < 9; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &num);
    for (int i = 0; i < 10; i++) {
        if (num <= arr[i] || i == 9) {
            for (int j = 8; j >= i; j--) {
                arr[j + 1] = arr[j];
            }
            arr[i] = num;
            break;
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
}