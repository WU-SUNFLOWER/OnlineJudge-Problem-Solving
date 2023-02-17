#include <stdio.h>
#include <string.h>

int main() {
    char str[101];
    gets(str);
    for (int i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
}