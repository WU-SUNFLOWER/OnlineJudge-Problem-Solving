#include <stdio.h>
#define Infinity 1 << 30
#define N 35

int main() {
    int num_node;
    int num_edge;
    int dist[N][N];
    int parent[N][N];
    while (~scanf("%d %d", &num_node, &num_edge)) {
        // 为dist和parent数组设置默认值
        for (int i = 1; i <= num_node; i++) {
            for (int j = 1; j <= num_node; j++) {
                dist[i][j] = i == j ? 0 : -Infinity;
                parent[i][j] = -1;
            }
        }
        // 建图
        for (int i = 0; i < num_edge; i++) {
            int from, to, weight;
            scanf("%d %d %d", &from, &to, &weight);
            dist[from][to] = weight;
            // parent[i][j]表示从i走到j路径上j的前驱节点是谁
            parent[from][to] = from;  
        }
        // floyd
        for (int k = 1; k <= num_node; k++) {
            for (int i = 1; i <= num_node; i++) {
                for (int j = 1; j <= num_node; j++) {
                    if (dist[i][k] + dist[k][j] > dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        parent[i][j] = parent[k][j];
                    }
                }
            }
        }
        // 输出
        printf("%d\n", dist[1][num_node]);
        int cur = num_node;
        int ans[2 * N];
        int idx = 0;
        while (cur != 1) {
            ans[idx] = parent[1][cur];
            ans[idx + 1] = cur;
            cur = parent[1][cur];
            idx += 2;
        }
        for (int i = idx - 2; i >= 0; i -= 2) {
            printf("%d %d\n", ans[i], ans[i + 1]);
        }
    }
}