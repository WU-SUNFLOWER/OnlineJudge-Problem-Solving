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

int main() {
	int m;
	scanf("%d", &m);
    printf(isPrimeNumber(m) ? "prime" : "not prime");
}