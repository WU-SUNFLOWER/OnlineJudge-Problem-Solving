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
        //�����1��1�տ�ʼ�����������
        int totalDays = day;
        month--;
        while (month) {
            totalDays += getTotalDay(year, month--);
        }
        //��֪������1952��1��1�������ڶ�
        //��1952��1��1�����㵽��ǰ���1��1�գ�ȷ����ǰ��Ԫ�������ڼ�
        int startWeek = 2;
        for (int i = 1952; i < year; i++) {
            startWeek = (startWeek + (isLeapYear(i) ? 366 : 365) - 1) % 7 + 1;
        }
        //������
        printf("%d\n", (startWeek + totalDays - 2) % 7 + 1);
    }
}