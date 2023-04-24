#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct bucket {
   int length;
   int data[N];
} *Bucket;

Bucket createBucket() {
    Bucket b = (Bucket)malloc(sizeof(struct bucket));
    b->length = 0;
    return b;
}

Bucket addToBucket(Bucket b, int val) {
    b->data[b->length++] = val;
    return b;
}

// 初始化所有桶
void initAllBuckets(Bucket ar[]) {
    for (int i = 0; i <= 10; i++) {
        if (ar[i] != NULL) free(ar[i]);
        ar[i] = createBucket();
    }
}

// 计算整型的位数
int getTotalDigit(int num) {
    int ans = 0;
    while (num > 0) {
        ans++;
        num /= 10;
    }
    return ans;
}

// 获取某数值的指定位数的数字
int getSingleNum(int num, int digit) {
    for (int i = 1; i < digit; i++) {
        num /= 10;
    }
    return num % 10;
}

int max(int a, int b) {
    return a < b ? b : a;
}

int main() {
    int ar[N];
    int temp;
    Bucket buckets[11] = {NULL}; // 准备十一个桶进行基数排序
    while (~scanf("%d", &temp)) {
        int tot = 0;
        int maxDigit = 0;
        // 存数组,并统计出最大位数
        while (temp != -1) {
            ar[tot++] = temp;
            maxDigit = max(maxDigit, getTotalDigit(temp));
            scanf("%d", &temp);
        }
        // 根据最大位数，按低位优先的顺序
        for (int digit = 1; digit <= maxDigit + 1; digit++) {
            // 收集
            if (digit > 1) {
                int idx = 0;
                for (int i = 0; i <= 10; i++) {
                    for (int j = 0; j < buckets[i]->length; j++) {
                        ar[idx++] = buckets[i]->data[j];
                        printf(idx == tot ? "%d\n" : "%d ", ar[idx - 1]);
                    }
                }
            }
            // 分配
            if (digit <= maxDigit) {
                initAllBuckets(buckets);
                for (int i = 0; i < tot; i++) {
                    addToBucket(buckets[getSingleNum(ar[i], digit)], ar[i]);
                }
            }
        }
    }
}