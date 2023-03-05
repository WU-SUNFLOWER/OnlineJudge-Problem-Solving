#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int size;
    int ar[110] = {1 << 30};
    int pos_min1 = 0;  // 最小元素的下标
    int pos_min2 = 0;  // 次小元素的下标
    scanf("%d", &size);
    for (int i = 1; i <= size * size; i++) {
        scanf("%d", &ar[i]);
        // 如果当前元素比最小元素还小
        if (ar[i] < ar[pos_min1]) {
            // 将最小元素贬为次小元素
            pos_min2 = pos_min1;
            // 更新最小元素
            pos_min1 = i;
        }
        // 如果当前元素比最小元素大，但比次小元素小
        else if (ar[i] < ar[pos_min2]) {
            pos_min2 = i;
        }
    }
    // 将矩阵左上角元素与矩阵中最小的元素交换
    swap(&ar[1], &ar[pos_min1]);
    // 如果次小元素的pos正好为1，要重新记录
    pos_min2 == 1 && (pos_min2 = pos_min1);
    // 将矩阵右下角元素与矩阵中次小的元素交换
    swap(&ar[size * size], &ar[pos_min2]);
    // 输出
    for (int i = 1; i <= size * size; i++) {
        printf(i % size ? "%d " : "%d\n", ar[i]);
    }
}