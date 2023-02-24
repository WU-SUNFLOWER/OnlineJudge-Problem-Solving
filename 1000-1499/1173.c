#include <stdio.h>

void swap(int* a, int* b) {
    int p = *a;
    *a = *b;
    *b = p;
}

int main() {
    int length;
    int arr[10];
    int minIdx = 0;
    int maxIdx = 0;
    scanf("%d", &length);
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
        arr[i] < arr[minIdx] && (minIdx = i);
        arr[i] > arr[maxIdx] && (maxIdx = i);
    }
    //处理特殊情况
    if (maxIdx == 0) {
        maxIdx = minIdx;
    }
    swap(&arr[0], &arr[minIdx]);
    swap(&arr[length - 1], &arr[maxIdx]);
    for (int i = 0; i < length; i++) {
        printf(i == length - 1 ? "%d\n" : "%d ", arr[i]);
    }
}