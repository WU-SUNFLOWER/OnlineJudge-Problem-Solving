#include <stdio.h>

int main() {
    int ans = 0;
    int range;
    scanf("%d", &range);
    for (int i = 0; i < range * range; i++) {
        int temp;
        scanf("%d", &temp);
        if (i % range <= i / range) {
            ans += temp;
        }
    }
    printf("%d\n", ans);
}