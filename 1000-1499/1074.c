#include <stdio.h>

int main() {
    int i;
    int j;
    int ans = 0;
    int f_len;
    int g_len;
    int f[1000];
    int g[1000];
    scanf("%d %d", &f_len, &g_len);
    for (i = 0; i < f_len; i++) {
        scanf("%d", &f[i]);
    }
    for (i = 0; i < g_len; i++) {
        scanf("%d", &g[i]);
    }
    i = 0;
    j = 0;
    while (i < f_len && j < g_len) {
        if (f[i] == g[j]) {
            ans++;
            i++;
            j++;
        }
        else if (f[i] > g[j]) {
            j++;
        }
        else {
            i++;
        }
    }
    printf("%d\n", ans);
}