#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2) {
    return *(int*)p1 - *(int*)p2;
}

int main() {
    int vis[100] = {0};
    int ar[100];
    int idx = 0;
    int temp;
    while (~scanf("%d", &temp)) {
        if (!vis[temp]) {
            ar[idx++] = temp;
            vis[temp] = 1;
        }
    }
    qsort(ar, idx, sizeof(int), cmp);
    for (int i = 0; i < idx; i++) {
        printf(i == idx - 1 ? "%d\n" : "%d ", ar[i]);
    }
}