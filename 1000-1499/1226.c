#include <stdio.h>

int record[30001];

int check(int num) {
    if (record[num] != -1) {
        return record[num];
    }
    if (num % 7 == 0) {
        return (record[num] = 1);
    }
    int temp = num;
    while (temp > 0) {
        if (temp % 10 == 7) {
            return (record[num] = 1);
        }
        temp /= 10;
    }
    return (record[num] = 0);
}

int main() {
    int top;
    for (int i = 7; i <= 30000; i++) {
        record[i] = -1;
    }
    while (scanf("%d", &top) != EOF) {
        for (int x = 7; x <= top; x++) {
            check(x) && printf("%d\n", x);
        }
    }
}