#include <stdio.h>
#include <string.h>

//����20���ַ���ͳ������Ӣ����ĸ�������ַ����ո��س��������ַ��ĸ�����

int main() {
	char ch;
	char str[21];
	int idx = 0;
	int englishTime = 0;
	int numberTime = 0;
	int spaceTime = 0;
	int otherTime = 0;
	while (idx < 20) {
		ch = getchar();
		if ('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z') {
			englishTime++;
		} 
		else if ('0' <= ch && ch <= '9') {
			numberTime++;
		}
		else if (ch == ' ' || ch == '\n') {
			spaceTime++;
		}
		else {
			otherTime++;
		}		
		idx++;
	}
	printf("%d��Ӣ����ĸ\n", englishTime);
	printf("%d�������ַ�\n", numberTime);
	printf("%d���ո��س�\n", spaceTime);
	printf("%d�������ַ�\n", otherTime);
}