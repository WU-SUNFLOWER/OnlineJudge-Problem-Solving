#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define N 100

int Graph[N][N];

bool vis[N];

int path[N];

bool dfs(int cur, int end, int dist, int num_node, int idx_ans, int* ans) {
    // 找到终点，结束搜索
    if (cur == end) {
        return dist > *ans ? (*ans = dist, path[idx_ans * 2] = 0, true) : false;
    }
    // 标记当前节点为已访问
    vis[cur] = true;
    bool flag = false;
    for (int i = 1; i <= num_node; i++) {
        if (Graph[cur][i] && !vis[i]) {
            if (dfs(i, end, dist + Graph[cur][i], num_node, idx_ans + 1, ans)) {
                flag = true;
                path[idx_ans * 2] = cur;
                path[idx_ans * 2 + 1] = i;
            }
        }
    }
    vis[cur] = false;
    return flag;
}

int main() {
    int num_node;
    int num_edge;
    while (~scanf("%d %d", &num_node, &num_edge)) {
        memset(Graph, 0, sizeof(Graph));
        memset(path, 0, sizeof(path));
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < num_edge; i++) {
            int from, to, dist;
            scanf("%d %d %d", &from, &to, &dist);
            Graph[from][to] = dist;
        }
        int ans = 0;
        dfs(1, num_node, 0, num_node, 0, &ans);
        printf("%d\n", ans);
        for (int i = 0; path[2 * i]; i++) {
            printf("%d %d\n", path[2 * i], path[2 * i + 1]);
        }
    }
}