#include <stdio.h>

int main() {
    int n;
    float temp;
    float max;
    float min;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%f", &temp);
        if (i == 1) {
            max = min = temp;
        } else {
            temp > max && (max = temp);
            temp < min && (min = temp);
        }
    }
    printf("%.2f %.2f", max, min);
}