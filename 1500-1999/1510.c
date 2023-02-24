#include <stdio.h>

int main() {
    char str[100];
    gets(str);
    for (int i = 0; str[i]; i++) {
        if ('a' <= str[i] && str[i] <= 'z') {
            str[i] = (str[i] + 1 - 'a') % 26 + 'a';
        }
        else if ('A' <= str[i] && str[i] <= 'Z') {
            str[i] = (str[i] + 1 - 'A') % 26 + 'A';
        }
    }
    puts(str);
}