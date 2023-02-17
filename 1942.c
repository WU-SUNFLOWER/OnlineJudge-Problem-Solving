#include <stdio.h>

/*
输入一个字符判断一下是星期几。请根据星期几的第一个大写字母来判断，并循环输入，
当输入’Y’时退出程序。如果第一个输入的字符为大写的’W’, 则输出”Wednesday”；
若为大写的’S’，则需要考虑输入的第二个字符。如果输入的第二个字符是’u’或’a’，
则针对Su或Sa输出”Sunday”或”Saturday”，然后从u或a之后输入的字符继续进行判断输出；
如果输入了一个不匹配的字符，就针对大写的’S’输出”Wrong data”，然后从这个不匹配的字符开始继续进行判断输出。
*/

/*
输入:
连续输入多个字符，最后以’Y’结束。

输出:
输出每个字符对应的星期几英文单词（若输入不匹配字符，则输出”Wrong data”）。

样例输入:
TTuFL&WY

样例输出:
Wrong data
Tuesday
Friday
Wrong data
Wrong data
Wednesday

提示:
提示：输入的最后一个字符必须要是’Y’，以表示退出程序。多个字符之间不要有回车键。
*/

/*
Monday
Tuesday
Thursday
Wednesday
Friday
Saturday
Sunday

小写：u、h、a、t
大写：M、T、W、F、S
*/

int main() {
	char str[100] = {'\0'};
	scanf("%s", str);
	for (int i = 0; str[i]; i++) {
		char ch = str[i];
		char nextCh = str[i + 1];
		if (ch == 'Y') {
			break;
		}
		//处理特殊大写字母
		else if (ch == 'T') {
			switch (nextCh) {
				case 'u':
					printf("Tuesday\n");
					i++;
					break;
				case 'h':
					printf("Thursday\n");
					i++;
					break;
				default:
					printf("Wrong data\n");
			}
		}
		else if (ch == 'S') {
			switch (nextCh) {
				case 'a':
					printf("Saturday\n");
					i++;
					break;
				case 'u':
					printf("Sunday\n");
					i++;
					break;
				default:
					printf("Wrong data\n");
			}
		}
		//处理其他大写字母
		else {
			switch (ch) {
				case 'M':
					printf("Monday\n");
					break;
				case 'W':
					printf("Wednesday\n");
					break;
				case 'F':
					printf("Friday\n");
					break;
				default:
					printf("Wrong data\n");
			}
		}
	}
}