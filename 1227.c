#include <stdio.h>
#include <math.h>

int main() {
    int n;
    int h, m, s;
    double a, b, c;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &h, &m, &s);
        //��24Сʱ�Ƶ�Ч��12Сʱ�Ƶ�����
        h %= 12;
        //����ʱ��ת��
        a = 30 * h + m * 0.5 + s / 120.0;
        //�������ת��
        b = 6 * m + 0.1 * s;
        c = fabs(a - b);
        //��������ʱ�������12�㷽��
        //��ת�ǲ����180�ȣ���ȡ360��-ת�ǲ�
        if (c > 180) {
            c = 360 - c;
        }
        printf("%g\n", floor(c));
    }   
    return 0;
}