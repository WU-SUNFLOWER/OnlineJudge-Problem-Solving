#include <stdio.h>

/*
我们知道，高中会考是按等级来的。 
90~100为A; 80~89为B; 70~79为C; 60~69为D; 0~59为E。 
编写一个程序，对输入的一个百分制的成绩t，将其转换成对应的等级。

对于每组输入数据，输出一行。如果输入数据不在0~100范围内，请输出一行：“Score is error!”。

如：
输入   56
输出   E
输入   123
输出   Score is error!
*/

/*
输入：
56
67
100
123

输出：
E
D
A
Score is error!
*/

int main() {
	int score;
	while (scanf("%d", &score) != EOF) {
		if (90 <= score && score <= 100) {
			printf("A\n");
		}
		else if (80 <= score && score <= 89) {
			printf("B\n");
		}
		else if (70 <= score && score <= 79) {
			printf("C\n");
		}
		else if (60 <= score && score <= 69) {
			printf("D\n");
		}
		else if (0 <= score && score <= 59) {
			printf("E\n");
		}
		else {
			printf("Score is error!\n");
		}
	}
}