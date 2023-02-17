#include <stdio.h>

/*
    参考资料：
    https://blog.csdn.net/Huberyxiao/article/details/104148871
    https://www.cnblogs.com/wushuaiyi/archive/2013/12/05/3460571.html
*/

const double PI = 3.1415926;

int main() {
    double R;
    double v1;  //船速
    double v2;  //敌人的速度
    while (~scanf("%lf %lf %lf", &R, &v1, &v2)) {
        double r = v1 / v2 * R;  //自己和敌人角速度相等后，自己运动圆周的半径
        double t1 = (R - r) / v1;  //自己和敌人角速度相等后，冲向岸边需要的时间
        double t2 = PI / (v2 / R);  //敌人和自己速度相等后，冲向自己需要的时间
        printf(t1 > t2 ? "No\n" : "Yes\n");
    }
}