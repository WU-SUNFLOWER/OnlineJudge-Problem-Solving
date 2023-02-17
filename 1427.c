#include <stdio.h>

int main() {
    int ch;
    int ans = 0;
    //因为getchar有可能返回EOF，为了防止出错，getchar的返回值类型是int
    while (~(ch = getchar())) {
        if (ch == '$') {
            ans++;
        }
    }
    printf("%d\n", ans);
}