#include <stdio.h>
#include <math.h>

/*
²Î¿¼×ÊÁÏ£º
https://wenku.baidu.com/view/a47786dc07a1b0717fd5360cba1aa81144318fef.html
https://hestyle.blog.csdn.net/article/details/104689962
*/

int main() {
    double n;
    while (scanf("%lf", &n) != EOF && n != 0) {
        printf("%.0lf\n", ceil(log(n) / log(3)));
    }
}