#include <stdio.h>

int main() {
    int a;
    int b;
    int c;
    int t;
    scanf("%d %d %d", &a, &b, &c);
    //其实就是模仿选择排序的思路
    //先把最小位固定下来，再确定次小位，最后的就是最大位
    if (a > b) {
        t = a;
        a = b;
        b = t;
    }
    if (a > c) {
        t = a;
        a = c;
        c = t;
    }
    if (b > c) {
        t = b;
        b = c;
        c = t;
    }
    printf("%d %d %d", a, b, c);    
}