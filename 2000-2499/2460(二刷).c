#include <stdio.h>
#define Infinity 1 << 10
#define N 25

char idToName[N];

char nameToId[0x7f];

int Graph[N][N];

int vexSet[N];

int max(int a, int b) {
    return a < b ? b : a;
}

int min(int a, int b) {
    return a > b ? b : a;
}

int Kruskal(int num_node, int record[], int* idx_record) {
    for (int i = 0; i < num_node; i++) {
        vexSet[i] = i;
    }
    int ans = 0;
    while (1) {
        // 选取未收入生成树中的一条最短的、且不构成回路的边
        int from, to;
        int shortest = Infinity;
        for (int i = 0; i < num_node; i++) {
            for (int j = 0; j < num_node; j++) {
                if (Graph[i][j] > 0 && Graph[i][j] < shortest && vexSet[i] != vexSet[j]) {
                    from = i;
                    to = j;
                    shortest = Graph[i][j];
                }
            }
        }
        // 将该条边收入图中
        if (shortest < Infinity) {
            ans += Graph[from][to];
            // 将该边标记为负数，表示已经被收入
            Graph[from][to] = Graph[to][from] = -Graph[from][to];
            // 更新并查集
            int vs_to = vexSet[to];
            for (int i = 0; i < num_node; i++) {
                if (vexSet[i] == vs_to) {
                    vexSet[i] = vexSet[from];
                }
            }
            // 记录答案
            record[2 * (*idx_record)] = min(from, to);
            record[2 * (*idx_record) + 1] = max(from, to);
            (*idx_record)++;
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
    int ans = Kruskal(num_node, record, &idx_record);
    // 检测图是否连通
    int flag = 1;
    for (int i = 1 ; i < num_node; i++) {
        if (vexSet[i] != vexSet[i - 1]) {
            flag = 0;
            break;
        }
    }
    if (flag) {
        for (int i = 0; i < idx_record; i++) {
            int from = record[2 * i];
            int to = record[2 * i + 1];
            printf("%c,%c:%d\n", idToName[from], idToName[to], -Graph[from][to]);
        }
        printf("\n%d\n", ans);
    } else {
        puts("ERROR");
    }
    
}