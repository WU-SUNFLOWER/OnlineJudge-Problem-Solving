#include <stdio.h>

//salt
int check(char* p) {
    return (p[0] == 's' || p[0] == 'S') &&
           (p[1] == 'a' || p[1] == 'A') &&
           (p[2] == 'l' || p[2] == 'L') &&
           (p[3] == 't' || p[3] == 'T');
}

int main() {
    char str[1000];
    while (gets(str) != NULL) {
        for (int i = 0; str[i]; i++) {
            if (check(&str[i])) {
                printf("%s\n", str);
                break;
            }
        }
    }
}