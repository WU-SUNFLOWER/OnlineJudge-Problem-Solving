#include <stdio.h>
#include <stdlib.h>

//给你一组数(未排序)，请你写设计一个程序：求出里面个数最多的数（可以不连续出现），
//并输出这个数的长度。例如：给你的数是：1、 2、 3、 3、 4、 4、 5、 5、 5 、6,
//其中只有6组数：1, 2, 3-3, 4-4, 5-5-5 and 6. 最长的是5那组，长度为3。所以输出3。

//第一行为整数t((1 ≤ t ≤ 10))，表示有n组测试数据。
//每组测试数据包括两行，第一行位数组的长度n (1 ≤ n ≤ 10000)。
//第二行为n个整数，所有整数Mi的范围都是(1 ≤ Mi ≤ 2^32)

//输入：
//1
//10
//1 2 3 3 4 4 5 5 5 6
//输出：
//3

int* createIntArray(int length) {
	return (int*)malloc(sizeof(int) * length);
}

//快速排序
//k传入1表示升序排序，传入-1表示降序排序
void QuickSort(int* arr, int leftBorder, int rightBorder, int k) {
    int i = leftBorder;
    int j = rightBorder;
    int refNum = arr[leftBorder];
    //如果leftBorder >= rightBorder，说明左右区间重合，说明以递归至最小子数组，直接结束递归即可
    if (leftBorder < rightBorder) {
        //通过哨兵i、j扫描数组，将数组裂成左右两部分
        while (i < j) {
            //通过哨兵j从右向左搜索比refNum小的数，以便将其调往左侧
            while (i < j && arr[j] * k >= refNum * k) {
                j--;
            }
            //通过哨兵i从左向右搜索比refNum大的数
            //以便将其调往右侧
            while (i < j && arr[i] * k <= refNum * k) {
                i++;
            }
            if (i < j) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
        //扫描完成后，将refNum置于两个新子数组的分界位置，即i、j重合处
        arr[leftBorder] = arr[i];
        arr[i] = refNum;
        //最后利用递归处理裂得的两个新子数组
        QuickSort(arr, leftBorder, i - 1, 1);
        QuickSort(arr, i + 1, rightBorder, 1);
    }
}

int getMax(int x, int y) {
	return x > y ? x : y;
}

int main() {
	int TestNum;
	scanf("%d", &TestNum);
	while ((TestNum--) > 0) {
		int length;
		int ans = 1;
		int curAns = 1;
		scanf("%d", &length);
		int* MyArray = createIntArray(length);
		for (int i = 0; i < length; i++) {
			scanf("%d", &MyArray[i]);
		}
		QuickSort(MyArray, 0, length - 1, 1);
		for (int i = 1; i < length; i++) {
			if (MyArray[i] == MyArray[i - 1]) {
				curAns++;
			} else {	
				curAns = 1;
			}
			ans = getMax(ans, curAns);
		}
		free(MyArray);
		printf("%d\n", ans);
	}
}