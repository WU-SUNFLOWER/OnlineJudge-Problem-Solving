#include <stdio.h>

/*
分治法求x的n次方，时间复杂度为O(logn)

简单证明如下：
随着递归进行，求解问题的转变情况为x^n -> x^(n/2) -> x^(n/4) -> …… -> x^1
设递归进行的总次数为k，则有n/(2^k)=1，解得k=logn
故该算法的时间复杂度为O(logn)
*/
int powerN(int x,int n){
    if (n == 0) {
        return 1;
    }
    int result = powerN(x, n / 2);
    // 如果n为奇数，需要补上一个x
    if (n & 1) {
        return result * result * x;
    }
    // 如果n为偶数，直接返回结果
    else {
        return result * result;
    }
}

int main() {
    printf("%d", powerN(5, 5));
}