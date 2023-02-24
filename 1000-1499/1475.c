#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int a;
    int b;
    int c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", max(max(a, b), c));
}