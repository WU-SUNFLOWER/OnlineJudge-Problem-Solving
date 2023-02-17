#include <stdio.h>
#include <math.h>

double min(double a, double b) {
    return a > b ? b : a;
}

/*
关键点：
1.牛郎只考虑搭乘坐标≤0的喜鹊，因为坐标>0的喜鹊要么速度偏小，没必要换乘；要么速度偏大，追都追不上。
2.没有必要考虑牛郎先乘坐向反方向运动的喜鹊，以换乘速度更大的向正向运动的喜鹊。
实际上这种情形和牛郎乘坐运动较慢的喜鹊，等待速度更大的喜鹊追上，消耗的时间是完全相等的。
3.实际上牛郎没有必要考虑换成喜鹊。
既然牛郎可以任意选择搭乘喜鹊的时机，他只要等到坐标≤0的喜鹊中抵达目的地时间最短的喜鹊抵达坐标原点，直接搭上一路坐到底即可！
*/

int main() {
    int width;
    int num;
    while (~scanf("%d %d", &width, &num)) {
        if (width == 0 && num == 0) {
            break;
        }
        width *= 1000;
        double pos;
        double speed;
        double ans = pow(2, 31) - 1;
        for (; num > 0; num--) {
            scanf("%lf %lf", &pos, &speed);
            if (pos <= 0 && speed > 0) {
                ans = min(ans, (width - pos) / speed);
            }
        }
        if (ans == pow(2, 31) - 1) {
            printf("Can't Solve\n");
        } else {
            printf("%d\n", (int)ans);
        }
    }
}