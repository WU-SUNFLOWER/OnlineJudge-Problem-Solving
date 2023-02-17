#include <stdio.h>

//大数组不能在函数体内部定义，需要定义在全局环境中
//因为函数体允许申请的内存空间较小，全局环境采用静态储存区，允许申请的内存空间大
int f[1000000] = {0, 1};

int main() {
	int n;
    int k = 3;
    for (int i = 2; i < 1000000; i++) {
    	f[i] = (f[i - 1] + k - 1) % i + 1;
	}
    while (~scanf("%d", &n) && n != 0) {
        printf("%d\n", f[n]);
    }
    return 0;
}