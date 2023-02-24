#include <stdio.h>
#include <math.h>

int main() {
    double H;
    const double g = 9.8;  //�������ٶ�
    const double m = 0.625;  //�������
    const double f = m * g * 0.5;  //ˮƽ����
    const double h0 = 1.75;  //���
    const double h1 = 0.2;  //��ͷ���ľ���
    const double h2 = 3.05;  //���𵽵���ľ���
    const double h3 = 0.4;  //��Ͷʱ����صľ���
    const double r = 0.246 / 2;  //���ֱ��
    const double R = 0.45 / 2;  //�����ֱ��
    scanf("%lf", &H);
    double t1 = sqrt(2 * (H - h2) / g) + sqrt(2 * (H - h1 - h0) / g);
    double l1 = 0.5 * f / m * pow(t1, 2);
    double w1 = m * g * (H - h1 - h0) + f * l1;
    printf("ԭ��: %.3lfm %.3lfJ\n", l1 + R - r, w1);
    double t2 = sqrt(2 * (H - h2) / g) + sqrt(2 * (H - h1 - h0 - h3) / g);
    double l2 = 0.5 * f / m * pow(t2, 2);
    double w2 = m * g * (H - h1 - h0 - h3) + f * l2;
    printf("��Ͷ: %.3lfm %.3lfJ\n", l2 + R - r, w2);
}