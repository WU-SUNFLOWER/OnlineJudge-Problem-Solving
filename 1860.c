#include <stdio.h>
#include <string.h>
#define N 100

int max(int a, int b) {
    return a < b ? b : a;
}

int main() {
    char cnt[0x7f] = {0};
    int pos[0x7f];  // 记录某个字符第一次出现的位置,初始值-1
    char sentence[N];
    memset(pos, -1, sizeof(pos));
    gets(sentence);
    char ch;
    int maxChar = 0;
    for (int i = 0; ch = sentence[i]; i++) {
        cnt[ch]++;
        maxChar = max(maxChar, (int)ch);
        pos[ch] == -1 && (pos[ch] = i);
    }
    int ans;
    int minPos = strlen(sentence);
    for (int i = 1; i <= maxChar; i++) {
        if (cnt[i] == 1 && pos[i] < minPos) {
            ans = i;
            minPos = pos[i];
        }
    }
    printf("%c\n", ans);
}