#include <stdio.h>

/*
����һ��������m��1��m��6����m�׷���A�е�Ԫ�أ�����ҵ�A�еİ��㣨�����Ԫ��ֵ�ڸ���������ڸ�������С����
����������±ꣻ���������NO����û�а��㣩����A�������һ�����㡣
*/

/*
����
3
1 2 3
0 1 2
0 0 1
���
2 2
*/

/*
����
4
1 2 3 4
0 1 1 3
0 0 1 2
1 0 0 1
���
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
	//��ȡ�������ݣ���ͳ��ÿ�����ֵ���ݵ�pos
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