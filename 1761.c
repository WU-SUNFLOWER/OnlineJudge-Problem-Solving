#include <stdio.h>
#include <string.h>

int check(char* p) {
    return (p[0] == 's' || p[0] == 'S') &&
           (p[1] == 'a' || p[1] == 'A') &&
           (p[2] == 'l' || p[2] == 'L') &&
           (p[3] == 't' || p[3] == 'T');
}

int main() {
    char str[1000];
    char ansStr[1000];
    char replaceStr[] = "soy sauce";
    while (gets(str) != NULL) {
        int idx = 0;
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            if (check(&str[i])) {
                for (int j = 0; replaceStr[j]; j++) {
                    ansStr[idx++] = replaceStr[j];
                }
                i += 3;
            } else {
                ansStr[idx++] = str[i];
            }
        }
        ansStr[idx] = '\0';
        puts(ansStr);
    }
}