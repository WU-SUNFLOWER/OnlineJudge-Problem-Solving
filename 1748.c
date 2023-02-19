#include <stdio.h>

int main() {
    int n;
    int ar[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (ar[i] != (i + 1) * (i + 1) - ar[i - 1]) {
            ans = 0;
            break;
        }
    }
    printf(ans ? "true" : "false");
}