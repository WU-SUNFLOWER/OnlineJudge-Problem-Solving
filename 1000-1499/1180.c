#include <stdio.h>
#include <math.h>

/*
12:01:12
13:09:43

1:08:31

注意：本题并没有说时间点1肯定先于时间点2。
*/

int main() {
	int time1;
	int time2;
	int deltaTime;
	int hour1, minute1, second1;
	int hour2, minute2, second2;
	int hour3, minute3, second3;
	scanf("%d:%d:%d", &hour1, &minute1, &second1);
	scanf("%d:%d:%d", &hour2, &minute2, &second2);
	time1 = second1 + 60 * minute1 + 3600 * hour1;
	time2 = second2 + 60 * minute2 + 3600 * hour2;
	deltaTime = abs(time1 - time2);
	hour3 = deltaTime / 3600;
	minute3 = deltaTime / 60 % 60;
	second3 = deltaTime % 60;
	printf("%d:%02d:%02d", hour3, minute3, second3);
}