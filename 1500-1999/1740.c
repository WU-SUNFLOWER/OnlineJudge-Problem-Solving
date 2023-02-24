#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool check(char str[]) {
    int len = strlen(str);
    int tail = len - 1;
    bool ans = true;
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[tail - i]) {
            ans = false;
            break;
        }
    }
    return ans;
}

int main() {
    bool ans = true;
    char buf[100];
    while (~scanf("%s", buf)) {
        if (!check(buf)) {
            ans = false;
            break;
        }
    }
    printf("Êä³ö½á¹û£º");
    printf(ans ? "Yes" : "No");
}