#include <stdio.h>
#include <string.h>

void reverse(char* str, int length) {
    for (int i = 0; i < length / 2; i++) {
        char t = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = t;
    }
}

int main() {
    char buf[100];
    while (~scanf("%s", buf)) {
        int len = strlen(buf);
        if (len % 2) {
            reverse(buf, len / 2);
            reverse(buf + 1 + len / 2, len / 2);
        } else {
            reverse(buf, len / 2);
            reverse(buf + len / 2, len / 2);
        }
        printf("%s\n\n", buf);
    }
}