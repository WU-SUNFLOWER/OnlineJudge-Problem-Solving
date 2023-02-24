#include <stdio.h>
#include <math.h>

int isNotPrime[33] = {1, 1, 0};

int isUsed[17] = {0, 1, 0};

void dfs(int ans[], int curLen, int lastNum, int totLen) {
    if (curLen == totLen) {
        if (isNotPrime[1 + lastNum]) {
            return;
        }
        for (int i = 0; i < totLen; i++) {
            printf(i == totLen - 1 ? "%d\n" : "%d ", ans[i]);
        }
        return;
    }
    for (int i = 2; i <= totLen; i++) {
        if (!isUsed[i] && !isNotPrime[i + lastNum]) {
            isUsed[i] = 1;
            ans[curLen] = i;
            dfs(ans, curLen + 1, i, totLen);
            isUsed[i] = 0;
            ans[curLen] = 0;
        }
    }
}

int main() {
    //采用筛法确定素数
    for (int i = 2; i <= 32; i++) {
        if (isNotPrime[i]) {
            continue;
        }
        for (int j = 2; j * i <= 32; j++) {
            isNotPrime[j * i] = 1;
        }
    }
    int n;
    int ans[16] = {1};
    scanf("%d", &n);
    dfs(ans, 1, 1, n);
}
