#include <stdio.h>

/*
我们寄信都要贴邮票，在邮局有一些小面值的邮票，通过这些小面值邮票中的一张或几张的组合，可以满足不同邮件的不同的邮资。 
现在，邮局有4种不同面值的邮票。在每个信封上最多能贴5张邮票，面值可相同，可不同。

输入：四种邮票的面值。
输出：用这四种面值组成的邮资最大的从1开始的一个连续的区间。
说明：如结果为10，则表明使用4张邮票可组合出1、2、3、4、5、6、7、8、9、10这些邮资。
*/

/*
输入：1 2 3 4
输出：20
*/

int value[4];

int dfs(int curVal, int idx, int leftChances) {
	if (leftChances < 0 || curVal < 0) {
		return 0;
	}
	if (curVal == 0) {
		return 1;
	}
	for (int i = idx; i < 4; i++) {
		if(dfs(curVal - value[i], i, leftChances - 1)) {
			return 1;
		}
	}
	return 0;
}

int main() {
	int ans = 0;
	scanf("%d %d %d %d", &value[0], &value[1], &value[2], &value[3]);
	while (dfs(++ans, 0, 5));
	printf("%d.", ans - 1);
}