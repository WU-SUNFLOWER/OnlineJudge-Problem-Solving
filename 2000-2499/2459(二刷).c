#include <stdio.h>
#define Infinity 1 << 10
#define N 25

char idToName[N];

char nameToId[0x7f];

int Graph[N][N];

int dist[N];

int parent[N];

int max(int a, int b) {
    return a < b ? b : a;
}

int min(int a, int b) {
    return a > b ? b : a;
}

int Prim(int start, int num_node, int record[], int* idx_record) {
    // 初始化dist数组和parent数组
    for (int i = 0; i < num_node; i++) {
        if (Graph[start][i]) {
            dist[i] = Graph[start][i];
            parent[i] = start;
        } else {
            dist[i] = Infinity;
            parent[i] = -1;
        }
    }
    dist[start] = 0;
    // 构建最小生成树
    int ans = 0;
    while (1) {
        // 从未被收入最小生成树的节点中选取距离最小生成树最近的那个
        int targetNode = -1;
        int targetDist = Infinity;
        for (int i = 0; i < num_node; i++) {
            if (dist[i] > 0 && dist[i] < targetDist) {
                targetNode = i;
                targetDist = dist[i];
            }
        }
        // 将选取出来的节点收入最小生成树，并更新其邻接点的dist值
        if (targetNode != -1) {
            int p = parent[targetNode];
            record[2 * (*idx_record)] = min(p, targetNode);
            record[2 * (*idx_record) + 1] = max(p, targetNode);
            (*idx_record)++;
            ans += targetDist;
            dist[targetNode] = 0;
            for (int i = 0; i < num_node; i++) {
                int newDist = Graph[targetNode][i];
                if (newDist > 0 && newDist < dist[i]) {
                    dist[i] = newDist;
                    parent[i] = targetNode;
                }
            }
        } else {
            break;
        }
    }
    return ans;
}

int main() {
    int num_node;
    int num_edge;
    char buf[N];
    scanf("%d", &num_node);
    // 读取节点名称
    for (int i = 0; i < num_node; i++) {
        scanf("%s", buf);
        char name = buf[0];
        nameToId[name] = i;
        idToName[i] = name;
    }
    // 读取边的信息
    scanf("%d", &num_edge);
    for (int i = 0; i < num_edge; i++) {
        char from, to;
        int dist;
        scanf("%s", buf);
        sscanf(buf, "%c,%c:%d", &from, &to, &dist);
        Graph[nameToId[from]][nameToId[to]] = dist;
        Graph[nameToId[to]][nameToId[from]] = dist;
    }
    // 调用Prim算法求解
    int record[N];
    int idx_record = 0;
    int ans = Prim(0, num_node, record, &idx_record);
    // 检测图是否连通
    int flag = 1;
    for (int i = 0 ; i < num_node; i++) {
        if (dist[i] != 0) {
            flag = 0;
            break;
        }
    }
    if (flag) {
        for (int i = 0; i < idx_record; i++) {
            int from = record[2 * i];
            int to = record[2 * i + 1];
            printf("%c,%c:%d\n", idToName[from], idToName[to], Graph[from][to]);
        }
        printf("\n%d\n", ans);
    } else {
        puts("ERROR");
    }
    
}