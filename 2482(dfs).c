#include <stdio.h>

void dfs(int leftUserNum1, int leftUserNum2, int leftChange, int* ans) {
    //第一种情况：所有用户已经处理完毕
    if (leftUserNum1 == 0 && leftUserNum2 == 0) {
        *ans += 1;
        return;
    }
    //第二种情况：当前用户拿的是一百元的钞票，且五十元的零钱足够
    if (leftUserNum2 > 0 && leftChange > 0) {
        dfs(leftUserNum1, leftUserNum2 - 1, leftChange - 1, ans);
    }
    //第三种情况：当前用户拿的是五十元的零钱
    if (leftUserNum1 > 0) {
        dfs(leftUserNum1 - 1, leftUserNum2, leftChange + 1, ans);
    }
}

int main() {
    int ans = 0;
    int leftUserNum1;
    int leftUserNum2;
    scanf("%d,%d", &leftUserNum1, &leftUserNum2);
    dfs(leftUserNum1, leftUserNum2, 0, &ans);
    printf("%d\n", ans);
}