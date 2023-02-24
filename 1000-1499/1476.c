#include <stdio.h>

int main() {
    char str[100];
    gets(str);
    for (int i = 0; str[i]; i++) {
        char start = str[i] < 'a' ? 'A' : 'a';
        str[i] = (str[i] + 4 - start) % 26 + start;
    }
    printf("%s\n", str);
}