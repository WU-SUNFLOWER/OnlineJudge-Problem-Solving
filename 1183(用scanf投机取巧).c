#include <stdio.h>

int main() {
	char temp[20];
	int ans = 0;
	while (scanf("%s", temp) != EOF) {
		ans++;
	}
	printf("%d", ans);
}