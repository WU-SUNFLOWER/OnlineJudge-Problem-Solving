#include <stdio.h>

int max(int a, int b) {
    return a < b ? b : a;
}

int main() {
    char ch;
    char str[100];
    int cnt = 0;
    int ans = 0;
    gets(str);
    for (int i = 0; ch = str[i]; i++) {
        if (ch == '(') {
            cnt++;
        } else if (ch == ')') {
            cnt--;
        }
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
}