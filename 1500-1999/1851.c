#include <stdio.h>
#define N 400

int dp[N][N];

int w[N];  // 储存每个物品的重量

int v[N];  // 储存每个物品的价值

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int total;  // 物品的总数
    int maxWeight;  // 背包能够容纳的最大重量
    scanf("%d %d", &total, &maxWeight);
    for (int i = 1; i <= total; i++) {
        scanf("%d %d", &w[i], &v[i]);
    }
    // 尝试逐个放入物品
    for (int i = 1; i <= total; i++) {
        // 讨论不同背包最大容量的情况
        for (int j = 1; j <= maxWeight; j++) {
            // 当前背包容量上限j无法装下当前物品i时
            if (j < w[i]) {
                dp[i][j] = dp[i - 1][j];
            } 
            // 当前背包容量上限如果能够装下当前物品i
            // 则讨论放入当前物品和不放入当前物品的最优解
            // 为了计算放入当前物品i情形下的最优解，
            // 需要将v[i]与除去i所占用空间后剩余空间放入物品所取得最大价值求和
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d\n", dp[total][maxWeight]);
}