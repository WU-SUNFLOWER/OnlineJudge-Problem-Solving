#include <stdio.h>

/*
输入一个正整数m（1≤m≤6）和m阶方阵A中的元素，如果找到A中的鞍点（鞍点的元素值在该行上最大，在该列上最小），
就输出它的下标；否则，输出“NO”（没有鞍点）。设A中最多有一个鞍点。
*/

/*
输入
3
1 2 3
0 1 2
0 0 1
输出
2 2
*/

/*
输入
4
1 2 3 4
0 1 1 3
0 0 1 2
1 0 0 1
输出
NO
*/

int main() {
	int range;
	int matrix[36];
	int MaxDataInRow[6];
    int MinDataInCol[6];
	int IsRepeatDataInRow[6] = {0};
    int IsRepeatDataInCol[6] = {0};
	scanf("%d", &range);
	//获取矩阵数据，并统计每行最大值数据的pos
	int curRow;
    int curCol;
    int curData;
	for (int pos = 0; pos < range * range; pos++) {
		scanf("%d", &matrix[pos]);
		curRow = pos / range;
        curCol = pos % range;
        curData = matrix[pos];
		if (pos % range == 0) {
			MaxDataInRow[curRow] = curData;
		} else {
            if (curData == MaxDataInRow[curRow]) {
                IsRepeatDataInRow[curRow] = 1;
            } 
            else if (curData > MaxDataInRow[curRow]) {
                IsRepeatDataInRow[curRow] = 0;
                MaxDataInRow[curRow] = curData;
            }
        }
        if (pos / range == 0) {
            MinDataInCol[curCol] = curData;
        } else {
            if (curData == MinDataInCol[curCol]) {
                IsRepeatDataInCol[curCol] = 1;
            }
            else if (curData < MinDataInCol[curCol]) {
                IsRepeatDataInCol[curCol] = 0;
                MinDataInCol[curCol] = curData;
            }
        }
	}
	for (int pos = 0; pos < range * range; pos++) {
		curRow = pos / range;
        curCol = pos % range;
        curData = matrix[pos];
        if (IsRepeatDataInCol[curCol] || IsRepeatDataInRow[curRow]) {
            continue;
        }
		if (curData == MinDataInCol[curCol] && curData == MaxDataInRow[curRow]) {
            printf("%d %d\n", curRow, curCol);
            return 0;
        }
	}
    printf("NO\n");
    return 0;
}