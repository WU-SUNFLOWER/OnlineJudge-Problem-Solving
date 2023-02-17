#include <stdio.h>
#include <string.h>

int compare(char* str1, char* str2) {
    char* fatherStr;
    char* subStr;
    if (strlen(str1) > strlen(str2)) {
        fatherStr = str1;
        subStr = str2;
    } else {
        fatherStr = str2;
        subStr = str1;
    }
    int i = 0;
    int j = 0;
    for (; fatherStr[i] && subStr[j]; i++) {
        if (fatherStr[i] == subStr[j]) {
            j++;
        }
    }
    return !subStr[j];
}

int main() {
    int num;
    char strArr[100][100];
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%s", strArr[i]);
    }
    int ans = 0;
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            ans += compare(strArr[i], strArr[j]);
        }
    }
    printf("%d\n", ans);
}