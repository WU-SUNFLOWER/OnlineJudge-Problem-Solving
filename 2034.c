#include <stdio.h>

/*
²Î¿¼×ÊÁÏ£ºhttps://blog.csdn.net/DBC_121/article/details/105921706
*/

int main() {
    int n;
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i <= n; i += 5) {
        int curNum = i;
        while (curNum > 0 && curNum % 5 == 0) {
            ans++;
            curNum /= 5;
        }
    }
    printf("%d\n", ans);
}