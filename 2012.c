#include <stdio.h>

/*
С���������һ�����罻��ϵͳ��Ϊ�˱�֤�û������밲ȫ������Ҫһ�������ж��û��Լ����õ������Ƿ�ȫ��
�������ȫ���������ʾ�����������������������æ���һ�����������������⡣ Ӧ���������µĹ������ж������Ƿ�ȫ��

1. ������볤��С�� 6 λ���򲻰�ȫ
2. ������������ַ�ֻ��һ�࣬�򲻰�ȫ
3. ������������ַ������࣬��Ϊ�жȰ�ȫ
4. ������������ַ�����������ϣ���Ϊ��ȫ 
ͨ����������Ϊ���֡���д��ĸ��Сд��ĸ����������Ϊ���಻ͬ���ַ���

���룺
4
1234 �����볤�Ⱦ�С��20��
abcdef
ABC123
1#c3Gh

�����
Not Safe
Not Safe
Medium Safe
Safe
*/

int main() {
	int n;
	char password[20];
	scanf("%d", &n);
	getchar();
	while ((n--) > 0) {
		int i;
		int hasNumber = 0;
		int hasUpperCaseLetter = 0;
		int hasLowerCaseLetters = 0;
		int hasOthers = 0;
		gets(password);
		for (i = 0; password[i]; i++) {
			if ('0' <= password[i] && password[i] <= '9') {
				hasNumber = 1;
			}
			else if ('A' <= password[i] && password[i] <= 'Z') {
				hasUpperCaseLetter = 1;
			}
			else if ('a' <= password[i] && password[i] <= 'z') {
				hasLowerCaseLetters = 1;
			}
			else {
				hasOthers = 1;
			}
		}
		if (i < 6) {
			printf("Not Safe\n");
		} else {
			int score = hasNumber + hasUpperCaseLetter + hasLowerCaseLetters + hasOthers;
			switch (score) {
				case 1:
					printf("Not Safe\n");
					break;
				case 2: 
					printf("Medium Safe\n");
					break;
				default:
					printf("Safe\n");
					break;
			}
		}
	}
}