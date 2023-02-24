# include<stdio.h>

int main() {
    int a;  //默认储存较大数
	int b;  //默认储存较小数
	int temp;
    scanf("%d %d", &a, &b);
	int multip = a * b;
    //调整数据位置
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    //辗转相除法
    while (b != 0) {
        temp = a;
        a = b;
        b = temp % b;
    }
    //依次输出两个整数的最小公倍数和最大公约数。
    printf("%d %d\n", multip / a, a);
    return 0;
}