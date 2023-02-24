#include <stdio.h>
#include <stdlib.h>

/*
���ָ�������Ρ� ��һ��ǰ����n-1���ո񣬵ڶ�����n-2���ո��Դ����ơ�
1<=n<=9
1<=����<=17
*/

/*
���룺
5
�����
    *    ��0�ո�4����1
   ***   ��1�ո�3����3
  *****  ��2�ո�2����5
 ******* ��3�ո�1����7
*********��4�ո�0����9
 *******
  *****
   ***
    *
*/

char* createCharArray(int length) {
	char* arr = (char*)malloc(sizeof(char) * (length + 1));
	for (int i = 0; i <= length; i++) {
		arr[i] = '\0';
	}
	return arr;
}

int main() {
	int n;
	char* LineAnsArr[17];
	scanf("%d", &n);
	//����ͷ��
	for (int i = n - 1; i >= 0; i--) {
		char* curLine = createCharArray(2 * n - 1);
		int point = 0;
		int line = n - i - 1;
		//���ɿո�
		for (; point < i; point++) {
			curLine[point] = ' ';
		}
		//�����Ǻ�
		for (; point < i + 2 * (line + 1) - 1; point++) {
			curLine[point] = '*';
		}
		LineAnsArr[line] = curLine;
		printf("%s\n", curLine);
	}
	//����β��
	for (int i = n - 2; i >= 0; i--) {
		printf("%s\n", LineAnsArr[i]);
	}
}