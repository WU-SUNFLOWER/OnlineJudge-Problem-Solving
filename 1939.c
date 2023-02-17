#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int minAns = 0;
	int maxAns = 0;
	int flag = 1;
	int a;
	
	scanf("%d", &a);
	
	for (int x = 0; x <= a / 2; x++) {
		for (int y = 0; y <= a / 2; y++) {
			if (2 * x + 4 * y == a) {
				int ans = x + y;
				if (flag) {
					minAns = maxAns = ans;
					flag = 0;
				} else {
					ans < minAns && (minAns = ans);
					ans > maxAns && (maxAns = ans);					
				}

			}
		}
	}
	
	printf("%d %d", minAns, maxAns);
	
}