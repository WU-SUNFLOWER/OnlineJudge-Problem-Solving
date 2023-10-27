#include<stdio.h>
#include<string.h>
#include<math.h>

int main() 
{
	char a;
	while (scanf("%c", &a) != EOF)
	{
		if (a == '<') printf("&LT;");
		else if (a == '>') printf("&GT;");
		else if (a == ' ') printf("&SPACE;");
		else if (a == '\t') printf("&TAB;");
		else printf("%c", a);
	}
	return 0;
}