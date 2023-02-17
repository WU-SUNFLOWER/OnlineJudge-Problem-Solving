#include <stdio.h>

int main() {
    int s;
    char num[105];
    scanf("%s %d", num, &s);
    //删数
    while (s-- > 0) {
        int i = 0;
        while (num[i] <= num[i + 1]) {
            i++;
        }
        while (num[i] != '\0') {
            num[i] = num[i + 1];
            i++;
        }
    }
    //输出
    int isFirst = 1;
    for (int i = 0; num[i]; i++) {
        if (isFirst && num[i] != '0' || !isFirst) {
            putchar(num[i]);
            isFirst = 0;
        }
    }
    putchar('\n');
}