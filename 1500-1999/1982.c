#include <stdio.h>
#include <math.h>

/*
某大奖赛有n(1<n<40)个选手参赛，m (2<m<20)个评委为依次参赛的选手评判打分：最高10分，最低0分。
统分规则为：每个选手所得的m个得分中，去掉一个最高分，去掉一个最低分，最后平均为该选手的最后得分。
根据n个选手的最后得分从高到低排出名次表，以便确定获奖名单。

输入:
输入选手的数目n(1<n<40)，评委的数目m (2<m<20)，以及评委对每位选手的打分。

输出:
选手的排名及最终的得分值（小数点后保留两位）。

输入样例 1 
3,5
5.6 7.8 9.4 5.8 8.8
7.8 6.7 8.3 6.9 5.5
6.7 9.2 8.8 8.3 9.0
输出样例 1
第1名:3号选手,得分8.70
第2名:1号选手,得分7.47
第3名:2号选手,得分7.13
*/

int main() {
	int competitorNum;
	int judgeNum;
	int indexArr[40];
	double minScore[40];
	double maxScore[40];
	double originalScore[40][20];  //score[选手编号][分数下标]
	double averageScore[40];
	scanf("%d,%d", &competitorNum, &judgeNum);
	for (int i = 0; i < competitorNum; i++) {
		indexArr[i] = i;
		for (int j = 0; j < judgeNum; j++) {
			scanf("%lf", &originalScore[i][j]);
			if (j == 0) {
				minScore[i] = maxScore[i] = originalScore[i][j];
			} else {
				originalScore[i][j] < minScore[i] && (minScore[i] = originalScore[i][j]);
				originalScore[i][j] > maxScore[i] && (maxScore[i] = originalScore[i][j]);
			}
		}
	}
	for (int i = 0; i < competitorNum; i++) {
		double sum = 0;
		int minFlag = 0;
		int maxFlag = 0;
		for (int j = 0; j < judgeNum; j++) {
			if (originalScore[i][j] == minScore[i] && minFlag == 0) {
				minFlag = 1;
			}
			else if (originalScore[i][j] == maxScore[i] && maxFlag == 0) {
				maxFlag = 1;
			}
			else {
				sum += originalScore[i][j];
			}
		}
		averageScore[i] = sum / (judgeNum - 2);
	}
	for (int i = 0; i < competitorNum - 1; i++) {
		int flag = 1;
		for (int j = 0; j <= competitorNum - 2 - i; j++) {
			if (averageScore[indexArr[j]] < averageScore[indexArr[j + 1]]) {
				int temp = indexArr[j];
				indexArr[j] = indexArr[j + 1];
				indexArr[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag) {
			break;
		}
	}
	for (int i = 0; i < competitorNum; i++) {
		printf("第%d名:%d号选手,得分%.2lf\n", i + 1, indexArr[i] + 1, averageScore[indexArr[i]]);
	}
}