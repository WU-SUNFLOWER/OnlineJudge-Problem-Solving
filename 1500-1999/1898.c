#include <stdio.h>
#include <math.h>

/*
���ǵ���������ݿ����㹻�������char����������ַ������򣬳����ֱ�ӱ�����
*/

int main() {
	int num;
	scanf("%d", &num);
	if (num == 0) {
		printf("0");
	}
	while (num > 0) {
		printf("%d", num % 10);
		num /= 10;
	}
}