#include <stdio.h>

int main() {
    double x1, y1;
    double x2, y2;
    double x3, y3;
    double x4, y4;
    while (scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2) != EOF) {
        scanf("%lf %lf %lf %lf", &x3, &y3, &x4, &y4);
        //处理斜率不存在的特殊情况
        if (x1 == x2 && x3 == x4) {
            printf(x2 == x3 ? "Yes\n" : "No\n"); 
        } else {
            double k1 = (y2 - y1) / (x2 - x1);
            double k2 = (y4 - y3) / (x4 - x3);
            double b1 = y1 - k1 * x1;
            double b2 = y3 - k2 * x3;
            //当斜率不相等时，两直线必定相交
            //当斜率和截距都相等时，两直线重合
            if (k1 != k2 || k1 == k2 && b1 == b2) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
}