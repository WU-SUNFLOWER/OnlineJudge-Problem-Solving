#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int idx;
} ElementType;

int cmp1(const void* p1, const void* p2) {
    return ((ElementType*)p1)->value - ((ElementType*)p2)->value;
}

int cmp2(const void* p1, const void* p2) {
    return ((ElementType*)p1)->idx - ((ElementType*)p2)->idx;
}

int main() {
    int idx1 = 0;
    int idx2 = 0;
    int temp;
    ElementType ar1[100];
    ElementType ar2[100];
    while (~scanf("%d", &temp) && temp != -1) {
        ar1[idx1].idx = idx1;
        ar1[idx1++].value = temp;
    }
    while (~scanf("%d", &temp) && temp != -1) {
        ar2[idx2].idx = idx2;
        ar2[idx2++].value = temp;
    }
    qsort(ar1, idx1, sizeof(ElementType), cmp1);
    qsort(ar2, idx2, sizeof(ElementType), cmp1);
    int i = 0;
    int j = 0;
    int ans[100];
    while (i < idx1 && j < idx2) {
        if (ar1[i].value == ar2[j].value) {
            ar1[i].value = -1;
            i++;
            j++;
        } 
        else if (ar1[i].value > ar2[j].value) {
            j++;
        }
        else {
            i++;
        }
    }
    qsort(ar1, idx1, sizeof(ElementType), cmp2);
    int cnt = 0;
    for (int i = 0; i < idx1; i++) {
        if (ar1[i].value != -1) {
            cnt++;
            printf("%d ", ar1[i].value);
        }
    }
    printf("\n%d\n", cnt);
}