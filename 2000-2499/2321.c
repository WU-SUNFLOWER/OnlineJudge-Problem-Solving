#include <stdio.h>

int main() {
    char str[1001];
    while (gets(str) != NULL) {
        int i = 0;
        while (str[i]) {
            if (str[i] == 'w' && str[i + 1] == 'e') {
                printf("you");
                i += 2;
            } else {
                printf("%c", str[i++]);
            }
        }
        printf("\n");
    }
}