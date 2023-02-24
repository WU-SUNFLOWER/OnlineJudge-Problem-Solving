#include <stdio.h>

int main() {
    char str[100];
    gets(str);
    int letterCount = 0;
    int numberCount = 0;
    int spaceCount = 0;
    int otherCount = 0;
    for (int i = 0; str[i]; i++) {
        char ch = str[i];
        if ('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z') {
            letterCount++;
        }
        else if ('0' <= ch && ch <= '9') {
            numberCount++;
        }
        else if (ch == ' ') {
            spaceCount++;
        }
        else {
            otherCount++;
        }
    }
    printf("%d %d %d %d\n", letterCount, numberCount, spaceCount, otherCount);
}