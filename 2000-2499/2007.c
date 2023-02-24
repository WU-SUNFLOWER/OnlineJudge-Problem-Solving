#include <stdio.h>
#include <string.h>

int main() {
    int num;
    scanf("%d", &num);
    int a = (num / 1000 + 5) % 10;
    int b = (num / 100 % 10 + 5) % 10;
    int c = (num / 10 % 10 + 5) % 10;
    int d = (num % 10 + 5) % 10;
    printf("%d%d%d%d", d, c, b, a);
}