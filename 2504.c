#include <stdio.h>

int arr[] = {0, 31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeapYear(int year) {
    return year % 4 == 0 && year % 100 != 0 ||
           year % 400 == 0;
}

int getTotalDay(int year, int month) {
    arr[2] = isLeapYear(year) ? 29 : 28;
    return arr[month];
}

int main() {
    int year;
    int month;
    int day;
    while (~scanf("%d %d %d", &year, &month, &day)) {
        if (year == 0) {
            break;
        }
        //计算从1月1日开始计算的总天数
        int totalDays = day;
        month--;
        while (month) {
            totalDays += getTotalDay(year, month--);
        }
        //已知条件：1952年1月1日是星期二
        //从1952年1月1日推算到当前年的1月1日，确定当前年元旦是星期几
        int startWeek = 2;
        for (int i = 1952; i < year; i++) {
            startWeek = (startWeek + (isLeapYear(i) ? 366 : 365) - 1) % 7 + 1;
        }
        //计算结果
        printf("%d\n", (startWeek + totalDays - 2) % 7 + 1);
    }
}