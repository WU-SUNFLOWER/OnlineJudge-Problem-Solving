#include <stdio.h>

int main() {
	//������year���жϸ����Ƿ�Ϊ���ꡣ�ж�����������ǣ��ܱ�4���������ܱ�100�����������ܱ�400������
	int year;
	scanf("%d", &year);
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		printf("%d��������", year);
	} else {
		printf("%d�겻������", year);
	}
}