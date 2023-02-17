#include <stdio.h>

int main() {
    int dataNum;
    int arr[100];
    while (scanf("%d", &dataNum) != EOF) {
        int ans = 1;
        int temp;
        for (int i = 0; i < dataNum; i++) {
            scanf("%d", &temp);
            if (temp % 2 == 1) {
                ans *= temp;
            }
        }
        printf("%d\n", ans);
    }
}