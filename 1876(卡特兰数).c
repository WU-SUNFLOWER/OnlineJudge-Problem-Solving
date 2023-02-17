#include <stdio.h>

/*
卡兰特数包括递推式和通项两种形式，这里仅展现基于递推式的解法
关于卡兰特数，详见参考资料：
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