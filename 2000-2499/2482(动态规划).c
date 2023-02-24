#include <stdio.h>

int main() {
    int dp[100][100];  //dp[i][j],其中i表示拿50元的人数，j表示拿100元的人数
    int leftUserNum1;  //拿50元钞票的人数
    int leftUserNum2;  //拿100元钞票的人数
    scanf("%d,%d", &leftUserNum1, &leftUserNum2);
    
    //第一种情况：若所有人都拿50元的钞票，则有且仅有1种排队方案，即dp[0][0]到dp[leftUserNum1][0]都为1
    //第二种情况：若拿50元钞票的人数小于拿100元钞票的人数，则一定无解，只有0种方案
    //其他情况，采用状态转移方程对两种可能的情况进行求和：最后一个人拿的是50元钞票，最后一个人拿了100元钞票 
    //dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
    
    for (int i = 0; i <= leftUserNum1; i++) {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= leftUserNum1; i++) {
        for (int j = 1; j <= leftUserNum2; j++) {
            if (i < j) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    
    printf("%d\n", dp[leftUserNum1][leftUserNum2]);
}