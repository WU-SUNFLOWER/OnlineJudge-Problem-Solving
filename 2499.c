#include <stdio.h>
#include <math.h>

char decode(int num) {
    int count = 0;
    char ans = 0;
    while (num > 0) {
        ans = ans * 2 + num % 2;
        num /= 2;
        count++;
    }
    for (int i = 1; i <= 7 - count; i++) {
        ans *= 2;
    }
    return ans;
}

int main() {
    int ch;
    while (scanf("%d", &ch) != EOF && ch != 0) {
        printf("%c", decode(ch));
    }
}