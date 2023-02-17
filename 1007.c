#include <stdio.h>
#include <stdlib.h>

int* createIntArray(int length) {
	int* arr = (int*)malloc(sizeof(int) * length);
	return arr;
}

int main() {
	int N;
	while (scanf("%d", &N) != EOF) {
		if (N <= 0) {
			break;
		}
		int* data = createIntArray(N + 1);
		data[0] = 1;
		data[1] = 1;
		for (int n = 2; n <= N; n++) {
			data[n] = data[n - 2] + data[n - 1];
		}
		printf("%d\n", data[N]);
		free(data);
	}
	return 0;
}