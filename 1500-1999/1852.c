#include <stdio.h>

int n = 3;
int target = 2;
int nums[] = {0, 1, 2, 3, 4};
int ans[10];

void dfs(int cnt, int target, int start, int n) {
    if (cnt == target) {
        for (int k = 1; k <= cnt; k++) {
            printf(k == cnt ? "%d\n" : "%d ", ans[k]);
        }
        return;
    }
    for (int k = start; k <= n; k++) {
        int num = nums[k];
        ans[cnt + 1] = num;
        dfs(cnt + 1, target, num + 1, n);
    }
}

int main() {
    dfs(0, target, 1, n);
}