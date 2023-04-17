#include <stdio.h>
#include <stdbool.h>
#define N 10

int top[N];

int bottom[N];

void outputAns() {
    for (int i = 0; i < N; i++) {
        printf(i == N - 1 ? "%d\n" : "%d ", bottom[i]);
    }
}

/*
    由题意，bottom数组应具有如下性质：
    1. 对于其中的任一元素bottom[i]，都有0 ≤ bottom[i] ≤10;
    2. bottom[0] + bottom[1] + ... + bottom[9] = 10;
    3. bottom[i]表示对应top[i]在bottom数组中出现的次数
*/
bool dfs(int sum, int idx) {
    // 如果sum还没满10，就尝试增加数字
    if (sum < N && idx < N) {
        for (int i = 0; i <= N - sum; i++) {
            int backup = bottom[idx];
            bottom[idx] = i;
            if (dfs(sum + i, idx + 1)) {
                return true;
            }
            bottom[idx] = backup;
        }
        return false;
    }
    // 如果sum已经满10，则校验当前组合是否符合题意
    else if (sum == N) {
        int cnt;
        for (int i = 0; i < N; i++) {
            cnt = 0;
            for (int j = 0; j < N; j++) {
                if (bottom[j] == top[i]) cnt++;
            }
            if (cnt != bottom[i]) return false;
        }
        outputAns();
        return true;
    }
    return false;
}

int main() {
    for (int i = 0; i < N; i++) {
        scanf("%d", &top[i]);
    }
    dfs(0, 0);
}