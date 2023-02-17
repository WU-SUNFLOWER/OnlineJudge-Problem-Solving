#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n;
        int m;
        int a;
        int b;
        scanf("%d %d", &n, &m);
        for (int j = 0; j < m; j++) {
            scanf("%d %d", &a, &b);
        }
        printf("%d\n", n - m);
    }
}