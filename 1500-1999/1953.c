#include <stdio.h>
#include <math.h>

int main() {
    for (int i = (int)sqrt(1000); i <= (int)sqrt(9999); i++) {
        int num = i * i;
        if (num / 1000 == num / 100 % 10 && num / 10 % 10 == num % 10) {
            printf("%d", num);
            break;
        }
    }
}