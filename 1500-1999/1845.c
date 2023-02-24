#include <stdio.h>

int main() {
    int flag = 1;
    int idx = -1;
    char str[100];
    char queue[100] = {0};
    gets(str);
    for (int i = 0; str[i] && flag; i++) {
        char ch = str[i];
        if (ch == '[' || ch == '(' || ch == '{') {
            queue[++idx] = ch;
        }
        else if (ch == ']') {
            queue[idx] == '[' ? (idx--) : (flag = 0);
        }
        else if (ch == ')') {
            queue[idx] == '(' ? (idx--) : (flag = 0);
        }
        else if (ch == '}') {
            queue[idx] == '{' ? (idx--) : (flag = 0);
        }
    }
    if (idx >= 0) {
        flag = 0;
    }
    printf(flag ? "YES" : "NO");
}