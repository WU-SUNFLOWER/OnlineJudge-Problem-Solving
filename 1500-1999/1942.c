#include <stdio.h>

/*
����һ���ַ��ж�һ�������ڼ�����������ڼ��ĵ�һ����д��ĸ���жϣ���ѭ�����룬
�����롯Y��ʱ�˳����������һ��������ַ�Ϊ��д�ġ�W��, �������Wednesday����
��Ϊ��д�ġ�S��������Ҫ��������ĵڶ����ַ����������ĵڶ����ַ��ǡ�u����a����
�����Su��Sa�����Sunday����Saturday����Ȼ���u��a֮��������ַ����������ж������
���������һ����ƥ����ַ�������Դ�д�ġ�S�������Wrong data����Ȼ��������ƥ����ַ���ʼ���������ж������
*/

/*
����:
�����������ַ�������ԡ�Y��������

���:
���ÿ���ַ���Ӧ�����ڼ�Ӣ�ĵ��ʣ������벻ƥ���ַ����������Wrong data������

��������:
TTuFL&WY

�������:
Wrong data
Tuesday
Friday
Wrong data
Wrong data
Wednesday

��ʾ:
��ʾ����������һ���ַ�����Ҫ�ǡ�Y�����Ա�ʾ�˳����򡣶���ַ�֮�䲻Ҫ�лس�����
*/

/*
Monday
Tuesday
Thursday
Wednesday
Friday
Saturday
Sunday

Сд��u��h��a��t
��д��M��T��W��F��S
*/

int main() {
	char str[100] = {'\0'};
	scanf("%s", str);
	for (int i = 0; str[i]; i++) {
		char ch = str[i];
		char nextCh = str[i + 1];
		if (ch == 'Y') {
			break;
		}
		//���������д��ĸ
		else if (ch == 'T') {
			switch (nextCh) {
				case 'u':
					printf("Tuesday\n");
					i++;
					break;
				case 'h':
					printf("Thursday\n");
					i++;
					break;
				default:
					printf("Wrong data\n");
			}
		}
		else if (ch == 'S') {
			switch (nextCh) {
				case 'a':
					printf("Saturday\n");
					i++;
					break;
				case 'u':
					printf("Sunday\n");
					i++;
					break;
				default:
					printf("Wrong data\n");
			}
		}
		//����������д��ĸ
		else {
			switch (ch) {
				case 'M':
					printf("Monday\n");
					break;
				case 'W':
					printf("Wednesday\n");
					break;
				case 'F':
					printf("Friday\n");
					break;
				default:
					printf("Wrong data\n");
			}
		}
	}
}