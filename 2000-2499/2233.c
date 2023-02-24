#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void qsort(int arr[], int start, int end) {
    //中位数法确定pivot
    int pivot;
    int mid = (start + end) >> 1;
    if (arr[start] > arr[mid]) {
        swap(&arr[start], &arr[mid]);
    }
    if (arr[start] > arr[end]) {
        swap(&arr[start], &arr[end]);
    }
    if (arr[mid] > arr[end]) {
        swap(&arr[end], &arr[mid]);
    }
    //如果排序区间长度小于等于3，则该区间已经有序，递归结束
    if (end - start + 1 <= 3) {
        return;
    }
    pivot = arr[mid];
    //为便于后续子集的划分，对pivot元素进行隐匿
    swap(&arr[end - 1], &arr[mid]);
    //子区间划分
    int i = start;
    int j = end - 1;
    while (1) {
        while (arr[++i] < pivot);
        while (arr[--j] > pivot);
        if (i < j) {
            swap(&arr[i], &arr[j]);
        } else {
            break;
        }
    }
    //恢复被隐匿的pivot元素
    swap(&arr[i], &arr[end - 1]);
    //递归，进行下一轮排序
    qsort(arr, start, i - 1);
    qsort(arr, i + 1, end);
}

int main() {
    int length;
    int arr[100];
    scanf("%d", &length);
    while (~scanf("%d", &length)) {
        for (int i = 0; i < length; i++) {
            scanf("%d", &arr[i]);
        }
        qsort(arr, 0, length - 1);
        for (int i = 0; i < length; i++) {
            printf(i == length - 1 ? "%d\n" : "%d ", arr[i]);
        }
    }
}