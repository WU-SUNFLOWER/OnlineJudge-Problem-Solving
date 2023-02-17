#include <stdio.h>

int main() {
    int score;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    while (~scanf("%d", &score) && score > 0) {
        if (score >= 85) {
            sum1++;
        }
        else if (score < 60) {
            sum3++;
        }
        else {
            sum2++;
        }
    }
    printf(">=85:%d\n60-84:%d\n<60:%d\n", sum1, sum2, sum3);
}