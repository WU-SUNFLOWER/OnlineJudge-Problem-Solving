#include <stdio.h>
#include <math.h>

/*
我们知道人民币有1、2、5、10、20、50、100这几种面值。 
现在给你n(1≤n≤250)元，让你计算换成用上面这些面额表示且总数不超过100张，共有几种。 
比如4元，能用4张1元、2张1元和1张2元、2张2元，三种表示方法。
*/

int f[251];
int valueData[7] = {1, 2, 5, 10, 20, 50, 100};

void dfs(int completeValue, int leftValue, int lastValueLevel, int leftChance) {
    if (leftValue < 0 || leftChance < 0) {
        return;
    }
    f[completeValue]++;
    for (int i = lastValueLevel; i < 7; i++) {
        dfs(completeValue + valueData[i], leftValue - valueData[i], i, leftChance - 1);
    }
}

int main() {
    int totalValue;
    for (int i = 0; i <= 250; i++) {
        f[i] = 0;
    }
    dfs(0, 250, 0, 100);
    while (scanf("%d", &totalValue) != EOF && totalValue != 0) {
        printf("%d\n", f[totalValue]);
    }
}