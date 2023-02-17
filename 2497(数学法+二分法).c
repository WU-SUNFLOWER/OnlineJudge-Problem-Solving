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
        //如果根不在区间[l, m]上，则说明根在区间[m, r]上
        //故需及时将区间左端点调整为m，再搜索新区间[m, r]
		if (f(a, b, c, l) * f(a, b, c, m) > 0) {
			l = m;
		}
        //如果根在区间[l, m]上
        //将区间右端点调整为m，再搜索新区间[l, m]
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
