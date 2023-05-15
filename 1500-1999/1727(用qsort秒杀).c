#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2) {
    return *(int*)p1 - *(int*)p2;
}

int vis[1000];

int main() {
    int tot1, tot2;
    int tot = 0;
    int ar[100];
    scanf("%d", &tot1);
    for (int i = 0; i < tot1; i++) {
        int temp;
        scanf("%d", &temp);
        if (!vis[temp]) {
            vis[temp] = 1;
            ar[tot++] = temp;
        }
    }
    scanf("%d", &tot2);
    for (int i = 0; i < tot2; i++) {
        int temp;
        scanf("%d", &temp);
        if (!vis[temp]) {
            vis[temp] = 1;
            ar[tot++] = temp;
        }
    }
    qsort(ar, tot, sizeof(int), cmp);
    for (int i = 0; i < tot; i++) {
        printf("%d ", ar[i]);
    }
}