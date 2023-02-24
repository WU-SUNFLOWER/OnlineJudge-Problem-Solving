#include <stdio.h>

int isUglyNumber(int num) {
    if (num == 1) {
        return 1;
    }
    else if (num % 2 == 0) {
        return isUglyNumber(num / 2);
    } 
    else if (num % 3 == 0) {
        return isUglyNumber(num / 3);
    } 
    else if (num % 5 == 0) {
        return isUglyNumber(num / 5);
    }
    else {
        return 0;
    }
}

int main() {
    int num;
    scanf("%d", &num);
    printf(isUglyNumber(num) ? "YES" : "NO");
}