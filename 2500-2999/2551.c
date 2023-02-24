#include <stdio.h>
#include <math.h>

int factorsum(int num) {
	int sum = 1;
	//����1������ֻ�б��������ӺͲ��ܰ������Լ�������������⴦��
	if (num == 1) {
		return 0;
	}
	for (int x = 2; x <= sqrt(num); x++) { 
		if (num % x == 0) {
			sum += (x == num / x ? x : (x + num / x));
		}
	}
	return sum;
}

int main() {
    int a;
    int b;
    while (~scanf("%d %d", &a, &b)) {
        if (a == factorsum(b) && factorsum(a) == b) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}