#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
windows下直接粘贴utf-8中文字符，程序接收的时候会出问题！
请使用管道符调试本程序！
*/

void parse(char str[], char list[]) {
    int idx = 0;
    char* token = strtok(str, " ");
    while (token != NULL) {
        //printf("token=%s\n", token);
        if (isdigit(*token)) {
            list[idx++] = atoi(token);
        }
        token = strtok(NULL, " ");
    }
    list[idx] = '\0';
}

int main() {
    char str1[100] = {0};
    char str2[100];
    char list1[100];
    char list2[100];
    gets(str1);
    gets(str2);
    gets(str2);
    parse(str1, list1);
    parse(str2, list2);
    puts(strstr(list1, list2) ? "是" : "否");
}