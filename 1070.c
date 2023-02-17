#include <stdio.h>

int main() {
    int length;
    int arr[100];
    while (scanf("%d", &length) != EOF) {
        int i;
        for (i = 0; i < length; i++) {
            scanf("%d", &arr[i]);
        }
        for (i = 0; i < length - 1; i++) {
            int a = arr[i];
            int b = arr[i + 1];
            int multip =  a * b;
            while (b > 0) {
                int Old_a = a;
                a = b;
                b = Old_a % b;
            }
            arr[i + 1] = multip / a;
        }
        printf("%d\n", arr[i]);
    }
}