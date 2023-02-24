#include <stdio.h>

int main() {
    char s1[5];
    scanf("%s", s1);
    for (int i = 0; s1[i]; i++) {
        printf("%c ", s1[i]);
    }
}