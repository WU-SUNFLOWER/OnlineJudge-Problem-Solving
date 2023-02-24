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
            //情况一：还钱消耗的月份比b还多，表面利率偏大，还款更吃力
            if (curMonth > b) {
                r = mid;
                break;
            }
        }
        //情况二：还钱消耗的月份比b还小，表面利率偏小，还款更轻松
        //情况三：还款消耗月份已经等于b了，则继续调整l,r以逼近精确解
        if (curMonth <= b) {
            l = mid;
        }
    }
    printf("%.3lf%%\n", l * 100);
}