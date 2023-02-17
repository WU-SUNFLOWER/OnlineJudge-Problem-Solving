#include <stdio.h>
#include <math.h>

int isOddNumber(int num) {
    return num % 2;
}

int main() {
    int idx = -1;
    int ans[10];
    int tempNum;
    for (int i = 1; i <= 10; i++) {
        scanf("%d", &tempNum);
        isOddNumber(tempNum) && (ans[++idx] = tempNum);
    }
    for (int i = 0; i <= idx; i++) {
        printf(i == idx ? "%d\n" : "%d ", ans[i]);
    }
}