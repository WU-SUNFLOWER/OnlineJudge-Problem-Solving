#include <stdio.h>

int n;
int target;
int nums[100];
int ans[100];

void dfs(int cnt, int target, int start, int n) {
    // 已经搜索到的长度已经满足题目要求，直接输出
    if (cnt == target) {
        for (int k = 1; k <= cnt; k++) {
            printf(k == cnt ? "%d\n" : "%d ", ans[k]);
        }
        return;
    }
    // 剪枝：剩余可供搜索的区间无法满足题目要求，放弃继续搜索
    if (cnt + n - start + 1 < target) {
        return;
    }
    // 正常进行搜索
    for (int k = start; k <= n; k++) {
        int num = nums[k];
        ans[cnt + 1] = num;
        dfs(cnt + 1, target, num + 1, n);
    }
}

int main() {
    scanf("k=%d", &target);
    while (~scanf("%d", &nums[n + 1])) {
        n++;
    };
    dfs(0, target, 1, n);
}