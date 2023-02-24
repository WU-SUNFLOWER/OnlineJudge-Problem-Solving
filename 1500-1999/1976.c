#include <stdio.h>

int main() {
	//输入年year，判断该年是否为闰年。判断闰年的条件是：能被4整除但不能被100整除，或者能被400整除。
	int year;
	scanf("%d", &year);
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		printf("%d年是闰年", year);
	} else {
		printf("%d年不是闰年", year);
	}
}