#include <stdio.h>
#include <stdlib.h>
#define N 11000

int cmp(const void* a, const void* b) {
    return *((int*)a) - *((int*)b);
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
    qsort(ar, idx, sizeof(int), cmp);
    printf("%d %d\n", ar[k - 1], cnt[ar[k - 1]]);
}