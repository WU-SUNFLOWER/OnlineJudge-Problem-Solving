#include <stdio.h>
#include <math.h>

#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")

typedef long long ll;

int main() {
    ll n, exp;
    scanf("%lld", &n);
    const ll sq = sqrt(n) + 1;
    for (ll i = 2; i <= sq; i++) {
        exp = 0;
        while (n % i == 0) {
            exp++;
            n /= i;
        }
        if (exp) printf("%lld %lld\n", i, exp);
    }
    if (n > 1) {
        printf("%lld %lld\n", n, 1);
    }
    return 0;
}
