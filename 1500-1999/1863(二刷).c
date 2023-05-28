#include <stdio.h>

void solve(int n, int last, int ans[], int idx_ans) {
    if (n == 0) {
        for (int i = 0; i < idx_ans; i++) {
            printf(i == idx_ans - 1 ? "%d\n\n" : "%d ", ans[i]);
        }
        return;
    }
    if (n > last * (last - 1) / 2) {
        return;
    }
    for (int i = last - 1; i >= 1; i--) {
        ans[idx_ans] = i;
        solve(n - i, i, ans, idx_ans + 1);
    }
}

int main() {
    int n;
    int ans[100];
    scanf("%d", &n);
    solve(n, n + 1, ans, 0);
}