#include <stdio.h>
#include <math.h>

int isPrimeNumber(int num) {
    int ans = 1;
	if (num == 1) {
		ans = 0;
	} else {
    	for (int i = 2; i <= sqrt(num); i++) {
    		if (num % i == 0) {
                ans = 0;
    		    break;
    		}
        }
    }
    return ans;
}

int main() {
    //素数打表
    int primeNumberArr[101];
    int primeNumberCount = 0;
    for (int i = 1; i <= 100; i++) {
        if (isPrimeNumber(i)) {
            primeNumberArr[primeNumberCount++] = i;
        }
    }
    int num;
    while (~scanf("%d", &num)) {
        //尝试对阶乘展开式中的每一项进行素因子的分解
        int maxPrimeIdx = 0;
        int bucket[101] = {0}; //统计因式分解的情况
        for (int i = 2; i <= num; i++) {
            int term = i;
            //此处大胆进行分解即可
            //因为任何一个自然数都可以分解为素数的乘积
            int j = 0;
            while (term > 1) {
                if (term % primeNumberArr[j] == 0) {
                    term /= primeNumberArr[j];
                    bucket[j] += 1;
                    j > maxPrimeIdx && (maxPrimeIdx = j);
                } else {
                    j++;
                }
            }
        }
        //输出
        printf("%d!= ", num);
        for (int i = 0; i <= maxPrimeIdx; i++) {
            printf(i == maxPrimeIdx ? "%d" : "%d ", bucket[i]);
        }
        printf("\n");
    }
}