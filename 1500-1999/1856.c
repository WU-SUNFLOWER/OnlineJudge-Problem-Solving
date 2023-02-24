#include <stdio.h>

void swap(int* x, int* y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int max(int a, int b, int c) {
    if (a > b) {
        swap(&a, &b);
    }
    if (b > c) {
        swap(&b, &c);
    }
    return c;
}

/*
    参数i：记录扫描数组的位置
    参数n: 数组长度
    参数sum: 记录最优的子数组合
*/
int dfs(int ar[], int i, int n, int sum) {
    if (i < n) {
        // 对于数组中的每个元素，都有纳入最优解，和抛弃两种情况
        sum = max(
            sum,
            dfs(ar, i + 1, n, sum + ar[i]),
            dfs(ar, i + 1, n, 0)
        );
    }
    return sum;
}

int main() {
    int temp;
    int ar[100];
    int idx = 0;
    while (~scanf("%d", &temp)) {
        ar[idx++] = temp;
    }
    printf("%d", dfs(ar, 0, idx, 0));
}