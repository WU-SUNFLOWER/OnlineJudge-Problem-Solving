#include <stdio.h>

//����һ���ַ�����ͳ������Ӣ����ĸ��������Сд�����ո����ֺ������ַ�������������������ַ����ĸ�����

int main() {
	char ch;
	int letterNum = 0;
	int spaceNum = 0;
	int numberNum = 0;
	int otherNum = 0;
	while ((ch = getchar()) != EOF && ch != '\n') {
		if ('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z') {
			letterNum++;
		}
		else if (ch == ' ') {
			spaceNum++;
		}
		else if ('0' <= ch && ch <= '9') {
			numberNum++;
		}
		else {
			otherNum++;
		}
	}
	printf("%d,%d,%d,%d", letterNum, spaceNum, numberNum, otherNum);
}