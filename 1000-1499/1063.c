#include <stdio.h>
#include <math.h>


int main(){
    int n;
    long long f[91] = {0, 1, 2};
    for (int i = 3; i <= 90; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    while (scanf("%d", &n) != EOF && n != 0) {
        printf("%lld\n", f[n]);
    }
}
