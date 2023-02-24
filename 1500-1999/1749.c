#include <stdio.h>

int parse(char str[], int ar[]) {
    char ch;
    int idx = 0;
    int num = 0;
    int flag = 0;  // 标记已经开始读取数字序列
    for (int i = 0; ch = str[i]; i++) {
        if ('0' <= ch && ch <= '9') {
            flag = 1;
            num = num * 10 + (ch - '0');
        }
        else if (ch == ' ' && flag) {
            ar[idx++] = num;
            num = 0;
        }
    }
    ar[idx++] = num;
    return idx;
}

int main() {
    int ar1[100];
    int ar2[100];
    char str1[100];
    char str2[100];
    gets(str1);
    gets(str2);
    gets(str2);
    int idx1 = parse(str1, ar1);
    int idx2 = parse(str2, ar2);
    int i = 0;
    int ans = 0;
    while (i < idx1) {
        // 匹配疑似头部
        int pos = -1;
        for (; i < idx1; i++) {
            if (ar1[i] == ar2[0]) {
                pos = i;
                break;
            }
        }
        // 如果遍历完整个A数组都没找到匹配头部，则B一定不是A的子串
        if (i == idx1 && pos == -1) {
            break;
        }
        // 找到疑似头部，进行后续校验
        int j;
        for (j = 0; j < idx2; j++) {
            if (ar1[pos + j] != ar2[j]) break;
        }
        // 匹配成功，记录答案并退出循环
        if (j == idx2) {
            ans = 1;
            break;
        }
    }
    printf(ans ? "是" : "否");
}