#include <stdio.h>
#include <math.h>

int main() {
    int num;
    int sqrt_num;
    scanf("%d", &num);
    sqrt_num = num * num;
    while (num > 0) {
        if (num % 10 != sqrt_num % 10) {
            printf("不是守形数");
            return 0;
        }
        num /= 10;
        sqrt_num /= 10;
    }
    printf("是守形数");
    return 0;
}