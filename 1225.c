#include <stdio.h>
#include <math.h>

int PrimeNumberRecord[201];

int isPrimeNumber(int num) {
    if (PrimeNumberRecord[num] != -1) {
        return PrimeNumberRecord[num];
    }
    for (int x = 2; x <= sqrt(num); x++) {
        if (num % x == 0) {
            PrimeNumberRecord[num] = 0;
            return 0;
        }
    }
    PrimeNumberRecord[num] = 1;
    return 1;
}

int main() {
    int n;
    for (int i = 0; i <= 200; i++) {
        PrimeNumberRecord[i] = -1;
    }
    while (scanf("%d", &n) != EOF && n != 0) {
        int count = 0;
        for (int x = 3; x <= n / 3; x++) {
            for (int y = x; y < n - x; y++) {
                int z = n - x - y;
                if (z >= y && isPrimeNumber(x) && isPrimeNumber(y) && isPrimeNumber(z)) {
                    count++;
                }
            }
        }
        if (count) {
            printf("%d\n", count);
        } else {
            printf("Error\n");
        }
    }
}