#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int order;
} ElementType;

void swap(ElementType* p, ElementType* q) {
    ElementType t = *p;
    *p = *q;
    *q = t;
}

void printArr(ElementType ar[], int length) {
    for (int i = 0; i < length; i++) {
        printf(i == length - 1 ? "%d\n" : "%d ", ar[i].val);
    }
}

int cmpByOrder(const void* p1, const void* p2) {
    return ((ElementType*)p1)->order - ((ElementType*)p2)->order;
}

int main() {
    int idx = 0;
    int length = 0;
    ElementType ar[100];
    // 读入数据
    while (~scanf("%d", &ar[idx].val) && ar[idx].val != -1) {
        ar[idx].order = idx;
        idx++;
    }
    // 保存长度
    length = idx;
    // 实现首次快排
    int low = 0;
    int high = length - 2;
    int pivot = ar[length - 1].val;
    while (1) {
        while (ar[low].val < pivot) {
            low++;
        }
        while (ar[high].val > pivot) {
            high--;
        }
        if (low < high) {
            swap(&ar[low], &ar[high]);
        } else {
            break;
        }
    }
    swap(&ar[low], &ar[length - 1]);
    // 整理两侧数据，确保相对顺序不变
    qsort(&ar[0], low, sizeof(ElementType), &cmpByOrder);
    qsort(&ar[low + 1], length -low - 1, sizeof(ElementType), &cmpByOrder);
    // 输出
    printArr(ar, length);
}