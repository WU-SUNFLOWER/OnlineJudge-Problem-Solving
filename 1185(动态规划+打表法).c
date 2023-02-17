#include <stdio.h>

int main() {
    //动规打表
    int dp[50] = {0, 2, 3};
    /*
    分两种情况进行考虑：
    第一种情况，无论上一位（即第i-1位）的数字是0还是1，当前第i位都可以填一个万能的0上去。
    在此种情况下，i位二进制数的情况总数相当于i-1位二进制数的情况总数。
    
    第二种情况，如果当前第i位想填一个1上去，那么意味着第i-1位必须是万能的0。
    若第i-1位是0，则意味着第1~i-2位构成的是任意的符合题意的二进制数。
    在此种情况下，i位二进制数的情况总数相当于i-2位二进制数的情况总数。
    */
    for (int i = 3; i <= 40; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    //处理输入数据
    int n;
    int idx = 1;
    int GroupNum;
    scanf("%d", &GroupNum);
    while (idx <= GroupNum) {
        scanf("%d", &n);
        printf("Scenario #%d:\n%d\n\n", idx++, dp[n]);
    }
}