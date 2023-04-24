#include <stdio.h>
#include <stdlib.h>
#define N 1005

/*
参考资料：https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
*/

int ar[N];  // 存原始数组

typedef struct {
    int val;
    int pos;  
} Info;

int cmp(const void* p1, const void* p2) {
    return ((Info*)p1)->val - ((Info*)p2)->val;
}

int main() {
    int tot;
    int temp;
    while (~scanf("%d", &tot)) {
        Info ar[N];
        for (int i = 0; i < tot; i++) {
            scanf("%d", &ar[i].val);
            // 记录当前数值在原数组中的真实位置
            ar[i].pos = i;  
        }
        // 对原数组进行排序，以便知道原数组中各值在有序数组中的位置
        qsort(ar, tot, sizeof(Info), cmp);
        int ans = 0;
        int vis[N] = {0};
        for (int i = 0; i < tot; i++) {
            // 如果当前位置已经被收入进回路环
            // 或者在原数组中当前位置的数已经处于正确的位置
            if (vis[i] || ar[i].pos == i) continue;
            // 在原数组中，利用排序生成的位置信息递推求出回路环
            int cur = i;
            int cnt_edge = 0;  // 该变量统计图中边的个数  
            while (!vis[cur]) {
                vis[cur] = 1;
                // 从当前位置出发，访问目标位置
                // 该目标位置即为应该放在当前位置的数在原数组中的真实位置
                cur = ar[cur].pos;
                // 在图中添加一条边
                cnt_edge++;
            }
            ans += cnt_edge - 1;
        }
        printf("%d\n", ans);
    }
}