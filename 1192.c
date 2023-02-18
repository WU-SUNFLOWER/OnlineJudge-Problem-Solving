#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ar[50000];

int cmp(const void* p1, const void* p2) {
    return (*(int*)p1) - (*(int*)p2);
}

int main() {
    int length;
    while (~scanf("%d", &length)) {
        for (int i = 0; i < length; i++) {
            scanf("%d", &ar[i]);
        }
        qsort(ar, length, sizeof(int), cmp);
        int oddSum = 0;
        int evenSum = 0;
        for (int i = 1; i <= length; i++) {
            if (i % 2) {
                oddSum += ar[i - 1];
            } else {
                evenSum += ar[i - 1];
            }
        }
        printf("%d\n", abs(oddSum - evenSum));
    }
}