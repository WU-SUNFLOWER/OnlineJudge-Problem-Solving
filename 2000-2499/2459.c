#include <stdio.h>
#include <stdlib.h>
#define Infinity 1<<30
#define min(x,y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)

// 通过节点名称查询到节点编号
int nameToId[0x7f];
// 通过节点编号查询到节点名称
char idToName[100];

int Graph[21][21];

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
int Prim(int num_node, int start, int parent[], int searchOrder[]) {
    // dist数组记录图中某个节点到最小生成树的"距离"
    // dist[i]=0表示编号为i的节点已被最小生成树收入。
    int dist[21];
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
    int cnt = 1;  // cnt变量用于统计已收入的顶点个数
    int sum = 0;  // 最小生成树路径权值和
    while (1) {
        // 从图中选择未被生成树收入的dist最小的节点v
        int v = getMinDistNode(num_node, dist);
        // 如果不存在这样的v，则退出程序
        if (v == -1) break;
        // 贪心：将v收入最小生成树当中
        dist[v] = 0;
        searchOrder[cnt++] = v;
        sum += Graph[parent[v]][v];
        // 访问v的每个未被收入的邻接节点w，更新它们的dist和parent信息
        for (int w = 0; w < num_node; w++) {
            if (Graph[v][w] && dist[w] && Graph[v][w] < dist[w]) {
                dist[w] = Graph[v][w];
                parent[w] = v;
            }
        }
    }
    // 校验所有节点是否都已经被收入生成树中，以防出现非连通图的情况
    return cnt == num_node ? sum : -1;
}

int main() {
    int num_node, num_edge;
    // 读取节点个数
    scanf("%d", &num_node);
    // 建立节点名称和节点编号的映射关系
    char name = getchar();
    for (int i = 0; i < num_node; i++) {
        name = getchar();
        if (name == ' ') {
            i--;
        } else {
            nameToId[name] = i;
            idToName[i] = name;            
        }
    }
    // 邻接矩阵建图
    char buf[31];
    char from, to;
    int weight;
    scanf("%d", &num_edge);
    for (int i = 0; i < num_edge; i++) {
        scanf("%s", buf);
        sscanf(buf, "%c,%c:%d", &from, &to, &weight);
        Graph[nameToId[from]][nameToId[to]] = weight;
        Graph[nameToId[to]][nameToId[from]] = weight;
    }
    // 选择构造带权图时所输入的第一个顶点为最小生成树的根节点，
    // 调用Prim算法求出答案。
    int parent[21];
    int searchOrder[21];
    int ans = Prim(num_node, 0, parent, searchOrder);
    if (ans == -1) {
        puts("ERROR");
    } else {
        for (int i = 1; i < num_node; i++) {
            int node = searchOrder[i];
            int parentNode = parent[node];
            char name_node = idToName[node];
            char name_parent = idToName[parentNode];
            printf("%c,%c:%d\n", min(name_node, name_parent), max(name_node, name_parent), Graph[node][parentNode]);
        }
        printf("\n%d", ans);
    }
}