#include <stdio.h>

/*
����������������ʽ��ͨ��������ʽ�������չ�ֻ��ڵ���ʽ�Ľⷨ
���ڿ�������������ο����ϣ�
https://zhuanlan.zhihu.com/p/391237550
https://zhuanlan.zhihu.com/p/56821103
*/

int catalan(int n) {
    if (n == 0) {
        return 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += catalan(i - 1) * catalan(n - i);
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", catalan(n));
}