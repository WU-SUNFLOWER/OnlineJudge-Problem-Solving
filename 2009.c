#include <stdio.h>

int BinarySearch(int* arr, int length, int target) {
    int i = 0;
    int j = length - 1;
    int midNum;
    while (i <= j) {
        midNum = arr[(i + j) >> 1];
        if (midNum == target) {
            return 1;
        }
        else if (midNum > target) {
            j--;
        }
        else {
            i++;
        }
    }
    return 0;
}

int main() {
    int apperRowArr[] = {0, 0, 0, 0, 0, 0};
    int map[6][32] = {
        {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63},
        {2, 3, 6, 7, 10, 11, 14, 15, 18, 19, 22, 23, 26, 27, 30, 31, 34, 35, 38, 39, 42, 43, 46, 47, 50, 51, 54, 55, 58, 59, 62, 63},
        {4, 5, 6, 7, 12, 13, 14, 15, 20, 21, 22, 23, 28, 29, 30, 31, 36, 37, 38, 39, 44, 45, 46, 47, 52, 53, 54, 55, 60, 61, 62, 63},
        {8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 26, 27, 28, 29, 30, 31, 40, 41, 42, 43, 44, 45, 46, 47, 56, 57, 58, 59, 60, 61, 62, 63},
        {16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63},
        {32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63},
    };
    //采集出现行号
    int firstRow = -1;
    int tempRow;
    while (scanf("%d", &tempRow) != EOF && tempRow != 0) {
        apperRowArr[tempRow - 1] = 1;
        if (firstRow < 0) {
            firstRow = tempRow - 1;
        }
    };
    //搜索
    for (int i = 0; i < 32; i++) {
        int flag = 1;
        int curNum = map[firstRow][i];
        for (int j = 0; j < 6 && flag; j++) {
            if (j == firstRow) {
                continue;
            }
            //处理非出现行
            if (apperRowArr[j] == 0) {
                flag = !BinarySearch(&map[j][0], 32, curNum);
            } 
            //处理出现行
            else {
                flag = BinarySearch(&map[j][0], 32, curNum);
            }
        }
        if (flag) {
            printf("%d\n", curNum);
            break;
        }
    }
}