#include <stdio.h>
#include <string.h>

void buildNext(char str[], int next[]) {
    int i = 1;
    int k = 0;
    next[i] = 0;
    while (i < str[0]) {
        if (k == 0 || str[k] == str[i]) {
            i++;
            k++;
            next[i] = k;
        } else {
            k = next[k];
        }
    }
}

int main() {
    char buf[100];
    char str[100];
    int next[100];
    gets(buf);
    int len = strlen(buf);
    str[0] = len;
    strcpy(str + 1, buf);
    buildNext(str, next);
    for (int i = 1; i <= len; i++) {
        printf(i < len ? "%d " : "%d\n", next[i]);
    }
}