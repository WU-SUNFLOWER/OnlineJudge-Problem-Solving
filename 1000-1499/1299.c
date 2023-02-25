#include <stdio.h>
#define N 11000

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int ar[], int start, int end) {
    int pivot = ar[end - 1];
    int i = start;
    int j = end - 1;
    while (i < j) {
        while (i < j && ar[i] <= pivot) i++;
        while (i < j && ar[j] >= pivot) j--;
        if (i < j) {
            swap(&ar[i], &ar[j]);
        }
    }
    swap(&ar[i], &ar[end - 1]);
    return i;
}

int ar[N];
int cnt[N] = {0};

int main() {
    int k;
    int length;
    int idx = 0;
    scanf("%d %d", &length, &k);
    // 构建非重复数组
    for (int i = 0; i < length; i++) {
        int num;
        scanf("%d", &num);
        if (cnt[num] == 0) {
            ar[idx++] = num;
        }
        cnt[num]++;
    }
    // 套二分模板
    int curK;
    int start = 0;
    int end = idx;
    while (1) {
        curK = partition(ar, start, end);
        if (curK == k - 1) {
            printf("%d %d\n", ar[curK], cnt[ar[curK]]);
            break;
        } 
        // 如果划分的数偏少了
        else if (curK < k - 1) {
            start = curK + 1;
            end = idx;
        }
        // 如果划分的数偏多了
        else {
            start = 0;
            end = curK;
        }
    }
}