#include <stdio.h>

/*
从键盘输入的字符串(用回车结束)中查找是否含有单词“is”(大小写不区分)，有则将其删除，输出结果字符串。
*/

int main() {
	char ch;
	char tempCh;
	int flag = 0;
	while ((ch = getchar()) != '\n') {
		//第一种情况：出现i/I，则备份当前字符预备检测s/S
		//第二种情况，i/I后面紧跟s/S
		//第三种情况：i/I没有s/S
		if (flag) {
			flag = 0;
			if (ch == 's' || ch == 'S') {	
				continue;
			} else {
				printf("%c", tempCh);
			}
		}
		if (ch == 'i' || ch == 'I') {
			flag = 1;
			tempCh = ch;
		} else {
			printf("%c", ch);
		}
	}
}