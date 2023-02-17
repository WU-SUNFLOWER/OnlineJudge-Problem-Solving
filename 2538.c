#include <stdio.h>
#include <math.h>

int PrimeNumberMap[65537];

int isPrimeNumber(int num) {
    if (PrimeNumberMap[num] != -1) {
        return PrimeNumberMap[num];
    }
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
    PrimeNumberMap[num] = ans;
    return ans;
}

int main() {
    for (int i = 0; i < 65537; i++) {
        PrimeNumberMap[i] = -1;
    }
    int left;
    int right;
    while (~scanf("%d %d", &left, &right)) {
        int sum = 0;
        if (left > right) {
            int temp = left;
            left = right;
            right = temp;
        }
        for (left += 1; left < right; left++) {
            if (isPrimeNumber(left)) {
                sum += left;
            }
        }
        printf("%lld\n", sum);
    }
}