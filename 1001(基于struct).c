#include <stdio.h>

struct hm {
	double value;
	double time;
	double rate;
} hwArr[20];

void Bubble_sort(struct hm arr[], int size) {
	int j,i;
	struct hm tem;
	for (i = 0; i < size-1;i ++) {
		int count = 0;
		for (j = 0; j < size-1 - i; j++)	{
			if (arr[j].rate < arr[j+1].rate) {
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
    int totalPaperNum;
    double totalTime;	
	while (scanf("%d %lf",&totalPaperNum, &totalTime) != EOF) {
		if (totalPaperNum == 0 && totalTime == 0) break;
		double ans = 0;
		for (int n = 0; n < totalPaperNum; n++) {
			scanf("%lf %lf", &hwArr[n].time, &hwArr[n].value);
			hwArr[n].rate = hwArr[n].value / hwArr[n].time;
		}
		Bubble_sort(hwArr, totalPaperNum);
		for (int n = 0; n < totalPaperNum; n++) {
			if (totalTime < hwArr[n].time) {
				ans += totalTime * hwArr[n].rate;
				totalTime = 0;
				break;
			} else {
				ans += hwArr[n].value;
				totalTime -= hwArr[n].time;
			}
		}
		printf("%.2lf\n", ans);
	}	
	return 0;
}