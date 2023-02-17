#include <stdio.h>
#include <stdlib.h>

int* createIntArray(int length) {
    int* arr = (int*)malloc(sizeof(int) * length);
    return arr;
}

double* createDoubleArray(int length) {
    double* arr = (double*)malloc(sizeof(double) * length);
    return arr;
}

int* createIndexArray(int length) {
	int* arr = createIntArray(length);
	int i;
	for (i = 0; i < length; i++) {
		arr[i] = i;
	}
	return arr;
}

void DoubleArrayDownOrderIndexSort(double* reallyArray, int* indexArray, int length) {
	int i;
	int j;
	for (i = 0; i < length - 1; i++) {
		int flag = 0;
		for (j = 0; j < length - 1 - i; j++) {
			if (reallyArray[indexArray[j]] < reallyArray[indexArray[j + 1]]) {
				int temp = indexArray[j];
				indexArray[j] = indexArray[j + 1];
				indexArray[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) {
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

		double* singlePaperArray_Time = createDoubleArray(totalPaperNum);
		double* singlePaperArray_Value = createDoubleArray(totalPaperNum);
		double* singlePaperArray_Rate = createDoubleArray(totalPaperNum);
		int* myIndexArray = createIndexArray(totalPaperNum); 
		   
		for (int n = 0; n < totalPaperNum; n++) {
			scanf("%lf %lf", &singlePaperArray_Time[n], &singlePaperArray_Value[n]);
			singlePaperArray_Rate[n] = singlePaperArray_Value[n] / singlePaperArray_Time[n];
		}
			
		DoubleArrayDownOrderIndexSort(singlePaperArray_Rate, myIndexArray, totalPaperNum);
		printf("----------------\n");
		for (int n = 0; n < totalPaperNum; n++) {
			int idx = myIndexArray[n];
            printf("%lf\n", singlePaperArray_Rate[idx]);
			if (totalTime < singlePaperArray_Time[idx]) {
				ans += totalTime * singlePaperArray_Rate[idx];
				totalTime = 0;
				break;
			} else {
				ans += singlePaperArray_Value[idx];
				totalTime -= singlePaperArray_Time[idx];
			}
		}
		printf("----------------\n");
		printf("%.2lf\n", ans);
		
	}
    
	return 0;
}