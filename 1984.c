#include <stdio.h>
#include <string.h>

/*
����һ�ַ��������䰴�����������������򣬲������
��������Ϊ�����ַ������м�һ��Ϊ������߲��ְ��ַ���ASCIIֵ��������
�������߲������ұ߲��ֽ��н���������ַ�������Ϊ�����������м���ַ������봦��
���磬����dcbahgfe,�����hgfeabcd��������432198765�������876591234��
*/

int main() {
	int length;
	char str[300];
	gets(str);
	length = strlen(str);
	//����
	for (int i = 0; i < length / 2 - 1; i++) {
		for (int j = 0; j <= length / 2 - 1 - 1; j++) {
			if (str[j] > str[j + 1]) {
				char temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}
	//���
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