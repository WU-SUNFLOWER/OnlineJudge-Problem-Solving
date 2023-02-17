#include <stdio.h>
#include <stdlib.h>

/*
Jesse托梦给你，希望你帮他判断一下当年他是否有机会在给定的时间T内找到公主。

题目包括多组测试数据。 
每组测试数据以三个整数N,M,T(0<n, m≤20, t>0)开头，分别代表迷宫的长和高，以及公主能坚持的天数。 
紧接着有M行，N列字符，由"."，"*"，"P"，"S"组成。其中 "." 代表能够行走的空地。 "*" 代表墙壁，Jesse不能从此通过。 
"P" 是公主所在的位置。 "S" 是Jesse的起始位置。 每个时间段里Jesse只能选择“上、下、左、右”任意一方向走一步。 
输入以0 0 0结束。
*/

/*
输入：
长度4 高度4 坚持天数10
....
....
....
S**P
0 0 0

输出：
YES
*/

int Width;
int Height;
char map[20][21];
char blackList[20][21];

char* createString(int length) {
    char* str = (char*)malloc(sizeof(char) * (length + 1));
	str[length] = '\0';
	return str;
}

int dfs(char map[20][21], int curX, int curY, int restTime) {
	//先判断是否成功
	//用完剩余天数则直接失败
	if (restTime < 0) {
		return 0;
	} 
	//找到字母P则搜索成功
	else if (map[curY][curX] == 'P') {
		return 1;
	}
	//尝试走上方
	if (curY > 0 && map[curY - 1][curX] != '*' && map[curY - 1][curX] != 'S' && blackList[curY - 1][curX] == 0) {
		blackList[curY - 1][curX] = 1;
		if (dfs(map, curX, curY - 1, restTime - 1)) {
			return 1;
		} else {
			blackList[curY - 1][curX] = 0;
		}
	}
	//尝试走下方
	if (curY <= Height - 2 && map[curY + 1][curX] != '*' && map[curY + 1][curX] != 'S' && blackList[curY + 1][curX] == 0) {
		blackList[curY + 1][curX] = 1;
		if (dfs(map, curX, curY + 1, restTime - 1)) {
			return 1;
		} else {
			blackList[curY + 1][curX] = 0;
		}
	}
	//尝试走左方
	if (curX > 0 && map[curY][curX - 1] != '*' && map[curY][curX - 1] != 'S' && blackList[curY][curX - 1] == 0) {
		blackList[curY][curX - 1] = 1;
		if (dfs(map, curX - 1, curY, restTime - 1)) {
			return 1;
		} else {
			blackList[curY][curX - 1] = 0;
		}
	}
	//尝试走右方
	if (curX <= Width - 2 && map[curY][curX + 1] != '*' && map[curY][curX + 1] != 'S' && blackList[curY][curX + 1] == 0) {
		blackList[curY][curX + 1] = 1;
		if (dfs(map, curX + 1, curY, restTime - 1)) {
			return 1;
		} else {
			blackList[curY][curX + 1] = 0;
		}
	}
	return 0;
}

int main() {
	int TotalTime;
	int startX;
	int startY;
	while (scanf("%d %d %d", &Width, &Height, &TotalTime) != EOF) {
		if (Width == 0 && Height == 0 && TotalTime == 0) {
			break;
		}
		for (int j = 0; j < Height; j++) {
			char* lineInfo = createString(Width);
			scanf("%s", lineInfo);
			for (int i = 0; i < Width; i++) {
				char sign = lineInfo[i];
				map[j][i] = sign;
				blackList[j][i] = 0;
				if (sign == 'S') {
					startX = i;
					startY = j;
				}
			}
		}
		printf(dfs(map, startX, startY, TotalTime) ? "YES\n" : "NO\n");
	}
	
	return 0;
}