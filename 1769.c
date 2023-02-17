#include <stdio.h>

int main() {
    int flag = 1;
    char str[1000];
    gets(str);
    for (int i = 0; str[i]; i++) {
        char ch = str[i];
        if ('0' <= ch && ch <= '9' || 'a' <= ch && ch <= 'z' ||'A' <= ch && ch <= 'Z') {
            flag = 1;
            putchar(ch);
        } 
        else if (flag) {
            putchar('\n');
            flag = 0;
        }
    }
}