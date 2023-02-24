#include <stdio.h>

char Data[100][50];  // 储存一堆字符串的二维数组
int _weight[100];  // 记录每个字符串的权值
int _index[100];  // 供索引排序使用的索引数组

int computeWeight(char str[], int length) {
    int weight = 0;
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (str[i] > str[j]) weight++;
        }
    }
    return weight;
}

int main() {
    int strLength;
    int strCnt;
    while (~scanf("%d %d", &strLength, &strCnt)) {
        // 读取字符串,并计算每个字符串的权值
        for (int i = 0; i < strCnt; i++) {
            scanf("%s", Data[i]);
            _index[i] = i;
            _weight[i] = computeWeight(Data[i], strLength);
        }
        // 按权值从小到大排序字符串
        for (int i = 0; i < strCnt - 1; i++) {
            for (int j = 0; j < strCnt - 1 - i; j++) {
                if (_weight[_index[j]] > _weight[_index[j + 1]]) {
                    int t = _index[j];
                    _index[j] = _index[j + 1];
                    _index[j + 1] = t;
                }
            }
        }
        // 输出答案
        for (int i = 0; i < strCnt; i++) {
            puts(Data[_index[i]]);
        }
    }
}