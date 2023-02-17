#include <stdio.h>
#include <string.h>

int checkPermutation(char str1[], char str2[]) {
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }
    int total = 0;
    int bucket[128] = {0};
    //���ִ������Ĺؼ����ڣ�
    //ֻ��Ҫ����str1�����ȳ��ֵ��ַ���
    //�ں����ı��������ж�����str2���������ƥ�䣬
    //�Ϳ��Ա�֤�����ַ�������ͬ�ַ�����������ϡ���ʵ�������Ѿ�֤��������ı�Ҫ�ԣ�
    //�ӳ�����Ͻ���������str1�С����ȡ����ֵ�ĳ���ַ�����str2���޷��õ�ƥ�䣬
    //��ô����ζ����str2����֮��Ӧ����һ��������ַ���Ҳ����˵
    //���������str1��str2��Ӧ�Ŀ϶�����ͬһ���ַ�����
    for (int i = 0; str1[i]; i++) {
        if (++bucket[str1[i]] == 1) {
            total++;
        }
        if (--bucket[str2[i]] == 0) {
            total--;
        }
    }
    return total == 0;
}

int main() {
    int index[20];
    char dict[20][9];
    char dictSize = 0;
    //��ȡ�ֵ�
    while (1) {
        scanf("%s", dict[dictSize]);
        if (dict[dictSize][0] == '*') {
            break;
        }
        index[dictSize] = dictSize;
        dictSize++;
    }
    //�����ֵ����ȶ��ֵ��������
    for (int i = 0; i < dictSize - 1; i++) {
        for (int j = 0; j <= dictSize - 2 - i; j++) {
            if (strcmp(dict[index[j]], dict[index[j + 1]]) > 0) {
                int temp = index[j];
                index[j] = index[j + 1];
                index[j + 1] = temp;
            }
        }
    }
    //���
    char word[9];
    while (~scanf("%s", word)) {
        int isFirstAns = 1;
        for (int i = 0; i < dictSize; i++) {
            if (checkPermutation(word, dict[index[i]])) {
                if (isFirstAns) {
                    isFirstAns = 0;
                } else {
                    putchar(' ');
                }
                printf("%s", dict[index[i]]);
            }
        }
        if (isFirstAns) {
            printf(":(");
        }
        putchar('\n');
    }
}