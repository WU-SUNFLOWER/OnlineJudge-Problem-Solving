#include <stdio.h>
#include <string.h>

int parseHex(char hex[]) {
    char ch;
    int temp;
    int ans = 0;
    for (int i = 0; ch = hex[i]; i++) {
        if ('a' <= ch && ch <= 'z') {
            temp = ch - 'a' + 10;
        }
        else if ('A' <= ch && ch <= 'Z') {
            temp = ch - 'A' + 10;
        } 
        else {
            temp = ch - '0';
        }
        ans = (ans << 4) + temp;
    }
    return ans;
}

int main() {
    int val;
    char hex[100];
    int ans[4];
    scanf("%s", hex);
    val = parseHex(hex);
    for (int i = 0; i < 4; i++) {
        ans[i] = val & 0b11111111;
        val >>= 8;
    }
    for (int i = 3; i >= 0; i--) {
        printf(i ? "%d." : "%d\n", ans[i]);
    }
}