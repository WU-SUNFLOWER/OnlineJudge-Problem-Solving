#include <stdio.h>

int n;
int flag[100];

void dfs(int tot, int range) {
    if (tot == 0) {
        int ans[100];
        int ansLen = 0;
        for (int i = n; i >= 1; i--) {
            if (flag[i]) {
                ans[ansLen++] = i;
            }
        }
        for (int i = 0; i < ansLen; i++) {
            printf(i == ansLen - 1 ? "%d\n\n" : "%d ", ans[i]);
        }
        return;
    }
    if (tot < 0 || range <= 0) {
        return;
    }
    // 把当前的最大值放入背包的情况
    flag[range] = 1;
    dfs(tot - range, range - 1);
    flag[range] = 0;
    // 不把当前的最大值放入背包的情况
    dfs(tot, range - 1);
}

int main() {
    scanf("%d", &n);
    dfs(n, n);
}