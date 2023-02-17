#include <stdio.h>
#include <stdlib.h>

typedef struct trnode {
    // 决策树左节点表示将当前物品放入背包的情形
    struct trnode* left;
    // 决策树右节点表示不将当前物品放入背包的情形
    struct trnode* right;
    // 当前背包内物品的总价值
    int value;
    // 当前背包的剩余容量
    int capcity;
    // 利用二进制记录最优决策的路径,
    // 除最高位1为哨兵位之外，二进制位0表示当前物品不放，1表示当前物品放
    int path;
} *TNode, *Tree;

int productNum;
int totalCapcity;
int values[100];
int weights[100];

TNode createNode(int value, int capcity, int path) {
    TNode node = (TNode)malloc(sizeof(struct trnode));
    node->value = value;
    node->capcity = capcity;
    node->path = path;
    return node;
}

int solve(TNode node, int idx) {
    if (idx >= productNum) {
        return node->value;
    }
    int ans1 = 0;
    int ans2 = 0;
    //讨论当前物品放入背包的情形
    if (node->capcity >= weights[idx]) {
        node->left = createNode(node->value + values[idx], node->capcity - weights[idx], node->path * 2 + 1);
        ans1 = solve(node->left, idx + 1);
    } else {
        node->left = NULL;
    }
    // 讨论当前背包不放入背包的情形
    node->right = createNode(node->value, node->capcity, node->path * 2);
    ans2 = solve(node->right, idx + 1);
    // 计算两种情形中的最优解，并回溯更新决策树
    if (ans1 > ans2) {
        node->value = ans1;
        node->path = node->left->path;
    } else {
        node->value = ans2;
        node->path = node->right->path;
    }
    return node->value;
}

int main() {
    scanf("%d %d", &productNum, &totalCapcity);
    //读取物品的价值
    for (int i = 0; i < productNum; i++) {
        scanf("%d", &values[i]);
    }
    //读取物品的重量
    for (int i = 0; i < productNum; i++) {
        scanf("%d", &weights[i]);
    }
    //初始化决策树，递归求解
    TNode root = createNode(0, totalCapcity, 1);
    solve(root, 0);
    //输出最优解
    printf("Optimal value is\n%d\n", root->value);
    //解码二进制的路径数据，输出
    int i = 0;
    int pathArr[100];
    int path = root->path;
    while (path) {
        pathArr[productNum - i] = path % 2;
        path /= 2;
        i++;
    }
    for (int i = 1; i <= productNum; i++) {
        printf(i == productNum ? "%d\n" : "%d ", pathArr[i]);
    }
}