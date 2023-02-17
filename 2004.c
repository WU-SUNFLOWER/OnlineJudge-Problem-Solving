#include <stdio.h>

int main() {
    int step = 0;
    int sum = 0;
    int num;
    scanf("%d", &num);
    while (num > 0) {
        step++;
        sum += num % 10;
        num /= 10;
    }
    printf("%d %d", sum, step);
}