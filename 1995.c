#include <stdio.h>
#include <string.h>

/*
编程实现将字符串中最短的单词输出，在主函数中输入字符串，
编写一个函数完成最短单词的查找，如果有多个相同长度单词，则只输出第一个最短单词。
假设单词之间用空格分隔（一个或多个空格），findshort(s1,s2)函数完成s1串是最短单词的查找，找到的最短单词存储于s2中。

输入:
Happy new year

输出:
new
*/

int main() {
    char ch;
    char ansWord[20] = {'\0'};
    char tempWord[20] = {'\0'};
    int tempLen = 0;
    int ansLen;
    int isValidWordsMeeted = 0;
    int isAnsLenInitialized = 0;
    while (1) {
        ch = getchar();
        if (isValidWordsMeeted) {
            if (ch == ' ' || ch == EOF || ch == '\n') {
                if (tempLen < ansLen || !isAnsLenInitialized) {
                    ansLen = tempLen;
                    strcpy(ansWord, tempWord);
                    ansWord[ansLen] = '\0';
                    isAnsLenInitialized = 1;
                }
                isValidWordsMeeted = 0;
                if (ch == EOF || ch == '\n') {
                    break;
                }
            } 
            else {
                tempWord[tempLen++] = ch;
            }
        }
        else if ('a' <= ch && ch <= 'z'|| 'A' <= ch && ch <= 'Z') {
            tempLen = 1;
            tempWord[tempLen - 1] = ch;
            isValidWordsMeeted = 1;
        }
        else if (ch == EOF || ch == '\n') {
            break;
        }
    }
    printf("%s\n", ansWord);
}