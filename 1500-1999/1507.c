#include <stdio.h>
#define LEAP_YEAR(year) (year % 4 == 0 && year % 100 != 0) || year % 400 == 0

int main() {
    int year;
    scanf("%d", &year);
    printf(LEAP_YEAR(year) ? "L" : "N");
}