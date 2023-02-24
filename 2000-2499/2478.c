#include <stdio.h>
#include <string.h>

int judge(char originalText[], int idx, char targetText[], int targetLength) {
    int ans = 1;
    for (int i = 0; i < targetLength; i++) {
        if (originalText[idx + i] != targetText[i]) {
            ans = 0;
            break;
        }
    }
    return ans;
}

int main() {
    int length;
    int targetLength;
    char originalText[100];
    char targetText[100];
    char correctText[100];
    gets(originalText);
    gets(targetText);
    gets(correctText);
    length = strlen(originalText);
    targetLength = strlen(targetText);
    int i = 0;
    while (i < length) {
        if (i <= length - targetLength && judge(originalText, i, targetText, targetLength)) {
            printf("%s", correctText);
            i += targetLength;
        } else {
            printf("%c", originalText[i]);
            i += 1;
        }
    }
}