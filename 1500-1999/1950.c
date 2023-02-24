#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return 1;
	} else {
		return 0;
	}
}

int getTotalDay(int year, int month) {
	int ans;
	if (month == 1 || month == 3 || month == 5 || month == 7|| month == 8 || month == 10 || month == 12) {
		ans = 31;
	}
	else if (month == 2) {
		ans = isLeapYear(year) ? 29 : 28;
	}
	else {
		ans = 30;
	}
	return ans;
}

int main() {
	int year;
	int month;
	int day;
	int ans = 0;
	scanf("%d %d %d", &year, &month, &day);
	for (int i = 1; i < month; i++) {
		ans += getTotalDay(year, i);
	}
	ans += day;
	printf("%d", ans);
}