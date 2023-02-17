#include <stdio.h>

int main() {
    char ch;
    char str[200];
    int isFirstFinishSymbol = 0;
    gets(str);
    for (int i = 0; str[i]; i++) {
        ch = str[i];
        //第一种情况，碰到合法字符就输出
        if (
            'a' <= ch && ch <= 'z' ||
            'A' <= ch && ch <= 'Z' ||
            '0' <= ch && ch <= '9'
        ) {
            putchar(ch);
            isFirstFinishSymbol = 1;
        }
        //第二种情况：第一碰到截断字符，就输出换行符
        else if (isFirstFinishSymbol) {
            putchar('\n');
            isFirstFinishSymbol = 0;
        }
    }
}