#include <stdio.h>


int main() {
    int a, b, mul;
    while (~scanf("%d %d", &a, &b)) {
        mul = a * b;
        // gcd(a, b) = gcd(b, a % b) = ... gcd(ans, 0)
        while (b > 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        printf("%d\n", mul / a);        
    }

}