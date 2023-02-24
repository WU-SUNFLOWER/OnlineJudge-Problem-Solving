#include <stdio.h>

int strcmp(char* str1, char* str2) {
    int ans;
    for (int i = 0; str1[i]; i++) {
        ans = str1[i] - str2[i];
        if (ans != 0) {
            break;
        }
    }
    return ans;
}

int main() {
    int n;
    char str1[120];
    char str2[120];
    scanf("%d", &n);
    while (~scanf("%s %s", str1, str2)) {
        printf("%d\n", strcmp(str1, str2));
    }
}