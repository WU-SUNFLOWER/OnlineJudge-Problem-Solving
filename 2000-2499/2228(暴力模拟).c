#include <stdio.h>
#define N 1000

int ar[N];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int tot;
    while (~scanf("%d", &tot)) {
        int temp;
        for (int i = 1; i <= tot; i++) {
            scanf("%d", &ar[i]);
        }
        int ans = 0;
        for (int i = 1; i <= tot; i++) {
            if (ar[i] != i) {
                for (int j = 1; j <= tot; j++) {
                    if (ar[j] == i) {
                        swap(&ar[i], &ar[j]);
                        ans++;
                        break;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
}