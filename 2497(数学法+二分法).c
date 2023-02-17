#include <stdio.h>
#include <math.h>

double f(double a, double b, double c, double x) {
    return c / x + pow(x + 1, b) * (a - c / x);
}

double bisection(double a, double b, double c, double (*func)(double, double, double, double)) {
	double l = 0.001;
    double r = 1;
	while (r - l > 0.00001) {
		double m = (l + r) / 2;
        //�������������[l, m]�ϣ���˵����������[m, r]��
        //���輰ʱ��������˵����Ϊm��������������[m, r]
		if (f(a, b, c, l) * f(a, b, c, m) > 0) {
			l = m;
		}
        //�����������[l, m]��
        //�������Ҷ˵����Ϊm��������������[l, m]
		else {
			r = m;
		}
	}
	return l;
}

int main() {
    double a;
    double b;
    double c;
	scanf("%lf %lf %lf", &a, &b, &c);
    printf("%.3lf%%\n", bisection(a, b, c, f) * 100);
	return 0;
}
