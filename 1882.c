#include <stdio.h>
#include <math.h>

int main() {
    int n;
    while (~scanf("%d", &n)) {
        n = pow(n, 3);
        int a = n / 100 % 10;
        int b = n / 10 % 10;
        int c = n % 10;
        if (a != 0) {
            printf("%d", a);
        }
        if (b == 0 && a != 0 || b != 0) {
            printf("%d", b);
        }
        printf("%d\n", c);        
    }

}