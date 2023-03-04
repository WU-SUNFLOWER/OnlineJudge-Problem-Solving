#include <stdio.h>
#include <stdbool.h>

int main() {
    char str[100];
    long long num = 0;
    char ch;
    bool isReadingNum = false;
    gets(str);
    for (int i = 0; true; i++) {
        ch = str[i];
        if ('0' <= ch && ch <= '9') {
            if (isReadingNum) {
                num = num * 10 + (ch - '0');
            } else {
                num = ch - '0';
                isReadingNum = true;
            }
        }
        else if (isReadingNum) {
            printf("%lld    ", num);
            isReadingNum = false;
        }
        if (ch == '\0') break;
    }
}