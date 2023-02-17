#include <stdio.h>
#include <string.h>
#define N 100001

struct {
    int next;
    int to;
} Edges[N];

int Heads[N];

int edgeId = 0;

void addEdge(int u, int v) {
    Edges[edgeId].next = Heads[u];
    Edges[edgeId].to = v;
    Heads[u] = edgeId++;
}

void dfs(int preNode, int curNode, int curHeight, int curRoot, int* maxHeight, int* minRoot) {
    int flag = 1;
    for (int i = Heads[curNode]; i != -1; i = Edges[i].next) {
        int nextNode = Edges[i].to;
        if (nextNode != preNode) {
            flag = 0;
            dfs(curNode, nextNode, curHeight + 1, curRoot, maxHeight, minRoot);
        }
    }
    if (flag) {
        if (curHeight > *maxHeight) {
            *maxHeight = curHeight;
            *minRoot = curRoot;
        }
    }
}

int main() {
    int nodeNum;
    while (~scanf("%d", &nodeNum)) {
        memset(Heads, -1, sizeof(Heads));
        //��������ͼ
        for (int i = 1; i < nodeNum; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        //ö�����ϵ�ÿ���ڵ���Ϊdfs��㣬�����Ŀ
        int minRoot = 0;
        int maxHeight = 0;
        for (int i = 1; i <= nodeNum; i++) {
            dfs(0, i, 1, i, &maxHeight, &minRoot);
        }
        printf("%d %d\n", minRoot, maxHeight);
    }
}