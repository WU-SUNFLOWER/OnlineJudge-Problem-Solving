#include <stdio.h>

/*
某人写了n封信，同时为每一封信写1个信封，共n个信封。如果把所有的信都装错了信封，问共有多少种？
试编程求出完全装错情形的所有方式及其总量s。

例如，输入n=3，即有3封信需要装入信封，完全装错的一种方式可以表示为312，
表示第1封信装入第3个信封，第2封信装入第1个信封，第3封信装入第2个信封。对于n=3，完全装错的方式共有2种，分别是312和231.

输入:
输入一个正整数n(2<=n<=6)
输出:
输出完全装错情形的所有方式以及装错方式的总量s (每行输出5种方式，一行中的相邻两种方式之间用1个空格隔开。装错方式输出时，从小到大排列，见输出样例)。
*/

/*
输入：
4
输出：
2143 2341 2413 3142 3412
3421 4123 4312 4321 
s=9
*/

int n;
int s = 0;

int hasInNumber(int singleNum, int num) {
	while (num > 0) {
		if (num % 10 == singleNum) {
			return 1;
		}
		num /= 10;
	}
	return 0;
}

void dfs(int ans, int idx) {
	if (idx > n) {
		if ((++s) % 5 == 0) {
			printf("%d\n", ans);
		} else {
			printf("%d ", ans);
		}
	} else {
		for (int i = 1; i <= n; i++) {
			if (i != idx && !hasInNumber(i, ans)) {
				dfs(ans * 10 + i, idx + 1);
			}
		}	
	}
}

int main() {
	scanf("%d", &n);
	dfs(0, 1);
	printf("\ns=%d", s);
}