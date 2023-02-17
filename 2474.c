#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    char temp;
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    char str1[100];
    char str2[100];
    scanf("%s %s", str1, str2);
    reverseString(str1);
    reverseString(str2);
    strcat(str1, str2);
    printf("%s\n", str1);
}