#include <stdio.h>
#include <string.h>

void sortString(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j <= length - 2 - i; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main() {
    int index[20];
    char dict[20][9];
    char shadowDict[20][9];
    char dictSize = 0;
    //��ȡ�ֵ�,�����ɾ��������Ӱ���ֵ�
    while (1) {
        scanf("%s", dict[dictSize]);
        if (dict[dictSize][0] == '*') {
            break;
        }
        //����Ӱ���ֵ�
        strcpy(shadowDict[dictSize], dict[dictSize]);
        sortString(shadowDict[dictSize]);
        //������������
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
        sortString(word);
        for (int i = 0; i < dictSize; i++) {
            if (strcmp(word, shadowDict[index[i]]) == 0) {
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