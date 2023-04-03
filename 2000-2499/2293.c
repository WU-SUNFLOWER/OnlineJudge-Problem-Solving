#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int Graph[20][20];

bool vis[20];

void dfs(int cur, int n) {
    vis[cur] = true;
    for (int i = 0; i < n; i++) {
        if (Graph[cur][i] && !vis[i]) {
            dfs(i, n);
        }
    }
}

bool check(int n) {
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {
    int n;  // 节点总数
    while (~scanf("%d", &n)) {
        int val;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &Graph[i][j]);
            }
        }
        bool ans = true;
        for (int i = 0; i < n; i++) {
            memset(vis, false, sizeof(vis));
            dfs(i, n);
            if (!check(n)) {
                ans = false;
                break;
            }
        }
        puts(ans ? "YES" : "NO");
    }
}