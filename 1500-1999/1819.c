#include <stdio.h>

int max(int a, int b) {
    return a < b ? b : a;
}

int dfs(int leftChild[], int rightChild[], int cur, int pathCnt) {
    int left = leftChild[cur];
    int right = rightChild[cur];
    // 如果当前节点为叶节点
    if (left == 0 && right == 0) {
        return pathCnt;
    }
    // 尝试访问当前节点的左右子树
    int left_cnt = 0;
    int right_cnt = 0;
    left && (left_cnt = dfs(leftChild, rightChild, left, pathCnt + 1));
    right && (right_cnt = dfs(leftChild, rightChild, right, pathCnt + 1));
    return max(left_cnt, right_cnt);
}

int main() {
    int nodeNum;
    int leftChild[100];
    int rightChild[100];
    // 获取节点总数
    scanf("%d", &nodeNum);
    // 建树
    int ans;
    for (int i = 1; i <= nodeNum; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        leftChild[i] = l;
        rightChild[i] = r;
        if (i == nodeNum) ans = l;
    }
    // dfs搜索
    printf("%d %d\n", dfs(leftChild, rightChild, 1, 1), ans);
}
