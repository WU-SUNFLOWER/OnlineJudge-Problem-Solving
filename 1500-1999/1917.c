#include<stdio.h>
int main()
{
	double a,b,c,x1, x2;
	scanf_s("%lf %lf %lf", &a, &b, &c);
	x1 = (-b + sqrt(b * b - 4 * a * c))/(2*a);
	x2= (-b - sqrt(b * b - 4 * a * c))/(2*a);
	printf("%.2f %.2f", x1 , x2 );
	return 0;
}