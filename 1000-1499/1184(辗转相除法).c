# include<stdio.h>

int main() {
    int a;  //Ĭ�ϴ���ϴ���
	int b;  //Ĭ�ϴ����С��
	int temp;
    scanf("%d %d", &a, &b);
	int multip = a * b;
    //��������λ��
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    //շת�����
    while (b != 0) {
        temp = a;
        a = b;
        b = temp % b;
    }
    //�������������������С�����������Լ����
    printf("%d %d\n", multip / a, a);
    return 0;
}