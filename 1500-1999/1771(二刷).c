#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char subStr[100];
    scanf("%s %s", str, subStr);
    int ans = 0;
    char* ptr = strstr(str, subStr);
    while (ptr != NULL) {
        ans++;
        ptr = strstr(ptr + 1, subStr);
    }
    printf("%d\n", ans);
}