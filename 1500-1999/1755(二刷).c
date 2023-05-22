#include <stdio.h>

int main() {
    int length = 0;
    int ar[100];
    while (1) {
        scanf("%d", &ar[length]);
        if (ar[length] == 0) break;
        length++;
    }
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j <= length - 2 - i; j++) {
            if (ar[j] < 0 && ar[j + 1] > 0) {
                int t = ar[j + 1];
                ar[j + 1] = ar[j];
                ar[j] = t;
            }
        }
    }
    for (int i = 0; i < length; i++) {
        printf("%d ", ar[i]);
    }
}