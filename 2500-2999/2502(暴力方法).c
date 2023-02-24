#include <stdio.h>
#include <string.h>

int main() {
    int length;
    char str1[200];
    char str2[200];
    gets(str1);
    gets(str2);
    strcat(str1, str2);
    length = strlen(str1);
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j <= length - 2 - i; j++) {
            if (str1[j] > str1[j + 1]) {
                char temp = str1[j];
                str1[j] = str1[j + 1];
                str1[j + 1] = temp;
            }
        }
    }
    puts(str1);
}