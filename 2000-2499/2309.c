#include <stdio.h>
#include <math.h>

/*
某数列为K(n)的定义为：

1                     n=1

k(n)=   （k(n-1)/5）-3        n为偶数

k(n-1)^2×3          n为奇数

请编写递归函数求该数列的第x项k(x),小数点后保留3位小数。
*/

double k(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n % 2 == 0) {
        return (k(n - 1) / 5) - 3;
    }
    else {
        return pow(k(n - 1), 2) * 3;
    }
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        if (n < 1) {
            printf("input data error!\n");
        } else {
            printf("k(%d)=%.3lf\n", n, k(n));
        }
    }
}