#include <stdio.h>

/*
本题参考资料：https://bubbleioa.blog.luogu.org/solution-p1040
*/

typedef long long ll;

int node_num;

int roots[100][100];

ll dp[100][100];

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
        // 叶子节点的根节点就是它本身
        roots[i][i] = i;
        // 若某个子树为空，规定其加分为1
        dp[i][i - 1] = 1;
        dp[i + 1][i] = 1;
        scanf("%lld", &dp[i][i]);
    }
    // 输出最优解
    // range变量表示子树的大小
    // range从2增加到node_num，通过不断扩大子树规模的方式最终求得原题答案
    for (int range = 2; range <= node_num; range++) {
        for (int left = 1; left + range - 1 <= node_num; left++) {
            int right = left + range - 1;
            for (int root = left; root <= right; root++) {
                ll curScore = dp[left][root - 1] * dp[root + 1][right] + dp[root][root];
                if (curScore > dp[left][right]) {
                    dp[left][right] = curScore;
                    roots[left][right] = root;
                }
            }
        }
    }
    printf("%lld\n", dp[1][node_num]);
    // 输出前序序列
    preOrderTraversal(1, node_num);
}