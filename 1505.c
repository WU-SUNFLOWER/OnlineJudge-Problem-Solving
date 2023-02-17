#include <stdio.h>
#define mod(a, b) a % b

int main() {
    int a;
    int b;
    scanf("%d %d", &a, &b);
    printf("%d", mod(a, b));
}