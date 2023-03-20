#include <stdio.h>

typedef long long ll;

int node_num;

int roots[100][100];

ll scores[100];

ll dfs(int left, int right) {
    ll maxScore = 0;
    // 碰到叶节点的情况
    if (left == right) {
        return scores[left];
    }
    // 左/右子树不存在的情况
    if (left > right) {
        return 1;
    }
    for (int i = left; i <= right; i++) {
        ll curScore = dfs(left, i - 1) * dfs(i + 1, right) + scores[i];
        if (curScore > maxScore) {
            maxScore = curScore;
            roots[left][right] = i;
        }
    }
    return maxScore;
}

void preOrderTraversal(int left, int right) {
    if (left > right) return;
    int root = roots[left][right];
    static int cnt = 0;
    printf(++cnt == node_num ? "%d\n" : "%d ", root);
    preOrderTraversal(left, root - 1);
    preOrderTraversal(root + 1, right);
}

int main() {
    scanf("%d", &node_num);
    for (int i = 1; i <= node_num; i++) {
        roots[i][i] = i;
        scanf("%lld", &scores[i]);
    }
    // 输出最优解
    printf("%lld\n", dfs(1, node_num));
    // 输出前序序列
    preOrderTraversal(1, node_num);
}