#include <stdio.h>
//当时有7个评委，每个评委都要给选手打分，现在要求去掉一个最高分和去掉一个最低分，再算出平均分。结果精确到小数点后两位。
//10 10 10 10 10 10 9 xiaoyuanwang
//0 0 0 0 0 0 0 beast
//xiaoyuanwang 10.00
//beast 0.00

void Bubble_sort(double arr[], int size) {
	int j,i;
	double tem;
	for (i = 0; i < size-1;i ++) {
		int count = 0;
		for (j = 0; j < size-1 - i; j++)	{
			if (arr[j] < arr[j+1]) {
				tem = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tem;
				count = 1;
			}
		}
		if (count == 0)	{
			break;	
		}
	}
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
		
		Bubble_sort(score, 7);
		
		//求分数之和
		double sum = 0;
		for (int i = 1; i <= 5; i++) {
				sum += score[i];
		}
		//输出答案
		printf("%s %.2lf\n", name, sum / 5.0);
	}
	return 0;
}