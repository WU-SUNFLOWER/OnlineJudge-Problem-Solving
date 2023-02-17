#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int arr[10];
    int min;
    int max;
    int minPos = 0;
    int maxPos = 0;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        if (i == 0) {
            min = max = arr[i];
        } else {
            arr[i] < min && (min = arr[i], minPos = i);
            arr[i] > max && (max = arr[i], maxPos = i);
        }
    }
    //交换最小的数和第一个数
    maxPos == 0 && (maxPos = minPos);
    swap(&arr[0], &arr[minPos]);
    //交换最大的数和最后一个数
    swap(&arr[9], &arr[maxPos]);
    //输出
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
}