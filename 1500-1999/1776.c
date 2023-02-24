#include <stdio.h>
#include <string.h>

int main() {
    int length;
    char str[100];
    char words[100][20] = {0};
    char symbols[100][20] = {0};
    //symbolMap[i]（i≥0）表示在第i个单词后有符号存在
    int symbolMap[100] = {0};
    gets(str);
    length = strlen(str);
    int symbolIdx = -1;
    int wordIdx = -1;
    int symbolLetterIdx = 0;
    int wordLetterIdx = 0;
    int isBetweenWords = 1;
    int isStarting = 1;
    for (int i = 0; i < length; i++) {
        char ch = str[i];
        if ('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z') {
            if (isBetweenWords || isStarting) {
                isBetweenWords = 0;
                wordLetterIdx = 0;
                wordIdx++;
            }
            words[wordIdx][wordLetterIdx++] = ch;
        } else {
            if (isBetweenWords == 0 || isStarting) {
                isBetweenWords = 1;
                symbolLetterIdx = 0;
                symbolIdx++;
            }
            symbolMap[wordIdx + 1] = 1;
            symbols[symbolIdx][symbolLetterIdx++] = ch;
        }
        isStarting = 0;
    }
    int j = 0;
    for (int i = -1; i <= wordIdx; i++) {
        i >= 0 && printf("%s", words[wordIdx - i]);
        symbolMap[i + 1] && printf("%s", symbols[j++]);
    }
}