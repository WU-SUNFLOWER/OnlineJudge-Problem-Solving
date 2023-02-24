#include <stdio.h>
#include <string.h>

int main() {
    int len;
    int pos;
    char str1[100];
    char str2[100];
    scanf("%d", &len);
    scanf("%s", str1);
    scanf("%d", &pos);
    strcpy(str2, &str1[pos - 1]);
    puts(str2);
}