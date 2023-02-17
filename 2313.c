#include <stdio.h>

int main() {
    int n;
    int ansNum;
    int bucket[1000] = {0};
    for (int i = 0; i < 10; i++) {
        scanf("%d", &n);
        bucket[n] += 1;
        i == 0 && (ansNum = n);
    }
    for (int i = 0; i < 1000; i++) {
        if (bucket[i] > bucket[ansNum]) {
            ansNum = i;
        }
    }
    printf("%d\n%d\n", ansNum, bucket[ansNum]);
}