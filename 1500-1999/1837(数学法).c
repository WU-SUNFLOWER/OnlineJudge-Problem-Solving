#include <stdio.h>

/*
参考资料：https://blog.csdn.net/jokerMingge/article/details/120675362
*/

int main() {
	int n, k, s;
	int f[1001];
    scanf("%d %d %d", &n, &s, &k);
    f[1] = 0;
    for (int i = 2; i <= n; i ++ ) {
    	f[i] = (f[i - 1] + k) % i;
	}
    printf("%d", (f[n] + s - 1) % n + 1);
    return 0;
}

/*
如果本题一定要直接从1开始给每个人编号，亦可以。
代码如下：
int main() {
	int n, k, s;
	int f[1001];
    scanf("%d %d %d", &n, &s, &k);
    f[1] = 1;
    for (int i = 2; i <= n; i ++ ) {
    	f[i] = (f[i - 1] + k - 1) % i + 1;
	}
    printf("%d", (f[n] + s - 1 - 1) % n + 1);
    return 0;
}
*/