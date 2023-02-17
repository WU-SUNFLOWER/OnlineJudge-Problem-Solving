#include <stdio.h>

char transform(int num) {
    if (num <= 9) {
        return '0' + num;
    } else {
        return 'a' + num - 10;
    }
}

int main() {
    int num;
    int idx = 0;
    char ans[100];
    scanf("%d", &num);
    while (num > 0) {
        ans[idx++] = transform(num % 16);
        num /= 16;
    }
    for (int i = idx - 1; i >= 0; i--) {
        printf("%c", ans[i]);
    }
}