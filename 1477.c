#include<stdio.h>
#include<stdlib.h>
int main ()
{
	float r,h;
	float C1,Sa,Sb,Va,Vb;  //此处注意double和float的区别
	double PI=3.14;
    scanf("%f %f",&r, &h);
	C1=2*PI*r;
	Sa=PI*r*r;
	Sb=4*PI*r*r;
	Va=(4.0/3)*PI*r*r*r;
	Vb=PI*r*r*h;
	printf("C1=%.2f\nSa=%.2f\nSb=%.2f\nVa=%.2f\nVb=%.2f\n",C1,Sa,Sb,Va,Vb);
	return 0;
}