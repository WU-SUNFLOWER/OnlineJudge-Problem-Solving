#include <stdio.h>

int main() {
    int temp;
    int range;
    int ans;
    int ansCol = 1;
    int ansRow = 1;
    scanf("%d", &range);
    scanf("%d", &ans);
    for (int i = 2; i <= range * range; i++) {
        scanf("%d", &temp);
        if (temp > ans) {
            ans = temp;
            ansCol = (i - 1) % range + 1;
            ansRow = i / range;            
        }
    }
    printf("%d %d %d", ans, ansRow, ansCol);
}