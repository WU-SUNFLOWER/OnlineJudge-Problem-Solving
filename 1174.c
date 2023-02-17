#include <stdio.h>

int main() {
    int idx = -1;
    int flag = 0;
    char str[81];
    char ans[81];
    gets(str);
    for (int i = 0; str[i]; i++) {
        if ('0' <= str[i] && str[i] <= '9') {
            flag = 0;
            ans[++idx] = str[i];
        }
        else if (flag == 0) {
            flag = 1;
            ans[++idx] = '*';
        }
    }
    ans[++idx] = '\0';
    printf("%s", ans);
}