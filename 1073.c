#include <stdio.h>

int main() {
    int ans = 0;
    int f[1000];
    int g[1000];
    int f_len;
    int g_len;
    scanf("%d %d", &f_len, &g_len);
    //读入f数组
    for (int i = 0; i < f_len; i++) {
        scanf("%d", &f[i]);
    }
    //读入g数组
    for (int i = 0; i < g_len; i++) {
        scanf("%d", &g[i]);
    }
    int i = 0;
    int j = 0;
    while (i < f_len && j < g_len) {
        if (f[i] > g[j]) {
            //处理g[j]遍历结束，但f[i]还有剩余较大项的情况
            if (j == g_len - 1) {
                ans += (j + 1) * (f_len - i);
            }
            j++;
        }
        else {
            ans += j;
            i++;
        }
    }
    printf("%d\n", ans);
}