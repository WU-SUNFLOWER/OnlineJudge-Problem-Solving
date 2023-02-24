##include <stdio.h>
#include<stdlib.h>
int main() {
	int l;
	scanf("%d", &l);
	int* num = (int*)malloc(sizeof(int) * l);
	int i = 1;
	while (i <= l) {
		scanf("%d", &num[i++]);
	}
	int target;
	scanf("%d", &target);
	int t = num[target];
	num[target] = num[target + 1];
	num[target + 1] = t;
	for (int j = 1; j <= l; j++) {
		printf("%d ", num[j]);
	}
	return 0;
}