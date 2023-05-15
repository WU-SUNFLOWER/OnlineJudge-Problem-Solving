#include <stdio.h>
#include <string.h>

void buildNext(char sub[], int next[]) {
    int i = 1;
    int k = 0;
    next[i] = 0;
    while (i < sub[0]) {
        if (k == 0 || sub[k] == sub[i]) {
            i++;
            k++;
            next[i] = k;
        } else {
            k = next[k];
        }
    }
}

void kmp(char str[], char sub[], int next[], int* cnt, int* pos) {
    int i = 1;
    int j = 1;
    int count = 1;
    while (i <= str[0] && j <= sub[0]) {
        if (j == 0 || str[i] == sub[j]) {
            i++;
            j++;
        } else {
            count++;
            j = next[j];
        }
    }
    *cnt = j == sub[0] + 1 ? count : 0;
    *pos = i - sub[0];
}

int main() {
    char buf[100];
    char str[100];
    char sub[100];
    int next[100];
    // 读入主串
    gets(buf);
    int len = strlen(buf);
    str[0] = len;
    strcpy(str + 1, buf);
    // 读入子串
    gets(buf);
    len = strlen(buf);
    sub[0] = len;
    strcpy(sub + 1, buf);
    // 计算next数组
    buildNext(sub, next);
    // 调用kmp
    int cnt;
    int pos;
    kmp(str, sub, next, &cnt, &pos);
    printf(cnt ? "%d %d" : "%d", cnt, pos);
}