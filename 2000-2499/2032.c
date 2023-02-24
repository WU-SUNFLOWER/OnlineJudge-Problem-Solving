#include <stdio.h>
#include <math.h>

int main() {
    double H;
    const double g = 9.8;  //重力加速度
    const double m = 0.625;  //球的质量
    const double f = m * g * 0.5;  //水平阻力
    const double h0 = 1.75;  //身高
    const double h1 = 0.2;  //球到头顶的距离
    const double h2 = 3.05;  //篮筐到地面的距离
    const double h3 = 0.4;  //跳投时脚离地的距离
    const double r = 0.246 / 2;  //球的直径
    const double R = 0.45 / 2;  //篮筐的直径
    scanf("%lf", &H);
    double t1 = sqrt(2 * (H - h2) / g) + sqrt(2 * (H - h1 - h0) / g);
    double l1 = 0.5 * f / m * pow(t1, 2);
    double w1 = m * g * (H - h1 - h0) + f * l1;
    printf("原地: %.3lfm %.3lfJ\n", l1 + R - r, w1);
    double t2 = sqrt(2 * (H - h2) / g) + sqrt(2 * (H - h1 - h0 - h3) / g);
    double l2 = 0.5 * f / m * pow(t2, 2);
    double w2 = m * g * (H - h1 - h0 - h3) + f * l2;
    printf("跳投: %.3lfm %.3lfJ\n", l2 + R - r, w2);
}