#include <stdio.h>
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

int compareDate(int y1, int m1, int d1, int y2, int m2, int d2) {
    //先判断年
    if (y1 > y2) {
        return 1;
    }
    else if (y1 < y2) {
        return -1;
    }
    //再判断月
    if (m1 > m2) {
        return 1;
    }
    else if (m1 < m2) {
        return -1;
    }
    //最后判断日
    if (d1 > d2) {
        return 1;
    }
    else if (d1 < d2) {
        return -1;
    }
    return 0;
}

int PrimeNumberMap[13];

int isPrimeNumber(int num) {
    if (PrimeNumberMap[num] != -1) {
        return PrimeNumberMap[num];
    }
    int ans = 1;
	if (num == 1) {
		ans = 0;
	} 
    else if (num == 2) {
        ans = 1;
    }
    else {
    	for (int i = 2; i <= sqrt(num); i++) {
    		if (num % i == 0) {
                ans = 0;
    		    break;
    		}
        }
    }
    PrimeNumberMap[num] = ans;
    return ans;
}

int main() {
    int n;
    int price1;  //素数月可赚的钱
    int price2;  //其他月可赚的钱
    for (int i = 1; i <=12; i++) {
        PrimeNumberMap[i] = -1;
    }
    while (~scanf("%d %d %d", &price1, &price2, &n)) {
        int year1;
        int month1;
        int day1;
        int year2;
        int month2;
        int day2;
        while (n-- > 0) {
            scanf("%d %d %d", &year1, &month1, &day1);
            scanf("%d %d %d", &year2, &month2, &day2);
            int ans = 0;
            int curYear = year1;
            int curMonth = month1;
            int curDay = day1;
            while (compareDate(year2, month2, day2, curYear, curMonth, curDay) >= 0) {
                ans += isPrimeNumber(curMonth) ? price1 : price2;
                curDay += 1;
                if (curDay > getTotalDay(curYear, curMonth)) {
                    curDay = 1;
                    curMonth += 1;
                }
                if (curMonth > 12) {
                    curMonth = 1;
                    curYear += 1;
                }
            }
            printf("%d\n", ans);            
        }
    }
}