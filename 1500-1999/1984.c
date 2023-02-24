#include <stdio.h>
#include <string.h>

/*
输入一字符串，对其按给定的条件进行排序，并输出。
排序条件为：将字符串从中间一分为二，左边部分按字符的ASCII值升序排序，
排序后左边部分与右边部分进行交换。如果字符串长度为奇数，则最中间的字符不参与处理。
例如，输入dcbahgfe,则输出hgfeabcd；若输入432198765，则输出876591234。
*/

int main() {
	int length;
	char str[300];
	gets(str);
	length = strlen(str);
	//排序
	for (int i = 0; i < length / 2 - 1; i++) {
		for (int j = 0; j <= length / 2 - 1 - 1; j++) {
			if (str[j] > str[j + 1]) {
				char temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}
	//输出
	if (length % 2 == 0) {
		for (int i = length / 2; i < length; i++) {
			printf("%c", str[i]);
		}
	} else {
		for (int i = length / 2 + 1; i < length; i++) {
			printf("%c", str[i]);
		}
		printf("%c", str[length / 2]);
	}
	for (int i = 0; i <= length / 2 - 1; i++) {
		printf("%c", str[i]);
	}
}