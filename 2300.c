#include <stdio.h>

int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	while (1) {
		int score;
		scanf("%d", &score);
		if (score <= 0) {
			break;
		}
		if (score >= 85) {
			a++;
		}
		else if (score >= 60) {
			b++;
		}
		else {
			c++;
		}
	}
	printf(">=85:%d\n60-84:%d\n<60:%d", a, b, c);
}