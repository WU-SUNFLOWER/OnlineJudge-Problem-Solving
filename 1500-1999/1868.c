#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2) {
    int v1 = *(int*)p1;
    int v2 = *(int*)p2;
    if (v1 % 2 == 1 && v2 % 2 == 0) {
        return -1;
    } 
    else if (v1 % 2 == 0 && v2 % 2 == 1) {
        return 1;
    }
    else if (v1 % 2 == 1) {
        return v2 - v1;
    }
    else if (v1 % 2 == 0) {
        return v1 - v2;
    }
}

int main() {
    int temp;
    int idx = 0;
    int ar[100];
    while (~scanf("%d", &temp)) {
        ar[idx++] = temp;
    };
    qsort(ar, idx, sizeof(int), cmp);
    for (int i = 0; i < idx; i++) {
        printf(i == idx - 1 ? "%d\n" : "%d ", ar[i]);
    }
}