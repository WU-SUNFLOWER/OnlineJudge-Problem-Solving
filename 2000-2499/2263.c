#include <stdio.h>

/*
    �ο����ϣ�
    https://blog.csdn.net/Huberyxiao/article/details/104148871
    https://www.cnblogs.com/wushuaiyi/archive/2013/12/05/3460571.html
*/

const double PI = 3.1415926;

int main() {
    double R;
    double v1;  //����
    double v2;  //���˵��ٶ�
    while (~scanf("%lf %lf %lf", &R, &v1, &v2)) {
        double r = v1 / v2 * R;  //�Լ��͵��˽��ٶ���Ⱥ��Լ��˶�Բ�ܵİ뾶
        double t1 = (R - r) / v1;  //�Լ��͵��˽��ٶ���Ⱥ󣬳��򰶱���Ҫ��ʱ��
        double t2 = PI / (v2 / R);  //���˺��Լ��ٶ���Ⱥ󣬳����Լ���Ҫ��ʱ��
        printf(t1 > t2 ? "No\n" : "Yes\n");
    }
}