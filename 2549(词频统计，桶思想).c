#include <stdio.h>
#include <string.h>

int checkPermutation(char str1[], char str2[]) {
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }
    int total = 0;
    int bucket[128] = {0};
    //这种处理方法的关键在于，
    //只需要满足str1中率先出现的字符，
    //在后续的遍历过程中都能在str2中逐个得以匹配，
    //就可以保证两个字符串是相同字符集的排列组合。（实际上这已经证明了命题的必要性）
    //从充分性上讲，倘若在str1中“率先”出现的某个字符，在str2中无法得到匹配，
    //那么就意味着在str2中与之对应存在一个相异的字符。也就是说
    //这种情况下str1和str2对应的肯定不是同一个字符集。
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
    //读取字典
    while (1) {
        scanf("%s", dict[dictSize]);
        if (dict[dictSize][0] == '*') {
            break;
        }
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