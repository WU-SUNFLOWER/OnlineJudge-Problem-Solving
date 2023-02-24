#include <stdio.h>

const double PI = 3.1415926;

int main() {
    double catLength;
    double r;
    while (~scanf("%lf %lf", &catLength, &r)) {
        if (catLength >= 2 * PI * r) {
            printf("敢不敢换个大点的碗\n");
        } else {
            printf("你才到碗里去\n");
        }
    }
}