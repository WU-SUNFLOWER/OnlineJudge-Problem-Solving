#include <stdio.h>
#include <string.h>

/*
²Î¿¼×ÊÁÏ£º
https://blog.csdn.net/weixin_47511190/article/details/112963583
*/

int main() {
    int length;
    int ans = 1;
    char preOrder[100];
    char postOrder[100];
    scanf("%s %s", preOrder, postOrder);
    length = strlen(preOrder);
    for (int i = 0; i < length - 1; i++) {
        for (int j = 1; j < length; j++) {
            if (preOrder[i] == postOrder[j] && preOrder[i + 1] == postOrder[j - 1]) {
                ans *= 2;
            }
        }
    }
    printf("%d\n", ans);
}