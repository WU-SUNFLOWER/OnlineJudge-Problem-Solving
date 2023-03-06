#include <stdio.h>
#include <string.h>

int check(char ch) {
    return '0' <= ch && ch <= '9' || 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z';
}

int main() {
    char email[100];
    scanf("%s", email);
    int len = strlen(email);
    if (
        email[len - 1] == 'm'
        && email[len - 2] == 'o'
        && email[len - 3] == 'c'
        && email[len - 4] == '.'
    ) {
        char ch;
        int atCnt = 0;
        int flag = 1;
        email[len - 4] = '\0';
        for (int i = 0; ch = email[i]; i++) {
            if (ch == '.') {
                flag = 0;
                break;
            }
            else if (ch == '@') {
                char ch_pre = email[i - 1];
                char ch_next = email[i + 1];
                if (atCnt || !check(ch_pre) || !check(ch_next)) {
                    flag = 0;
                    break;
                } else {
                    atCnt = 1;
                }
            }
            else if (!check(ch) && ch != '_') {
                flag = 0;
                break;
            }
        }
        flag = flag && atCnt;
        puts(flag ? "YES" : "NO");
    } else {
        puts("NO");
    }
}