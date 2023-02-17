#include <stdio.h>

int main() {
    double num;
    while (~scanf("%lf", &num)) {
        printf("%.2lf\n\n", num);
    }
}