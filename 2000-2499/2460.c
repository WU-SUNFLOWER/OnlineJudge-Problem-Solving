#include <stdio.h>
#include <stdlib.h>
#define min(x,y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)

/* 邻接表存图 开始 */
typedef struct edge {
    int v1;
    int v2;
    int weight;
} Edge;

Edge createEdge(int v1, int v2, int weight) {
    Edge e = (Edge)malloc(sizeof(struct edge));
    e->v1 = v1;
    e->v2 = v2;
    e->weight = weight;
    return e;
}

int cmp(const void* e1, const void* e2) {
    Edge edge1 = *(Edge*)e1;
    Edge edge2 = *(Edge*)e2;
    return edge1->weight - edge2->weight;
}
/* 邻接表存图 结束 */


// 通过节点名称查询到节点编号
int nameToId[0x7f];
// 通过节点编号查询到节点名称
char idToName[100];

int Graph[21][21];

int Kruskal(int num_node, int num_edge, Edge edges[], Edge searchOrder[]) {
    int sum = 0;
    int cnt = 0;  // 记录已收入生成树的边数
    int idx = 0;
    // 事先需要先对所有边按升序排序
    qsort(edges, num_edge, sizeof(Edge), cmp);
    // 当还没收集满num_node-1条边，且图中还有边可供收集时
    while (cnt < num_node - 1 && idx < num_edge) {
        Edge newEdge = edges[idx++];
        // 检测newEdge是否和生成树中已收入的边构成回路
        if () {
            sum += newEdge->weight;
            searchOrder[cnt++] = newEdge;
        }
    }
    // 如果循环退出时边没搜集满，说明最小生成树不存在（即图不连通）
    return cnt < num_node - 1 ? : sum;
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
    char v1, v2;
    int weight;
    int edges[21];
    scanf("%d", &num_edge);
    for (int i = 0; i < num_edge; i++) {
        scanf("%s", buf);
        sscanf(buf, "%c,%c:%d", &v1, &v2, &weight);
        edges[i] = createEdge(nameToId[v1], nameToId[v2], weight);
    }
    // 调用Kruskal算法求出答案
    Edge searchOrder[21];
    int ans = Kruskal(num_node, num_edge, edges, searchOrder);
    if (ans == -1) {
        puts("ERROR");
    } else {
        for (int i = 0; i < num_node - 1; i++) {
            Edge edge = searchOrder[i];
            char name1 = idToName[edge->v1];
            char name2 = idToName[edge->v2];
            printf("%c,%c:%d\n", min(name1, name2), max(name1, name2), newEdge->weight);
        }
        printf("\n%d", ans);
    }
}