#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// 对数组指定范围进行划分，并返回划分边界的下标
// 处理的数组下标范围为[start, end)
int partition(int ar[], int start, int end) {
    int tail = end - 1;
    int pivot = ar[tail];
    int i = start;
    int j = tail - 1;
    while (1) {
        while (ar[i] < pivot && i < j) {
            i++;
        }
        while (ar[j] > pivot && i < j) {
            j--;
        }
        if (i < j) {
            swap(&ar[i], &ar[j]);
        } else {
            break;
        }
    }
    swap(&ar[i], &ar[tail]);
    return i;
}

int main() {
    int k;
    int len;
    int ar[100];
    scanf("%d %d", &len, &k);
    for (int i = 0; i < len; i++) {
        scanf("%d", &ar[i]);
    }
    int index = partition(ar, 0, len);
    while (1) {
        // 第一种情况：如果划分边界正好落在k处，则求解完毕
        if (index + 1 == k) {
            break;
        }
        // 第二种情况：如果划分边界若在k左侧，说明划分少了
        else if (index + 1 < k) {
            index = partition(ar, index + 1, len);
        }
        // 第二种情况：如果划分边界若在k右侧，说明划分多了
        else if (index + 1 > k) {
            index = partition(ar, 0, index);
        }
    }
    for (int i = 0; i < k; i++) {
        printf(i == k - 1 ? "%d\n" : "%d ", ar[i]);
    }
}