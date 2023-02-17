#include <stdio.h>
#include <math.h>

/*
ĳ����ΪK(n)�Ķ���Ϊ��

1                     n=1

k(n)=   ��k(n-1)/5��-3        nΪż��

k(n-1)^2��3          nΪ����

���д�ݹ麯��������еĵ�x��k(x),С�������3λС����
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