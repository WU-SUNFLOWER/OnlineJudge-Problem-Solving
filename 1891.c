#include <stdio.h>

int main() {
    int a;
    int b;
    int c;
    int t;
    scanf("%d %d %d", &a, &b, &c);
    //��ʵ����ģ��ѡ�������˼·
    //�Ȱ���Сλ�̶���������ȷ����Сλ�����ľ������λ
    if (a > b) {
        t = a;
        a = b;
        b = t;
    }
    if (a > c) {
        t = a;
        a = c;
        c = t;
    }
    if (b > c) {
        t = b;
        b = c;
        c = t;
    }
    printf("%d %d %d", a, b, c);    
}