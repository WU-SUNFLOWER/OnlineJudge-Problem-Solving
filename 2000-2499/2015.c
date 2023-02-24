#include <stdio.h>

int main() {
    float a;
    float h;
    float ans;
    scanf("%f,%f", &a, &h);
    ans = 0.5 * a * h;
    printf("三角形的面积为%.2f\n", ans);
}