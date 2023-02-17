#include <stdio.h>
#include <math.h>

void sortByAbs(int arr[], int length) {
    int temp;
    for (int i = 0; i < length - 1; i++) {
        int flag = 1;
        for (int j = i; j <= length - 2; j++) {
            if (abs(arr[j]) > abs(arr[j + 1])) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 0;
            }
        }
        if (flag) {
            break;
        }
    }
}

int main() {
    int totalNum;
    int NegativeNumberArr[100];
    while (~scanf("%d", &totalNum)) {
        int temp;
        int flag = 0;  //用以标记multip是否已有有效值
        int multip;
        int negativeNum = 0;
        //获取数据，并将所有正数相乘
        for (int i = 0; i < totalNum; i++) {
            scanf("%d", &temp);
            if (temp > 0 && !flag) {
                flag = 1;
                multip = temp;
            }
            else if (temp > 0) {
                multip *= temp;
            }
            else if (temp < 0) {
                NegativeNumberArr[negativeNum++] = temp;
            }
        }
        //处理负数
        //第一种情况：只有一个负数，且已有正数相乘之结果，则直接放弃处理
        //第二种情况：只有一个负数，没有正数相乘的结果，则将它作为答案
        //第三种情况：有偶数个负数，则直接将答案乘以所有负数
        //第四种情况：有奇数个负数，则根据绝对值大小对所有负数进行排序，放弃绝对值最小的负数
        if (negativeNum > 1) {
            if (!flag) {
                multip = 1;
                flag = 1;
            }
            if (negativeNum % 2 == 0) {
                while (negativeNum > 0) {
                    multip *= NegativeNumberArr[negativeNum - 1];
                    negativeNum--;
                }
            } else {
                sortByAbs(NegativeNumberArr, negativeNum);
                while (negativeNum > 1) {
                    multip *= NegativeNumberArr[negativeNum - 1];
                    negativeNum--;
                }
            }
        }
        else if (negativeNum == 1 && !flag) {
            flag = 1;
            multip = NegativeNumberArr[0];
        }
        //输出
        printf("%d\n", flag ? multip : 0);
    }
}