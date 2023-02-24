#include <stdio.h>

/*
²Î¿¼×ÊÁÏ£ºhttps://blog.csdn.net/jokerMingge/article/details/120675362
*/

long long f[100001];

int main() {
	long long n, i, k = 3, s = 1;	
    f[1] = 0;
    for (i = 2; i <= 100000; i++) {
    	f[i] = (f[i - 1] + k) % i;
	}
    while (~scanf("%lld", &n)) {
        printf("%lld\n", (f[n] + s - 1) % n + 1);
    }
    return 0;
}