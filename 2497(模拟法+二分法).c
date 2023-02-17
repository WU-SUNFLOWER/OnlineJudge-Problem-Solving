#include <stdio.h>
#include <math.h>

int main() {
    double a;
    double b;
    double c;
	scanf("%lf %lf %lf", &a, &b, &c);
    double l = 0;
    double r = 1;
    while (r - l > 0.000001) {
        double mid = (l + r) / 2;
        double curMonth = 1;
        double leftMoney = a * (1 + mid) - c;
        while (leftMoney > 0) {
            leftMoney = leftMoney * (1 + mid) - c;
            curMonth++;
            //���һ����Ǯ���ĵ��·ݱ�b���࣬��������ƫ�󣬻��������
            if (curMonth > b) {
                r = mid;
                break;
            }
        }
        //���������Ǯ���ĵ��·ݱ�b��С����������ƫС�����������
        //����������������·��Ѿ�����b�ˣ����������l,r�Աƽ���ȷ��
        if (curMonth <= b) {
            l = mid;
        }
    }
    printf("%.3lf%%\n", l * 100);
}