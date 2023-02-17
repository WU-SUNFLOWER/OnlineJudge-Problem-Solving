#include <stdio.h>
#include <string.h>

/*
假设渊子原来一个BBS上的密码为zvbo941987,为了方便记忆，他通过一种算法把这个密码变换成YUANzi1987，
这个密码是他的名字和出生年份，怎么忘都忘不了，而且可以明目张胆地放在显眼的地方而不被别人知道真正的密码。 
他是这么变换的，大家都知道手机上的字母： 1--1， abc--2, def--3, ghi--4, jkl--5, mno--6, pqrs--7, tuv--8
 wxyz--9, 0--0,就这么简单，渊子把密码中出现的小写字母都变成对应的数字，数字和其他的符号都不做变换，
 
 声明：密码中没有空格，而密码中出现的大写字母则边成小写之后往后移一位，
 如：X，先边成小写，再往后移一位，不就是y了嘛，简单吧。记住，z往后移是a哦。
*/

/*
输入包括多个测试数据。输入是一个明文，密码长度不超过100个字符，输入直到文件结尾。
输出输出渊子真正的密文。

输入：
YUANzi1987

输出：
zvbo941987
*/

int main() {
	char password[100];
	while (scanf("%s", &password) != EOF) {
		int length = strlen(&password[0]);
		for (int idx = 0; idx < length; idx++) {
			if ('A' <= password[idx] && password[idx] <= 'Y') {
				password[idx] = password[idx] - 'A' + 'a' + 1;
			}
			else if (password[idx] == 'Z') {
				password[idx] = 'a';
			}
			else if ('a' <= password[idx] && password[idx] <= 'c') {
				password[idx] = '2';
			}
			else if ('d' <= password[idx] && password[idx] <= 'f') {
				password[idx] = '3';
			}
			else if ('g' <= password[idx] && password[idx] <= 'i') {
				password[idx] = '4';
			}
			else if ('j' <= password[idx] && password[idx] <= 'l') {
				password[idx] = '5';
			}
			else if ('m' <= password[idx] && password[idx] <= 'o') {
				password[idx] = '6';
			}
			else if ('p' <= password[idx] && password[idx] <= 's') {
				password[idx] = '7';
			}
			else if ('t' <= password[idx] && password[idx] <= 'v') {
				password[idx] = '8';
			}
			else if ('w' <= password[idx] && password[idx] <= 'z') {
				password[idx] = '9';
			}
		}
		printf("%s\n", password);
	}
	return 0;
}