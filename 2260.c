#include <stdio.h>

int check(int num) {
    int last = 0;
    while (num > 0) {
        int cur = num % 10;
        if (cur == 4 || last == 8 && cur == 3) {
            return 0;
        }
        last = cur;
        num /= 10;
    }
    return 1;
}

int main() {
    int left;
    int right;
    while (~scanf("%d %d", &left, &right)) {
        int ans = 0;
        if (left == 0 && right == 0) {
            break;
        }
        for (; left <= right; left++) {
            check(left) && (ans++);
        }
        printf("%d\n", ans);
    }
}