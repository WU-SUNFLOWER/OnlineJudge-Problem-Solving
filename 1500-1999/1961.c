#include <stdio.h>
#include <math.h>

//���κ�һ����λ����3�η��������λ���ֹ��ɵ���
//����һ�����ڵ���10��С�ڵ���99������
//���������3�η�������������ֹ��ɵ���

//���룺11
//�����331

int main() {
	int a;
	int b;
	int c;
	int num;
	//��ʼ��num
	scanf("%d", &num);
	num = pow(num, 3);
	a = num / 100 % 10;
	b = num / 10 % 10;
	c = num % 10;
	printf("%d%d%d", a, b, c);
}