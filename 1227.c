#include <stdio.h>
#include <math.h>

int main() {
    int n;
    int h, m, s;
    double a, b, c;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &h, &m, &s);
        //将24小时制等效成12小时制的问题
        h %= 12;
        //计算时针转角
        a = 30 * h + m * 0.5 + s / 120.0;
        //计算分针转角
        b = 6 * m + 0.1 * s;
        c = fabs(a - b);
        //如果分针和时针相对于12点方向
        //的转角差大于180度，则取360度-转角差
        if (c > 180) {
            c = 360 - c;
        }
        printf("%g\n", floor(c));
    }   
    return 0;
}