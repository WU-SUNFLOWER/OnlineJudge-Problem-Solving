#include <stdio.h>
#include <string.h>
#define N 100

int Graph[N][N];

int vis[N];

void dfs(int cur, int num_node) {
    vis[cur] = 1;
    for (int i = 1; i <= num_node; i++) {
        if (Graph[cur][i] && !vis[i]) {
            dfs(i, num_node);
        }
    }
}

int main() {
    int tot;
    int num_node;
    int num_edge;
    scanf("%d", &tot);
    while (~scanf("%d %d", &num_node, &num_edge)) {
        memset(Graph, 0, sizeof(Graph));
        for (int i = 0; i < num_edge; i++) {
            int from, to;
            scanf("%d %d", &from, &to);
            Graph[from][to] = Graph[to][from] = 1;
        }
        // 连通图至少有n-1条边（形成生成树）
        if (num_edge < num_node - 1) {
            puts("no");
            continue;
        }
        // dfs全图，检测连通性
        memset(vis, 0, sizeof(vis));
        dfs(1, num_node);
        int flag = 1;
        for (int i = 1; i <= num_node; i++) {
            if (!vis[i]) {
                flag = 0;
                break;
            }
        }
        puts(flag ? "yes" : "no");
    }
}