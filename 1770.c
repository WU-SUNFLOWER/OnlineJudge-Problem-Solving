#include <stdio.h>

int main() {
    char ch;
    char str[100];
    int count = 0;
    gets(str);
    ch = getchar();
    for (int i = 0; str[i]; i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    printf("%d", count);
}