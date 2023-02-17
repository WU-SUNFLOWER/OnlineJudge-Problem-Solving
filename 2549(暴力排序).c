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
    //读取字典,并生成经过排序的影子字典
    while (1) {
        scanf("%s", dict[dictSize]);
        if (dict[dictSize][0] == '*') {
            break;
        }
        //生成影子字典
        strcpy(shadowDict[dictSize], dict[dictSize]);
        sortString(shadowDict[dictSize]);
        //生成索引数组
        index[dictSize] = dictSize;
        dictSize++;
    }
    //按照字典序先对字典进行排序
    for (int i = 0; i < dictSize - 1; i++) {
        for (int j = 0; j <= dictSize - 2 - i; j++) {
            if (strcmp(dict[index[j]], dict[index[j + 1]]) > 0) {
                int temp = index[j];
                index[j] = index[j + 1];
                index[j + 1] = temp;
            }
        }
    }
    //求解
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