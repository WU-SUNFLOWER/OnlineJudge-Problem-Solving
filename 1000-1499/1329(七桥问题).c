#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
参考资料：
https://blog.csdn.net/seagal890/article/details/94845465
https://zh.wikipedia.org/zh-cn/%E4%B8%80%E7%AC%94%E7%94%BB%E9%97%AE%E9%A2%98
*/

int edges[105];
int Graph[101][101];

bool vis[101];

void dfs(int cur, int cnt_node) {
    vis[cur] = true;
    for (int i = 1; i <= cnt_node; i++) {
        if (Graph[cur][i] && !vis[i]) {
            dfs(i, cnt_node);
        }
    }
}

bool isConnectedGraph(int cnt_node) {
    for (int i = 1; i <= cnt_node; i++) {
        memset(vis, false, sizeof(vis));
        dfs(i, cnt_node);
        for (int i = 1; i <= cnt_node; i++) {
            if (!vis[i]) return false;
        }
    }
    return true;
}

int main() {
    int total;
    int num_node;
    int num_edge;
    scanf("%d", &total);
    while (total--) {
        memset(edges, 0, sizeof(edges));
        memset(Graph, 0, sizeof(Graph));
        scanf("%d %d", &num_node, &num_edge);
        for (int i = 0; i < num_edge; i++) {
            int from, to;
            scanf("%d %d", &from, &to);
            edges[from]++;
            edges[to]++;
            Graph[from][to] = 1;
            Graph[to][from] = 1;
        }
        
        // 无向图存在欧拉回路的充要条件：
        // 图连通，所有顶点都是偶数度  （也就是说所有的节点全是偶点，没有奇点）
        // 首先检测是否是连通图
        bool flag = isConnectedGraph(num_node);
        // 再检测所有顶点的度数
        for (int i = 1; i <= num_node && flag; i++) {
            if (edges[i] % 2 != 0) {
                flag = false;
                break;
            }
        }
        puts(flag ? "YES" : "NO");
    }
}