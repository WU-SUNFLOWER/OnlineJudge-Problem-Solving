#include <stdio.h>

int main() {
    int arr[10];
    for (int i = 0; i <= 9; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 9; i >= 0; i--) {
        printf(i == 0 ? "%d\n" : "%d ", arr[i]);
    }
}