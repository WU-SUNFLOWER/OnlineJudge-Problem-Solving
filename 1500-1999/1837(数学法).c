#include <stdio.h>

/*
�ο����ϣ�https://blog.csdn.net/jokerMingge/article/details/120675362
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
�������һ��Ҫֱ�Ӵ�1��ʼ��ÿ���˱�ţ�����ԡ�
�������£�
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