#include <stdio.h>

int main() {
	int a;
	int b;
	int ans;
	scanf("%d,%d", &a, &b);
	scanf("%d", &ans);
	printf(a + b == ans ? "right" : "error");
}