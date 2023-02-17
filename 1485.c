#include <stdio.h>

int getSubSum(int num, int* arr) {
    int sum = 0;
    int idx = 0;
    for (int i = 1; i < num; i++) {
        num % i == 0 && (sum += i, arr[idx++] = i);
    }
    arr[idx] = -1;
    return sum;
}

int main() {
    int n;
    int subArr[100];
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        if (getSubSum(i, &subArr[0]) == i) {
            printf("%d its factors are ", i);
            for (int j = 0; subArr[j] != -1; j++) {
                printf("%d ", subArr[j]);
            }
            printf("\n");
        }
    }
}