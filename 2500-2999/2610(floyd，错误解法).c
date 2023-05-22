#include <stdio.h>
#define Infinity 1 << 15
#define N 35

/*
此种做法有误！
Floyd(及尝试对其进行改造)并无法保证生成字典序最小的路径!

反例如下：
8 11
1 2 1
1 3 1
1 4 1
2 5 1
2 8 3
3 5 1
4 5 1
5 7 1
5 6 1
7 8 1
6 8 1
*/

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
                    int newDist = dist[i][k] + dist[k][j];
                    if (newDist > dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        parent[i][j] = parent[k][j];
                    }
                    else if (newDist > 0 && newDist == dist[i][j] && parent[k][j] > 0 && parent[i][j] > parent[k][j]) {
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
            printf("cur=%d\n", cur);
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