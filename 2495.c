#include <stdio.h>

char Data[100][50];  // ����һ���ַ����Ķ�ά����
int _weight[100];  // ��¼ÿ���ַ�����Ȩֵ
int _index[100];  // ����������ʹ�õ���������

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
        // ��ȡ�ַ���,������ÿ���ַ�����Ȩֵ
        for (int i = 0; i < strCnt; i++) {
            scanf("%s", Data[i]);
            _index[i] = i;
            _weight[i] = computeWeight(Data[i], strLength);
        }
        // ��Ȩֵ��С���������ַ���
        for (int i = 0; i < strCnt - 1; i++) {
            for (int j = 0; j < strCnt - 1 - i; j++) {
                if (_weight[_index[j]] > _weight[_index[j + 1]]) {
                    int t = _index[j];
                    _index[j] = _index[j + 1];
                    _index[j + 1] = t;
                }
            }
        }
        // �����
        for (int i = 0; i < strCnt; i++) {
            puts(Data[_index[i]]);
        }
    }
}