#include <stdio.h>
#include <string.h>
#define Infinity (1 << 10)
#define N 100

int Graph[N][N];

int dist[N][N];

void BuildGraph(int parent, int preOrder[], int* idx) {
    int cur = preOrder[*idx];
    (*idx)++;
    // 当前节点为空则结束递归
    if (cur == -1) {
        return;
    }
    // 在当前节点和父节点之间加边
    if (cur != 0) {
        Graph[parent][cur] = 1;
        Graph[cur][parent] = 1;        
    }
    // 递归访问当前节点的左右子树
    BuildGraph(cur, preOrder, idx);
    BuildGraph(cur, preOrder, idx);
}

int main() {
    int t;
    char str[N];
    int preOrder[N];
    scanf("%d", &t);
    getchar();
    while (t-- > 0) {
        int idx = 0;
        gets(str);
        // 初始化邻接矩阵
        memset(Graph, 0, sizeof(Graph));
        // 对节点进行重新编号,重新生成preOrder
        int id = 0;
        char ch;
        for (int i = 0; ch = str[i]; i++) {
            if (ch == ' ') {
                preOrder[i] = -1;
            } else {
                preOrder[i] = id++;
            }
        }
        // 建图
        BuildGraph(0, preOrder, &idx);
        // 初始化dist数组
        for (int i = 0; i < id; i++) {
            for (int j = 0; j < id; j++) {
                if (Graph[i][j] == 0) {
                    dist[i][j] = Infinity;
                } else {
                    dist[i][j] = 1;
                }
            }
        }
        // Floyd
        for (int k = 0; k < id; k++) {
            for (int i = 0; i < id; i++) {
                for (int j = 0; j < id; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        // 找出最长路径
        int ans = 0;
        for (int i = 0; i < id; i++) {
            for (int j = 0; j < id; j++) {
                if (dist[i][j] > ans && dist[i][j] < Infinity) {
                    ans = dist[i][j];
                }
            }
        }
        // 输出
        printf("%d\n", ans + 1);
    }
}