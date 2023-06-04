#include <stdio.h>
#define N 100

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// 将堆中的值小的元素向下调整
void PercDown(int ar[], int node, int n) {
    int parent = node;
    int value = ar[node];
    int child_l = parent * 2 + 1;
    int child_r = parent * 2 + 2;
    // 将parent下沉，将child_l和child_r中值大的节点上浮
    while (child_l < n) {
        // 默认选取左孩子与父节点交换
        int target = child_l;
        // 如果右孩子存在且值比左孩子大，那么考虑将右孩子与父节点交换
        if (child_r < n && ar[child_r] > ar[child_l]) {
            target = child_r;
        }
        // 确认有必要再进行交换，否则的话说明parent下沉结束，需要退出循环
        if (ar[target] > value) {
            ar[parent] = ar[target];
            parent = target;
            child_l = parent * 2 + 1;
            child_r = parent * 2 + 2;            
        } else {
            break;
        }
    }
    ar[parent] = value;
}

// 构建最大堆
void InitHeap(int ar[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        PercDown(ar, i, n);
    }
}

int main() {
    int n;
    int ar[N];
    while (~scanf("%d", &n)) {
        // 读取数据
        for (int i = 0; i < n; i++) {
            scanf("%d", ar + i);
        }
        // 建造最大堆
        InitHeap(ar, n);
        // 实现堆排序: 对堆进行n-1次调整即可完成排序
        int tot = n;
        for (int i = 0; i < tot; i++) {
            for (int j = 0; j < tot; j++) {
                printf(j == tot - 1 ? "%d\n" : "%d ", ar[j]);
            }
            swap(&ar[0], &ar[tot - i - 1]);
            PercDown(ar, 0, --n);
        }
    }
}