#include <stdio.h>
#include <string.h>

void del_char(char* str, char ch) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == ch) {
            for (int j = i; str[j]; j++) {
                str[j] = str[j + 1];
            }
            //前移后str[i]已被更新，所以要重新校验
            i--;
        }
    }
}

int main() {
    char ch;
    char str[100];
    scanf("%c %s", &ch, str);
    del_char(&str[0], ch);
    printf("%s\n", str);
}