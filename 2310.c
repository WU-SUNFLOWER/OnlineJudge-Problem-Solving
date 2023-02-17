#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    char tempString[100];
    int total = 0;
    int count[26] = {0};
    while (gets(tempString) != NULL) {
        for (int i = 0; tempString[i]; i++) {
            char ch = tempString[i];
            if ('A' <= ch && ch <= 'Z') {
                count[ch - 'A']++;
                total = max(total, count[ch - 'A']);
            }
        }
    }
    for (int i = 1; i <= total; i++) {
        for (int j = 0; j < 26; j++) {
            printf(total - i >= count[j] ? "  " : "* ");
        }
        putchar('\n');
    }
    for (int j = 0; j < 26; j++) {
        printf("%c ", 'A' + j);
    }
}