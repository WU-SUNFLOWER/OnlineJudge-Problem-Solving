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
    // ��������
    while (~scanf("%d", &ar[idx].val) && ar[idx].val != -1) {
        ar[idx].order = idx;
        idx++;
    }
    // ���泤��
    length = idx;
    // ʵ���״ο���
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
    // �����������ݣ�ȷ�����˳�򲻱�
    qsort(&ar[0], low, sizeof(ElementType), &cmpByOrder);
    qsort(&ar[low + 1], length -low - 1, sizeof(ElementType), &cmpByOrder);
    // ���
    printArr(ar, length);
}