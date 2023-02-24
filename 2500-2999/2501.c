#include <stdio.h>

typedef long long ll;

ll getDigit(ll num) {
    ll ans = 0;
    while (num > 0) {
        ans++;
        num /= 10;
    }
    return ans;
}

ll getSum(ll num) {
    ll ans = 0;
    while (num > 0) {
        ans += num % 10;
        num /= 10;
    }
    return ans;
}

int main() {
    ll num;
    while (~scanf("%lld", &num) && num != 0) {
        while (getDigit(num) > 1) {
            num = getSum(num);
        }
        printf("%lld\n", num);
    }
}