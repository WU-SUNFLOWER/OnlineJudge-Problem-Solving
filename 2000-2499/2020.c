#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    double x;
    double y;
    double module;
} Vector;

Vector createVector(Point a, Point b) {
    Vector v = {b.x - a.x, b.y - a.y};
    v.module = sqrt(v.x * v.x + v.y * v.y);
    return v;
}

// 余弦定理，求v1和v2对应线段围成夹角的余弦值
double getAngleCosine(Vector v1, Vector v2, Vector v3) {
    double a = v1.module;
    double b = v2.module;
    double c = v3.module;
    return (a * a + b * b - c * c) / (2 * a * b);
}

// 判定两向量是否共线
bool isParallel(Vector v1, Vector v2) {
    if (v1.x == 0 || v2.x == 0) {
        return !v1.x && !v2.x;
    }
    else if (v1.y == 0 || v2.y == 0) {
        return !v1.y && !v2.y;
    }
    else {
        return v1.x / v2.x == v1.y / v2.y;
    }
}

// 求三项中的最大值
double max(double a, double b, double c) {
    if (a > b) b = a;
    return b > c ? b : c;
}

double solve(Point p1, Point p2, Point p3) {
    Vector v1 = createVector(p1, p2);
    Vector v2 = createVector(p1, p3);
    Vector v3 = createVector(p2, p3);
    //若3点组成直角或钝角三角形，或3点共线，此时，最小圆的半径为三边中最长边的一半
    if (
        isParallel(v1, v2)
        || getAngleCosine(v1, v2, v3) <= 0
        || getAngleCosine(v1, v3, v2) <= 0
        || getAngleCosine(v2, v3, v1) <= 0
    ) {
        return max(v1.module, v2.module, v3.module) / 2;
    } 
    // 否则，3点组成锐角三角形，最小圆为3点的外接圆
    double a = v1.module;
    double b = v2.module;
    double c = v3.module;
    // 海伦定理解出三角形面级
    double l = (a + b + c) / 2;
    double s = sqrt(l * (l - a) * (l - b) * (l - c));
    // 套公式解出外接圆半径
    return a * b * c / (4 * s);
}

int main() {
    int total;
    Point points[100];
    scanf("%d", &total);
    for (int i = 0; i < total; i++) {
        scanf("%lf,%lf", &points[i].x, &points[i].y);
    }
    // 任取三点，枚举所有情况
    double ans = 0;
    for (int i = 0; i < total; i++) {
        for (int j = i + 1; j < total; j++) {
            for (int k = j + 1; k < total; k++) {
                Point p1 = points[i];
                Point p2 = points[j];
                Point p3 = points[k];
                double temp = solve(p1, p2, p3);
                ans = max(ans, temp, 0);
            }
        }
    }
    printf("以上%d个点的覆盖圆的最小半径为%.4lf\n", total, ans);
}