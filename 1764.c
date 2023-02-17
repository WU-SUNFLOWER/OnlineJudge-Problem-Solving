#include <stdio.h>
#include <string.h>

/*
将字符串t插入到字符串s中，在位置pos后插入。不得使用字符串操作函数，输出组合成的字符串。

输入
输入两个字符串(t和s)和要插入的位置（pos）

输出
输出组合后的字符串

样例输入
qwe
jij
3
样例输出
jijqwe

*/

int main() {
	int i;
	int insertPos;
	char tempString[100];
	char insertString[100];
	char originalString[100];
	gets(insertString);
	gets(originalString);
	scanf("%d", &insertPos);
	//缓存原字符串
	for (i = insertPos; i <= strlen(originalString); i++) {
		tempString[i - insertPos] = originalString[i];
	}
	//写入新字符串
	for (i = 0; i < strlen(insertString); i++) {
		originalString[i + insertPos] = insertString[i];
	}
	//写入缓存字符串
	for (int j = 0; j <= strlen(tempString); j++) {
		originalString[i + insertPos + j] = tempString[j];
	}
	printf("%s\n", originalString);
}