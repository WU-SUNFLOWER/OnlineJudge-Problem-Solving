#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//从键盘输入一个字符串给str和一个字符给c，删除str中的所有字符c并输出删除后的字符串str。

/*
输入：
sdf$$$sdf$$
$

输出：
sdfsdf
*/

char* createString(int length) {
	char* str = (char*)malloc(sizeof(char) * (length + 1));
	str[length] = '\0';
	return str;
}

char* addCharToString(char* string, char coin) {
	int len = strlen(string);
	//新字符串长度len+1
	//新字符串存储字符下标范围：0~len
	//新字符串结束位下标len+1
	char* newString = createString(len + 1);
	for (int i = 0; i < len; i++) {
		newString[i] = string[i];
	}
	newString[len] = coin;
	free(string);
	return newString;
}

int main() {
	char ch;
	char delCh;
	char* str = createString(0);
	while ((ch = getchar()) != '\n') {
		str = addCharToString(str, ch);
	}
	scanf("%c", &delCh);
	for (int i = 0; i < strlen(str); i++) {
		str[i] != delCh && printf("%c", str[i]);
	}
	printf("\n");
}