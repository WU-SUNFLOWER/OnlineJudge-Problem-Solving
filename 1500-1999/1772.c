#include <stdio.h>
#include <string.h>

int main() {
    int length;
    char str[100];
    gets(str);
    length = strlen(str);
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j <= length - 2 - i; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
    puts(str);
}