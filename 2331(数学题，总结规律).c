#include <stdio.h>

int main() {
	int a;
    int b;
	while(~scanf("%d%d",&a,&b)) {
		printf("%d", a * b);
		if(a % 2 && b % 2) {
            printf(".41");
        } else {
            printf(".00");
        }
		printf("\n");
	}
	return 0;
}
 