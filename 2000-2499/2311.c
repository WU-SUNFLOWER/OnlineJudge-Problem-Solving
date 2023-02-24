#include <stdio.h>

void statistics(int n, int s[], int* max, int* min, float* avg) {
    *max = s[0];
    *min = s[0];
    *avg = s[0];
    for (int i = 1; i < n; i++) {
        *min > s[i] && (*min = s[i]);
        *max < s[i] && (*max = s[i]);
        *avg += s[i];
    }
    *avg /= n;
}

int main() {
    int n = 0;
    int s[100];
    int max;
    int min;
    float avg;
    while (~scanf("%d", &s[n++]) && s[n - 1] != 0);
    n--;
    statistics(n, s, &max, &min, &avg);
    printf("Num=%d\nMax=%d\nMin=%d\nAvg=%.3f\n", n, max, min, avg);
}