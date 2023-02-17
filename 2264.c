#include <stdio.h>

const int Range = 5;

int main() {
    int temp;
    int matrix[25];
    int index[25];
    int target[] = {0, 4, 20, 24};
    while (~scanf("%d", &matrix[0])) {
        //读取矩阵，并获知最大值
        int max = matrix[0];
        int maxPos = 0;
        index[0] = 0;
        for (int i = 1; i < Range * Range; i++) {
            scanf("%d", &matrix[i]);
            index[i] = i;
            matrix[i] > max && (max = matrix[i], maxPos = i);
        }
        //运用选择排序求解四个最小值
        for (int i = 0; i < 4; i++) {
            int k = i;
            for (int j = i + 1; j < Range * Range; j++) {
                if (matrix[index[j]] < matrix[index[k]]) {
                    k = j;
                }
            }
            temp = index[i];
            index[i] = index[k];
            index[k] = temp;
        }
        //处理最大值的交换
        matrix[maxPos] = matrix[12];
        matrix[12] = max;
        for (int j = 0; j < 4; j++) {
            if (index[j] == 12) {
                index[j] = maxPos;
            }
        }
        //放置四个最小值
        for (int i = 0; i < 4; i++) {
            //交换矩阵
            temp = matrix[index[i]];
            matrix[index[i]] = matrix[target[i]];
            matrix[target[i]] = temp;
            //防止交换后原先index数组中的索引引用失效
            for (int j = i + 1; j < 4; j++) {
                if (index[j] == target[i]) {
                    index[j] = index[i];
                }
            }
        }
        //输出数组
        for (int i = 1; i <= Range * Range; i++) {
            printf("%d ", matrix[i - 1]);
            if (i % Range == 0) {
                printf("\n");
            }
        }
        printf("\n");
    }
}