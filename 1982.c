#include <stdio.h>
#include <math.h>

/*
ĳ������n(1<n<40)��ѡ�ֲ�����m (2<m<20)����ίΪ���β�����ѡ�����д�֣����10�֣����0�֡�
ͳ�ֹ���Ϊ��ÿ��ѡ�����õ�m���÷��У�ȥ��һ����߷֣�ȥ��һ����ͷ֣����ƽ��Ϊ��ѡ�ֵ����÷֡�
����n��ѡ�ֵ����÷ִӸߵ����ų����α��Ա�ȷ����������

����:
����ѡ�ֵ���Ŀn(1<n<40)����ί����Ŀm (2<m<20)���Լ���ί��ÿλѡ�ֵĴ�֡�

���:
ѡ�ֵ����������յĵ÷�ֵ��С���������λ����

�������� 1 
3,5
5.6 7.8 9.4 5.8 8.8
7.8 6.7 8.3 6.9 5.5
6.7 9.2 8.8 8.3 9.0
������� 1
��1��:3��ѡ��,�÷�8.70
��2��:1��ѡ��,�÷�7.47
��3��:2��ѡ��,�÷�7.13
*/

int main() {
	int competitorNum;
	int judgeNum;
	int indexArr[40];
	double minScore[40];
	double maxScore[40];
	double originalScore[40][20];  //score[ѡ�ֱ��][�����±�]
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
		printf("��%d��:%d��ѡ��,�÷�%.2lf\n", i + 1, indexArr[i] + 1, averageScore[indexArr[i]]);
	}
}