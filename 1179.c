#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�Ӽ�������һ���ַ�����str��һ���ַ���c��ɾ��str�е������ַ�c�����ɾ������ַ���str��

/*
���룺
sdf$$$sdf$$
$

�����
sdfsdf
*/

char* createString(int length) {
	char* str = (char*)malloc(sizeof(char) * (length + 1));
	str[length] = '\0';
	return str;
}

char* addCharToString(char* string, char coin) {
	int len = strlen(string);
	//���ַ�������len+1
	//���ַ����洢�ַ��±귶Χ��0~len
	//���ַ�������λ�±�len+1
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