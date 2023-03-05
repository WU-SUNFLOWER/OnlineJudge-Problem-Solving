#include <stdio.h>
#include <stdlib.h>

typedef struct ele {
    int val;
    int id;
} Ele;

int cmp(const void* p1, const void* p2) {
    Ele* v1 = (Ele*)p1;
    Ele* v2 = (Ele*)p2;
    if (v1->val < 0 && v2->val > 0) {
        return 1;
    }
    else if (v1->val > 0 && v2->val < 0) {
        return -1;
    }
    else {
        return v1->id - v2->id;
    }
}

int main() {
    Ele ar[100];
    int temp;
    int idx = 0;
    while (~scanf("%d", &temp) && temp) {
        ar[idx].val = temp;
        ar[idx].id = idx;
        idx++;
    }
    qsort(ar, idx, sizeof(Ele), cmp);
    for (int i = 0; i < idx; i++) {
        printf("%d ", ar[i]);
    }
}