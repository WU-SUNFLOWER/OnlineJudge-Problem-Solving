#include <stdio.h>

/*
��дһ�����򣬶���һ������������������Щ�����ĺ�Ϊ�������������������ҳ�����
���磬�������27,����2~7,8~10,13��14�ĺ���27������ǽ������������10000��Ӧ����18~142,297~412, 388~412,1998~2002��4�顣
ע�⣬��һ�����д𰸣���4,16���޽⡣

����
����һ����������

���
������������������飬�������Ϊ����������������û�д𰸣��������No answer!��.

�������� 1 
500
������� 1
8~32
59~66
98~102
*/

int main() {
	int num;
	int flag = 1;
	scanf("%d", &num);
	for (int i = 1; i < num; i++) {
		for (int j = i + 1; j <= num - i; j++) {
			if (num * 2 == (i + j) * (j - i + 1)) {
				flag = 0;
				printf("%d~%d\n", i, j);
			}
		}
	}
	if (flag) {
		printf("No answer!\n");
	}
}