#include <stdio.h>
#include <math.h>

int isPrimeNumber(int num) {
	if (num == 1) {
		return 0;
	}
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int Prime(int m, int n, int* nums) {
    for (; m <= n; m++) {
        if (isPrimeNumber(m)) {
            *(nums++) = m;
        }
    }
    *nums = 0;
}

int main() {
    int m;
    int n;
    int nums[100];
    scanf("%d %d", &m, &n);
    Prime(m, n, &nums[0]);
    for (int i = 0; nums[i]; i++) {
        printf("%d\n", nums[i]);
    }
}