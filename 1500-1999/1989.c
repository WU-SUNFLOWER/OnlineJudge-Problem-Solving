#include <stdio.h>
#include <math.h>

int isPrimeNumber(int num) {
	for (int x = 2; x <= sqrt(num); x++) {
		if (num % x == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int num;
	int flag = 1;
	scanf("%d", &num);
	printf("%d=", num);
	while (num > 1) {
		for (int x = 2; x <= num; x++) {
			if (num % x == 0 && isPrimeNumber(x)) {
				num /= x;
				printf(flag ? "%d" : "*%d", x);
				flag = 0;
				break;
			}
		}
	}	
}