#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000

char NumString1[N];
char NumString2[N];

int* createIntArray(int length) {
    int* p = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        p[i] = 0;
    }
    return p;
}

int main() {
    int temp;
    scanf("%d", &temp);
    while (~scanf("%s %s", NumString1, NumString2)) {
        //׼������
        int len1 = strlen(NumString1);
        int len2 = strlen(NumString2);
        int totalLen = len1 > len2 ? len1 : len2;
        int* NumArray1 = createIntArray(totalLen + 1);
        int* NumArray2 = createIntArray(totalLen + 1);
        //���ַ��������е����ݽ���¼��
        for (int i = 0; i < len1; i++) {
            NumArray1[i] = NumString1[len1 - i - 1] - 'a' + 1;
        }
        for (int i = 0; i < len2; i++) {
            NumArray2[i] = NumString2[len2 - i - 1] - 'a' + 1;
        }
        //��ʼģ��26���Ƽӷ�
        int carry = 0;
        for (int i = 0; i <= totalLen; i++) {
            int sum = NumArray1[i] + NumArray2[i] + carry;
            NumArray1[i] = (sum - 1) % 26 + 1;
            carry = (sum - 1) / 26;
        }
        //������
        for (int i = totalLen; i >= 0; i--) {
            if (i == totalLen && NumArray1[i] == 0) {
                continue;
            }
            putchar('a' + NumArray1[i] - 1);
        }
        putchar('\n');
        putchar('\n');
        //���������ͷ��ڴ�
        free(NumArray1);
        free(NumArray2);
    }
}