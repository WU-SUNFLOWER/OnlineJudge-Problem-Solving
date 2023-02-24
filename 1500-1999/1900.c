#include <stdio.h>

int main() {
	float a;
	while (scanf("%f", &a) != EOF) {
		float s = 0;
		float n = 0;
		while (s <= a) {
			s += 1 / (++n);
		}
		printf("s=%.4f,n=%.0f\n", s, n);
	}
}