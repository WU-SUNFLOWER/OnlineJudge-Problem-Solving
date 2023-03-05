#include <stdio.h>

int isLetter(char ch) {
    return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z';
}

int main() {
    char ch;
    char str[100];
    int layer = 0;
    int targetLayer;
    gets(str);
    scanf("%d", &targetLayer);
    for (int i = 0; ch = str[i]; i++) {
        if (ch == '(') {
            layer++;
        } else if (ch == ')') {
            layer--;
        } else if (layer == targetLayer && isLetter(ch) && str[i + 1] != '(') {
            printf("%c\n", ch);
        }
    }
}