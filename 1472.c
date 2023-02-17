#include <stdio.h>
#include <string.h>

int main() {
    char str[6];
    gets(str);
    int len = strlen(str);
    printf("%d\n", len);
    for (int i = 0; i < len; i++) {
        putchar(str[i]);
        putchar(i != len - 1 ? ' ' : '\n');
    }
    for (int i = len - 1; i >= 0; i--) {
        putchar(str[i]);
    }
}