#include <stdio.h>
#include <string.h>

/*
小凡的老师每次上课前都要点名，但是这样就浪费了老师的上课时间。
所以老师让小凡来完成点名，让小凡在早自习的时候就点好名。老师给了小凡名单，小凡只要照着名单点名就好了是不是很简单啊。

输入:
输入有多组数据，直到文件结束。
每组测试数据有三行，第一行为两个整数m, n（50 >= m >= n）。
第二行有m个名字，名字之间用空格隔开，是小凡班上同学的名单。
后面有n个名字是来上课的同学。名字间用空格隔开。名字的长度不超过20个字符。

输出:
按照第一行的名单，每个人对应输出是否到了。到的人输出Yes，没到的人输出No。
*/

/*
输入：
3 2
同学的名单Bob Marry Jam
来上课的同学Bob Jam
2 2
Limeme Lintianzhi
Limeme Lintianzhi

输出：
Yes
No
Yes

Yes
Yes
*/

int main() {
	int totalPeopleNum;
	int realPeopleNum;
	char totalPeopleArr[50][21];
	char realPeopleArr[50][21];
	while (scanf("%d %d", &totalPeopleNum, &realPeopleNum) != EOF) {
		for (int i = 0; i < totalPeopleNum; i++) {
			scanf("%s", &totalPeopleArr[i][0]);
		}
		for (int i = 0; i < realPeopleNum; i++) {
			scanf("%s", &realPeopleArr[i][0]);
		}
        
		for (int i = 0; i < totalPeopleNum; i++) {
			int flag = 1;
			for (int j = 0; j < realPeopleNum; j++) {
				if (strcmp(&totalPeopleArr[i][0], &realPeopleArr[j][0]) == 0) {
					flag = 0;
					printf("Yes\n");
					break;
				}
			}
			flag && printf("No\n");
		}
	}
	return 0;
}