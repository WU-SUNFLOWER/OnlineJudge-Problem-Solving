#include <stdio.h>

int main() {
    char str[100];
    char min;
    char max;
    gets(str);
    min = max = str[0];
    for (int i = 1; str[i]; i++) {
        str[i] > max && (max = str[i]);
        str[i] < min && (min = str[i]);
    }
    for (int i = 0; str[i]; i++) {
        str[i] != min && str[i] != max && putchar(str[i]);
    }
}