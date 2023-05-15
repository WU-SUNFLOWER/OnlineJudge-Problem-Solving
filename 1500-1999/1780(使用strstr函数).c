#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char subStr[100];
    char replacedStr[100];
    char buf[100];
    scanf("%s %s %s", str, subStr, replacedStr);
    char* ptr = strstr(str, subStr);
    int flag = 0;
    int len_str = strlen(str);
    int len_sub = strlen(subStr);
    int len_replaced = strlen(replacedStr);
    while (ptr) {
        flag = 1;
        strcpy(buf, ptr + len_sub);
        strcpy(ptr, replacedStr);
        strcpy(ptr + len_replaced, buf);
        ptr = strstr(ptr + len_replaced, subStr);
    }
    puts(flag ? str : "NO");
}