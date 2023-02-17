#include <stdio.h>
#include <stdlib.h>

/*
输出指定的菱形。 第一行前面有n-1个空格，第二行有n-2个空格，以此类推。
1<=n<=9
1<=行数<=17
*/

/*
输入：
5
输出：
    *    行0空格4符号1
   ***   行1空格3符号3
  *****  行2空格2符号5
 ******* 行3空格1符号7
*********行4空格0符号9
 *******
  *****
   ***
    *
*/

char* createCharArray(int length) {
	char* arr = (char*)malloc(sizeof(char) * (length + 1));
	for (int i = 0; i <= length; i++) {
		arr[i] = '\0';
	}
	return arr;
}

int main() {
	int n;
	char* LineAnsArr[17];
	scanf("%d", &n);
	//生成头部
	for (int i = n - 1; i >= 0; i--) {
		char* curLine = createCharArray(2 * n - 1);
		int point = 0;
		int line = n - i - 1;
		//生成空格
		for (; point < i; point++) {
			curLine[point] = ' ';
		}
		//生成星号
		for (; point < i + 2 * (line + 1) - 1; point++) {
			curLine[point] = '*';
		}
		LineAnsArr[line] = curLine;
		printf("%s\n", curLine);
	}
	//生成尾部
	for (int i = n - 2; i >= 0; i--) {
		printf("%s\n", LineAnsArr[i]);
	}
}