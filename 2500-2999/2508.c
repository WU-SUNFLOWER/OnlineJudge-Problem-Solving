#include <stdio.h>

char Map[50][50];

int dfs(int height, int width, int i, int j) {
    //如果找到公主，则搜索结束，返回结果
    if (Map[i][j] == 'G') {
        return 1;
    }
    //碰到墙说明此路不通
    if (Map[i][j] == '#') {
        return 0;
    }
    //往上走
    if (i > 0 && Map[i - 1][j] != '*') {
        Map[i][j] = '*';
        if (dfs(height, width, i - 1, j)) {
            return 1;
        }
        Map[i][j] = '.';
    }
    //往下走
    if (i < height - 1 && Map[i + 1][j] != '*') {
        Map[i][j] = '*';
        if (dfs(height, width, i + 1, j)) {
            return 1;
        }
        Map[i][j] = '.';
    }
    //往左走
    if (j > 0 && Map[i][j - 1] != '*') {
        Map[i][j] = '*';
        if (dfs(height, width, i, j - 1)) {
            return 1;
        }
        Map[i][j] = '.';
    }
    //往右走
    if (j < width - 1 && Map[i][j + 1] != '*') {
        Map[i][j] = '*';
        if (dfs(height, width, i, j + 1)) {
            return 1;
        }
        Map[i][j] = '.';
    }
    return 0;
}

int main() {
    int temp;
    int height;
    int width;
    while (~scanf("%d %d", &height, &width)) {
        int startI;
        int startJ;
        int flag = 1;
        for (int i = 0; i < height; i++) {
            scanf("%s", Map[i]);
            for (int j = 0; j < width && flag; j++) {
                if (Map[i][j] == 'W') {
                    startI = i;
                    startJ = j;
                    flag = 0;
                }
            }
        }
        printf(dfs(height, width, startI, startJ) ? "Good life" : "Mission Failed");
        putchar('\n');
    }
}