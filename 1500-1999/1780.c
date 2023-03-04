#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool check(char* str, char* subStr, int length) {
    for (int i = 0; i < length; i++) {
        if (str[i] != subStr[i]) return false;
    }
    return true;
}

void update(char* str, char* subStr_new, int subLength) {
    char buf[100] = {0};
    strcpy(buf, str + subLength);
    strcpy(str, subStr_new);
    strcat(str, buf);
}

int cmp(const void* p1, const void* p2) {
    return *((int*)p1) - *((int*)p2);
}

int main() {
    char str[100] = {0};
    char subStr[100] = {0};
    char subStr_new[100] = {0};
    scanf("%s %s %s", str, subStr, subStr_new);
    int subLength = strlen(subStr);
    int length = strlen(str);
    int subLength_new = strlen(subStr_new);
    // 滑动窗口核心代码
    bool flag = false;
    int pos[100];
    int idx_pos = 0;
    for (int i = 0; i < subLength; i++) {
        for (int j = i; j < length; j += subLength) {
            if (check(str + j, subStr, subLength)) {
                flag = true;
                pos[idx_pos++] = j;
            }
        }
    }
    // 批量替换子串
    int offset = subLength_new - subLength;
    qsort(pos, idx_pos, sizeof(int), cmp);
    for (int i = 0; i < idx_pos; i++) {
        int newPos = pos[i] + i * offset;
        update(str + newPos, subStr_new, subLength);
    }
    // 输出
    puts(flag ? str : "NO");
    return 0;
}