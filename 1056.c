#include <stdio.h>
//当时有7个评委，每个评委都要给选手打分，现在要求去掉一个最高分和去掉一个最低分，再算出平均分。结果精确到小数点后两位。
//10 10 10 10 10 10 9 xiaoyuanwang
//0 0 0 0 0 0 0 beast
//xiaoyuanwang 10.00
//beast 0.00

double getMinItemInArray(double* arr, int length) {
	double min = arr[0];
	for (int i = 1; i < length; i++) {
		arr[i] < min && (min = arr[i]);
	}
	return min;
}

double getMaxItemInArray(double* arr, int length) {
	double max = arr[0];
	for (int i = 1; i < length; i++) {
		arr[i] > max && (max = arr[i]);
	}
	return max;
}

int main() {
	double score[7];
	while (scanf("%lf", &score[0]) != EOF) {
		char name[30];
		//逐个读取后面6个分数
		for (int i = 1; i <= 6; i++) {
			scanf("%lf", &score[i]);
		}
		//读取名字
		scanf("%s", &name);
		//求最大最小分数
		double minScore = getMinItemInArray(score, 7);
		double maxScore = getMaxItemInArray(score, 7);
		int checkMin = 0;
		int checkMax = 0;
		//求分数之和
		double sum = 0;
		for (int i = 0; i < 7; i++) {
			if (!checkMin && score[i] == minScore) {
				checkMin = 1;
			}
			else if (!checkMax && score[i] == maxScore) {
				checkMax = 1;
			}
			else {
				sum += score[i];
			}
		}
		//输出答案
		printf("%s %.2lf\n", name, sum / 5.0);
	}
	return 0;
}