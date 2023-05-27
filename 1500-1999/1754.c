#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//对顺序表中的子序列data[low..high]进行一趟快速排序，返回枢轴下标
int Partition(int ar[], int low, int high) {
	int pivot = ar[high];				//枢轴记录关键字保存在pivot中
	while (low < high) {
	    while (low < high && ar[low] <= pivot) ++low;
		ar[high] = ar[low];			//把比枢轴关键字大的记录移到高端
		while (low < high && ar[high] > pivot) --high;
		ar[low] = ar[high];			//把比枢轴关键字小的记录移到低端
	}
	ar[low] = pivot;		 		//将暂存在data[0]的枢轴记录移到最终位置
	return low;
}

int main() {
    char str[100];
	int ar[100];
    while (gets(str) != NULL) {
        int length = 0;
        char* ptr = strtok(str, " ");
        while (ptr != NULL) {
            int num = atoi(ptr);
            if (num <= 0) break;
            ar[length++] = num;
            ptr = strtok(NULL, " ");
        }
    	Partition(ar, 0, length - 1);
        for (int i = 0; i < length; i++) {
            printf(i == length - 1 ? "%d\n" : "%d ", ar[i]);
        }
    }
	return 0;
}
