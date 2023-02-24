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
	int startNum;
	int count;
	scanf("%d %d", &startNum, &count);
	while (count > 0) {
		if (isPrimeNumber(++startNum)) {
			printf("%d\n", startNum);
			count--;
		}
	}
}