#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* createString(length) {
	char* str = (char*)malloc(sizeof(char) * (length + 1));
	for (int i = 0; i <= length; i++) {
		str[i] = '\0';
	}
	return str;
}

char convertNumToChar(int num) {
	return (char)(num + 48);
}

int main() {
	
	char* anss[20];
	int n;
	
	scanf("%d", &n);
	
	//����ͷ��
	for (int i = 0; i < n; i++) {
		char* mystr = createString(n * 2 - 1);
		
		//���ɿո�
		int point = 0;
		for (; point < n - 1 - i; point++) {
			mystr[point] = ' ';
		}
		
		//�������֣�����
		for (int j = 1; j <= i + 1; j++) {
			mystr[point++] = convertNumToChar(j);
		}
		
		//�������֣����ģ�
		int oldPoint = point - 2;
		for (int j = 1; j < i + 1; j++) {
			mystr[point++] = mystr[oldPoint--];
		}
		
		//���桢������
		anss[i] = mystr;
		printf("%s\n", mystr);
	}
	
	
	
	//���β��
	for (int i = 1; i <= n - 1; i++) {
		printf("%s\n", anss[n - 1 - i]);
	}
	
}