#include <stdio.h>

int main() {
    int a;
    int b;
    int n;
    scanf("%d", &n);
    while (scanf("%d %d", &a, &b) != EOF) {
        printf("%d\n", a + b);
    }
}