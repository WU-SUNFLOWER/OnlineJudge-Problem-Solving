#include <stdio.h>
#include <string.h>

/*
参考资料：
https://blog.csdn.net/weixin_47511190/article/details/112963583
*/

int main() {
    int t;
    char preOrder[100];
    char postOrder[100];
    scanf("%d", &t);
    while (t--) {
        scanf("%s %s", preOrder, postOrder);
        int ans = 1;
        int length = strlen(preOrder);
        for (int i = 0; i < length - 1; i++) {
            for (int j = 1; j < length; j++) {
                if (preOrder[i] == postOrder[j] && preOrder[i + 1] == postOrder[j - 1]) {
                    ans *= 2;
                }
            }
        }
        printf("%d\n", ans);                
    }
}