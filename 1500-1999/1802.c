#include <stdio.h>
#define N 25

//本题直接采用邻接矩阵记录图的连通关系
int Graph[N][N];
//记录图中的每个节点是否已被访问过
int Visited[N];
//记录图中每个节点的权值
int Values[N];

int max(int a, int b) {
    return a > b ? a : b;
}

int dfs(int nodeIdx, int nodeNum, int* ans) {
    int sum = Values[nodeIdx];
    Visited[nodeIdx] = 1;
    for (int i = 1; i <= nodeNum; i++) {
        if (Graph[nodeIdx][i] && !Visited[i]) {
            //贪心：如果子图的最大权重和为正数，则更新当前节点的最大权重和
            sum = max(sum, sum + dfs(i, nodeNum, ans));
        }
    }
    *ans = max(*ans, sum);
    return sum;
}

int main() {
    int nodeNum;
    scanf("%d", &nodeNum);
    //读取节点权值
    for (int i = 1; i <= nodeNum; i++) {
        scanf("%d", &Values[i]);
    }
    //读取图，初始化邻接矩阵
    for (int i = 0; i < nodeNum - 1; i++) {
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        Graph[n1][n2] = 1;
        Graph[n2][n1] = 1;
    }
    //任取一个节点作为dfs的起点，这里为了方便直接取编号为1的节点
    int ans = 0;
    dfs(1, nodeNum, &ans);
    printf("%d\n", ans);
}