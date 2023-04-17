#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#define Infinity 1<<30

int Graph[N][N];

int getMinDistNode(int num_node, int dist[]) {
    int node = -1;
    int minDist = Infinity;
    for (int i = 0; i < num_node; i++) {
        if (dist[i] > 0 && dist[i] < minDist) {
            minDist = dist[i];
            node = i;
        }
    }
    return node;
}

// 通过Prim算法计算最小生成树各条边的权值之和
int Prim(int num_node, int start, int parent[]) {
    // dist数组记录图中某个节点到最小生成树的"距离"
    // dist[i]=0表示编号为i的节点已被最小生成树收入。
    int dist[N];
    // 将根节点标记为已收入
    // 同时更新与根节点直接连通的各节点的dist值
    // 还需要将其他节点的dist值标记为无穷大
    dist[start] = 0;
    for (int i = 0; i < num_node; i++) {
        if (i == start) continue;
        if (Graph[start][i]) {
            dist[i] = Graph[start][i];
            parent[i] = start;
        } else {
            dist[i] = Infinity;
        }
    }
    int sum = 0;  // 最小生成树路径权值和
    while (1) {
        // 从图中选择未被生成树收入的dist最小的节点v
        int v = getMinDistNode(num_node, dist);
        // 如果不存在这样的v，则退出程序
        if (v == -1) break;
        // 贪心：将v收入最小生成树当中
        dist[v] = 0;
        sum += Graph[parent[v]][v];
        // 访问v的每个未被收入的邻接节点w，更新它们的dist和parent信息
        for (int w = 0; w < num_node; w++) {
            if (Graph[v][w] && dist[w] && Graph[v][w] < dist[w]) {
                dist[w] = Graph[v][w];
                parent[w] = v;
            }
        }
    }
    return sum;
}

int main() {
    int parent[N];
    int num_node, num_edge;
    while (~scanf("%d", &num_node) && num_node > 0) {
        int from, to, weight;
        // 所有村庄之间都有无向路径
        num_edge = num_node * (num_node - 1) / 2;
        memset(Graph, 0, sizeof(Graph));
        for (int i = 0; i < num_edge; i++) {
            scanf("%d %d %d", &from, &to, &weight);
            Graph[from - 1][to - 1] = weight;
            Graph[to - 1][from - 1] = weight;
        }
        // 选择构造带权图时所输入的第一个顶点为最小生成树的根节点，
        // 调用Prim算法求出答案。
        printf("%d\n", Prim(num_node, 0, parent));        
    }
}