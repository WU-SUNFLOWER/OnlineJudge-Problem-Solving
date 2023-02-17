#include <stdio.h>
#include <string.h>

int isSymString(char str[]) {
    int ans = 1;
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            ans = 0;
            break;
        }
    }
    return ans;
}

int main() {
    char str[100];
    while (~scanf("%s", str)) {
        printf(isSymString(str) ? "Yes\n" : "No\n");
    }
}