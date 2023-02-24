#include <stdio.h>
#include <stdlib.h>

void sort(int** p, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= n - 2 - i; j++) {
            if (*(*p + j) > *(*p + j + 1)) {
                temp = *(*p + j);
                *(*p + j) = *(*p + j + 1);
                *(*p + j + 1) = temp;
            }
        }
    }
}

int main() {
    int length;
    int* arr = (int*)malloc(sizeof(int) * 100);
    int** p = &arr;
    while (~scanf("%d", &length)) {
        if (!length) {
            break;
        }
        for (int i = 0; i < length; i++) {
            scanf("%d", *p + i);
        }
        sort(p, length);
        for (int i = 0; i < length; i++) {
            printf("%d ", *(*p + i));
        }
        putchar('\n');
    }
    free(arr);
}