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
    int tot = 0;
    int ans[100];
    int idx = 0;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++) {
        int cnt = getCount(i);
        if (cnt > 0) {
            tot += cnt;
            ans[idx++] = i;
        }
    }
    printf("%d\n", tot);
    for (int i = idx - 1; i >= 0; i--) {
        printf(i == 0 ? "%d\n" : "%d ", ans[i]);
    }
}