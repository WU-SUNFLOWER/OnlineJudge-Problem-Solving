#include <stdio.h>

/*
小林正在设计一个网络交易系统，为了保证用户的密码安全，他需要一个程序，判断用户自己设置的密码是否安全，
如果不安全，则给出提示。现在他向你求助，请你帮忙设计一个程序来解决这个问题。 应当按照以下的规则来判断密码是否安全：

1. 如果密码长度小于 6 位，则不安全
2. 如果组成密码的字符只有一类，则不安全
3. 如果组成密码的字符有两类，则为中度安全
4. 如果组成密码的字符有三类或以上，则为安全 
通常，可以认为数字、大写字母、小写字母和其它符号为四类不同的字符。

输入：
4
1234 （密码长度均小于20）
abcdef
ABC123
1#c3Gh

输出：
Not Safe
Not Safe
Medium Safe
Safe
*/

int main() {
	int n;
	char password[20];
	scanf("%d", &n);
	getchar();
	while ((n--) > 0) {
		int i;
		int hasNumber = 0;
		int hasUpperCaseLetter = 0;
		int hasLowerCaseLetters = 0;
		int hasOthers = 0;
		gets(password);
		for (i = 0; password[i]; i++) {
			if ('0' <= password[i] && password[i] <= '9') {
				hasNumber = 1;
			}
			else if ('A' <= password[i] && password[i] <= 'Z') {
				hasUpperCaseLetter = 1;
			}
			else if ('a' <= password[i] && password[i] <= 'z') {
				hasLowerCaseLetters = 1;
			}
			else {
				hasOthers = 1;
			}
		}
		if (i < 6) {
			printf("Not Safe\n");
		} else {
			int score = hasNumber + hasUpperCaseLetter + hasLowerCaseLetters + hasOthers;
			switch (score) {
				case 1:
					printf("Not Safe\n");
					break;
				case 2: 
					printf("Medium Safe\n");
					break;
				default:
					printf("Safe\n");
					break;
			}
		}
	}
}