#include <stdio.h>

int main() {
    int map[0x7f] = {0};
    char sentence[100];
    char blackList[100];
    gets(sentence);
    gets(blackList);
    // 给黑名单打表
    for (int i = 0; blackList[i]; i++) {
        map[blackList[i]] = 1;
    }
    // 过滤句子并直接输出
    char ch;
    for (int i = 0; ch = sentence[i]; i++) {
        // 测试样例里可能有中文，每个字节转成char会变成负数
        // 所以要先判断ch的正负
        if (ch > 0 && map[ch]) continue;
        putchar(ch);
    }
}