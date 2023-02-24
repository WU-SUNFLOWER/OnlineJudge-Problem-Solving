#include <stdio.h>
int main() {
	//10
	//1 2 3 4 5 6 7 8 9 10
	int n ,a,b,H;
	a=0;
	H=0;
	scanf("%d",&n);
	while (a<n) {
        a=a+1;
        scanf("%d",b);
        if(b%2==0) {
            H=H+b;
            printf("%d", b);
        }
    }
    printf("%d",H);
	return 0;
}