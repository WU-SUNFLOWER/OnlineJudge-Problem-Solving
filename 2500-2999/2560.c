#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define N 210

const int Infinity = 1 << 20;

int Graph[N][N];

int getMinDistVex(int dist[], bool collected[], int num_node) {
    int vex = -1;
    int minDist = Infinity;
    for (int i = 1; i <= num_node; i++) {
        if (!collected[i] && dist[i] < minDist) {
            vex = i;
            minDist = dist[i];
        }
    }
    return vex;
}

void Dijkstra(int start, int num_node, int parent[]) {
    int dist[N];
    bool collected[N] = {false};
    // 初始化parent数组
    memset(parent, 0xff, num_node * sizeof(int));
    // 初始化dist数组
    for (int i = 1; i <= num_node; i++) {
        if (i == start) {
            dist[i] = 0;
        }
        else {
            dist[i] = Infinity;
        }
    }
    while (true) {
        // 查询未收入顶点中dist最小者
        int v = getMinDistVex(dist, collected, num_node);
        // 这样的顶点如果不存在，则说明最小路径已生成完毕
        if (v == -1) break;
        // 将v收入集合当中
        collected[v] = true;
        // 更新v的邻接点
        for (int i = 1; i <= num_node; i++) {
            if (Graph[v][i] && !collected[i] && dist[v] + Graph[v][i] < dist[i]) {
                dist[i] = dist[v] + Graph[v][i];
                parent[i] = v;
            }
        }
    }
}

int main() {
    int num_node;
    int num_edge;
    int parent[N];
    while (~scanf("%d %d", &num_node, &num_edge)) {
        // 邻接矩阵建图
        memset(Graph, 0, sizeof(Graph));
        for (int i = 0; i < num_edge; i++) {
            int from, to, weight;
            scanf("%d %d %d", &from, &to, &weight);
            Graph[from][to] = Graph[to][from] = weight;
        }
        // 读取起点和终点
        int start, end;
        scanf("%d %d", &start, &end);
        // 调用Dijskstra生成最短路径
        Dijkstra(start, num_node, parent);
        // 计算最短路径的值
        int cur = end;
        int ans = 0;
        if (parent[cur] == -1) {
            puts("-1");
        } else {
            while (cur != -1) {
                ans += Graph[parent[cur]][cur];
                cur = parent[cur];
            }
            printf("%d\n", ans);            
        }
    }
}