#include <stdio.h>

int values[100];
int weights[100];

int max(int a, int b) {
    return a < b ? b : a;
}

int dfs(int cur, int total, int leftVolume, int curValue) {
    // 当所有物品都放完后，返回当前的总价值
    if (cur >= total) {
        return curValue;
    }
    // 每种物品都有放和不放两种选择
    // 当背包容量足够时，可以尝试将物品放入
    if (leftVolume >= weights[cur]) {
        return max(
            dfs(cur + 1, total, leftVolume - weights[cur], curValue + values[cur]),
            dfs(cur + 1, total, leftVolume, curValue)
        );
    } 
    // 当前背包不能放下该物品，则只能不放
    else {
        return dfs(cur + 1, total, leftVolume, curValue);
    }
}

int main() {
    int total;
    int volume;
    // 物品件数，总重量
    scanf("%d %d", &total, &volume);
    // 重量，价值
    for (int i = 0; i < total; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }
    printf("%d\n", dfs(0, total, volume, 0));
}