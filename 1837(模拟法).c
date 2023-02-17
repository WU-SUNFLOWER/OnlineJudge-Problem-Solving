#include <stdio.h>

/*
约瑟夫环问题：设有n（n≤1000）个人围坐一圈，并按顺时针方向1—n编号。
从第s个人开始进行报数，报数到第m个人，此人出圈，
再从他的下一个人重新开始从1到m的报数进行下去 ，直到只剩一个人为止。

输入:
人数n
最先开始报数的那个人的编号s
报到第几个数m

输出:
剩下的最后一个人的编号
*/

int main() {
	int n;
	int s;
	int m;
	int curStep;
	int curN;
	int arr[1001];
	scanf("%d %d %d", &n, &s, &m);
	curN = n;
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	while (curN > 1) {
		//将第一个人报的数设定为1
		curStep = 1;
		//寻找下一个被杀的人
		while (curStep < m) {
			s = s % n + 1;
			if (arr[s] != -1) {
				curStep++;
			}
		}
		arr[s] = -1;
		curN--;
		//定位到下一轮报数的第一人
		while (1) {
			s = s % n + 1;
			if (arr[s] != -1) {
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] != -1) {
			printf("%d\n", i);
			break;
		}
	}
}