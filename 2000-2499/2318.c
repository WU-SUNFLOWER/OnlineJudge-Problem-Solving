#include <stdio.h>

int main() {
    char str[100];
    gets(str);
    for (int i = 0; str[i]; i++) {
        if ('a' <= str[i] && str[i] <= 'z' || 'A' <= str[i] && str[i] <= 'Z') {
            putchar(str[i]);
        }
    }
}