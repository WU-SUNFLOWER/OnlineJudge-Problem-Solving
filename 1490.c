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
    int n;
    //f[i]=1表示i为素数,0为质数,-1表示待判断
    int f[500];
    scanf("%d", &n);
    for (int i = 0; i < 500; i++) {
        f[i] = -1;
    }
    for (int i = 2; i <= n; i++) {
        if (f[i] == 1) {
            printf("%d\n", i);
        }
        else if (f[i] == -1 && isPrimeNumber(i)) {
            f[i] = 1;
            printf("%d\n", i);
            for (int j = 2; j * i <= n; j++) {
                f[j * i] = 0;
            }
        }
    }
}