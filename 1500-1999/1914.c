#include <stdio.h>

int main() {
	int ans;
	int score;
	scanf("��������� %d", &score);
	if (90 <= score && score <= 100) {
		ans = 5;
	}
	else if (80 <= score && score <= 89) {
		ans = 4;
	}
	else if (70 <= score && score <= 79) {
		ans = 3;
	}
	else if (60 <= score && score <= 69) {
		ans = 2;
	}
	else {
		ans = 1;
	}
	printf("���Ӧ������� %d", ans);
}