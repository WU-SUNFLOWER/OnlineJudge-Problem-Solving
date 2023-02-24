#include <stdio.h>

/*
草原上有一群羊,过一会又来了一群，请问现在有几群羊? 不会有人说是两群羊吧!
为了防止有人将"一群羊"的概念曲解,现给出其概念. 
将草原理想化为一个规则的矩形,且将它划分为一个个规则的单位小方块,每一小方块中恰好能容纳一头羊,
假设羊a,则羊b与羊a为同一群羊应满足羊b所在的小方块和羊a所在的小方块相邻的8个方向。 
若小方块中有羊存在则这个小方块被标记为1,否则被标记为0.现给你一个矩形的小方块请数一数有几群羊?
*/

void dfs(char matrix[][100], int weight, int height, int i, int j) {
    if (matrix[i][j] == '0') {
        return;
    }
    //注销掉该格的小羊
    matrix[i][j] = '0';
    //向上方搜索
    if (i >= 1) {
        dfs(matrix, weight, height, i - 1, j);
    }
    //向下方搜索
    if (i <= height - 2) {
        dfs(matrix, weight, height, i + 1, j);
    }
    //向左方搜索
    if (j >= 1) {
        dfs(matrix, weight, height, i, j - 1);
    }
    //向右方搜索
    if (j <= weight - 2) {
        dfs(matrix, weight, height, i, j + 1);
    }
    //向左上搜索
    if (i >= 1 && j >= 1) {
        dfs(matrix, weight, height, i - 1, j - 1);
    }
    //向右上搜索
    if (i >= 1 && j <= weight - 2) {
        dfs(matrix, weight, height, i - 1, j + 1);
    }
    //向左下搜索
    if (j >= 1 && i <= height - 2) {
        dfs(matrix, weight, height, i + 1, j - 1);
    }
    //向右下搜索
    if (j <= weight - 2 && i <= height - 2) {
        dfs(matrix, weight, height, i + 1, j + 1);
    }
}

int main() {
    int height;
    int weight;
    char matrix[100][100];  //[行][列]
    while (scanf("%d %d", &height, &weight) != EOF) {
        int ans = 0;
        if (height == 0 && weight == 0) {
            break;
        }
        //接收矩阵
        for (int i = 0; i < height; i++) {
            scanf("%s", &matrix[i]);
        }
        //遍历矩阵
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < weight; j++) {
                if (matrix[i][j] == '1') {
                    ans++;
                    dfs(matrix, weight, height, i, j);
                }
            }
        }
        //输出答案
        printf("%d\n", ans);
    }
}