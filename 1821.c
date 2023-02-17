#include <stdio.h>

int main() {
    int size;
    int root;
    int EdgeCnt[1024] = {0};
    scanf("%d %d", &size, &root);
    //root节点需要特殊讨论
    EdgeCnt[root] = 1;
    //统计每个节点的连通边数
    for (int i = 0; i < size - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        EdgeCnt[a]++;
        EdgeCnt[b]++;
    }
    //题目定义的“完全二叉树”一定满足如下特征：
    //叶节点的连通边数一定等于1，其余节点的连通边数一定等于3
    int ans = 1;
    for (int i = 1; i <= size; i++) {
        if (EdgeCnt[i] != 1 && EdgeCnt[i] != 3) {
            ans = 0;
            break;
        }
    }
    printf(ans ? "yes\n" : "no\n");
}