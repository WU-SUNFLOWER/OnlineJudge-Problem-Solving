#include <stdio.h>
//��ʱ��7����ί��ÿ����ί��Ҫ��ѡ�ִ�֣�����Ҫ��ȥ��һ����߷ֺ�ȥ��һ����ͷ֣������ƽ���֡������ȷ��С�������λ��
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
		//�����ȡ����6������
		for (int i = 1; i <= 6; i++) {
			scanf("%lf", &score[i]);
		}
		//��ȡ����
		scanf("%s", &name);
		
		Bubble_sort(score, 7);
		
		//�����֮��
		double sum = 0;
		for (int i = 1; i <= 5; i++) {
				sum += score[i];
		}
		//�����
		printf("%s %.2lf\n", name, sum / 5.0);
	}
	return 0;
}