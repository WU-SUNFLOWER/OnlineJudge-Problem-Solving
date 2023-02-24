#include <stdio.h>
#include <string.h>

int main() {
    int k;
    int length;
    char str[100];
    scanf("%s %d", str, &k);
    length = strlen(str);
    for (int i = 1; i <= length; i++) {
        putchar(str[i - 1]);
        if (i % k == 0) {
            putchar('\n');
        }
    }
}