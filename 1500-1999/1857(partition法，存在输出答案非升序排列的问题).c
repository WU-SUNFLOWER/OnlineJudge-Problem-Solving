#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int median_three(int ar[], int start, int end) {
    int mid = (start + end) >> 1;
    // 确保ar[start] <= ar[mid] <= ar[end]
    if (ar[start] > ar[mid]) {
        swap(&ar[start], &ar[mid]);
    }
    if (ar[mid] > ar[end]) {
        swap(&ar[mid], &ar[end]);
    }
    if (ar[start] > ar[mid]) {
        swap(&ar[start], &ar[end]);
    }
    // 将mid交换到end-1的位置，作为pivot返回
    swap(&ar[mid], &ar[end-1]);
    return ar[end - 1];
}

// 对数组指定范围进行划分，并返回划分边界的下标
// 处理的数组下标范围为[start, end]
int partition(int ar[], int start, int end) {
    int pivot = median_three(ar, start, end);
    int i = start;
    int j = end - 1;
    while (1) {
        while (ar[++i] < pivot);
        while (ar[--j] > pivot);
        if (i < j) {
            swap(&ar[i], &ar[j]);
        } else {
            break;
        }
    }
    swap(&ar[i], &ar[end - 1]);
    return i;
}

int cmp(const void* p1, const void* p2) {
    return *(int*)p1 - *(int*)p2;
}

int main() {
    int k;
    int len;
    int ar[100];
    scanf("%d %d", &len, &k);
    for (int i = 0; i < len; i++) {
        scanf("%d", &ar[i]);
    }
    int left = 0;
    int right = len - 1;
    int index = partition(ar, 0, len - 1);
    while (1) {
        // 第一种情况：如果划分边界正好落在k处，则求解完毕
        if (index + 1 == k) {
            break;
        }
        // 第二种情况：如果划分边界若在k左侧，说明划分少了
        else if (index + 1 < k) {
            left = index;
            index = partition(ar, left, right);
        }
        // 第二种情况：如果划分边界若在k右侧，说明划分多了
        else if (index + 1 > k) {
            right = index;
            index = partition(ar, left, right);
        }
    }
    qsort(ar, k, sizeof(int), cmp);
    for (int i = 0; i < k; i++) {
        printf(i == k - 1 ? "%d\n" : "%d ", ar[i]);
    }
}