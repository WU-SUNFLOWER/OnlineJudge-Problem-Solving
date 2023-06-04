#include <stdio.h>
#include <string.h>
#define N 100

/*
参考资料：
https://blog.csdn.net/weixin_47511190/article/details/112963583
*/

int main() {
    int t;
    char preOrder[N];
    char postOrder[N];
    char buf[N] = {0};
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%s %s", preOrder, postOrder);
        int cnt = 0;
        int length = strlen(preOrder);
        for (int i = 0; i < length - 1; i++) {
            buf[0] = preOrder[i + 1];
            buf[1] = preOrder[i];
            if (strstr(postOrder, buf)) {
                cnt++;
            }
        }
        printf("%d\n", 1 << cnt);
    }
}