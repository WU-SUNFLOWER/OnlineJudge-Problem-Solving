#include <stdio.h>
#include <string.h>

int main() {
    char str[21];
    char subStr[21];
    scanf("%s %s", str, subStr);
    int str_len = strlen(str);
    int subStr_len = strlen(subStr);
    int ans = 0;
    for (int i = 0; i <= str_len - subStr_len; i++) {
        for (int j = 0; j < subStr_len; j++) {
            if (str[i + j] != subStr[j]) {
                break;
            }
            if (j == subStr_len - 1) {
                ans++;
            }
        }
    }
    printf("%d", ans);
}