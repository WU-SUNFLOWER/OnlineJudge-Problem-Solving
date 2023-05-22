#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void dfs(int ar[], int n, int cur, int k) {
    if (cur >= k) {
        for (int i = 0; i < k; i++) {
            printf(i == k - 1 ? "%d\n" : "%d ", ar[i]);
        }        
        return;
    }
    for (int i = cur; i < n; i++) {
        if (cur == 0 || ar[i] > ar[cur - 1]) {
            swap(&ar[i], &ar[cur]);
            dfs(ar, n, cur + 1, k);
            swap(&ar[i], &ar[cur]);
        }
    }
}

int main() {
    int ar[100];
    int k;
    int n = 0;
    scanf("k=%d", &k);
    while (~scanf("%d", &ar[n])) {
        n++;
    }
    dfs(ar, n, 0, k);
}