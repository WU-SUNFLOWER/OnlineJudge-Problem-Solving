#include <stdio.h>

int getCount(int num) {
    int ans = 0;
    while (num > 0) {
        num % 10 == 1 && (ans++);
        num /= 10;
    }
    return ans;
}

int main() {
    int num;
    int ans = 0;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++) {
        ans += getCount(i);
    }
    printf("%d", ans);
}