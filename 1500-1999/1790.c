#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char str_ans[100] = {0};
    char str_num[100] = {0};
    int idx_ans = 0;
    int idx_num = 0;
    gets(str);
    char ch;
    for (int i = 0; ch = str[i]; i++) {
        if ('0' <= ch && ch <= '9') {
            str_num[idx_num++] = ch;
        } else {
            str_ans[idx_ans++] = ch;
        }
    }
    int pos = strlen(str_ans) / 2;
    char buf[100];
    strcpy(buf, str_ans + pos);
    strcpy(str_ans + pos, str_num);
    strcat(str_ans, buf);
    puts(str_ans);
}