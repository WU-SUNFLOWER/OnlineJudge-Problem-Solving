#include <stdio.h>
#include <math.h>

int main() {
    int left;
    int right;
    while (scanf("%d %d", &left, &right) != EOF) {
        int ans1 = 0;  //偶数的平方和
        int ans2 = 0;  //奇数的立方和
        for (int i = left; i <= right; i++) {
            if (i % 2 == 0) {
                ans1 += pow(i, 2);
            } else {
                ans2 += pow(i, 3);
            }
        }
        printf("%d %d\n", ans1, ans2);
    }
}