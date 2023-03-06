#include <stdio.h>

int find(int ar[], int length, int key) {
    int i = 0;
    int j = length - 1;
    int m;
    int cnt = 0;
    // 此处i < j为错误写法！！！
    // 考虑如下的例子：
    // 1    2
    // ↑    ↑
    // i(m) j
    // 如果要查找到2，则必须移动i，
    // 使其与j重合，m指针才能正确定位！
    while (i <= j) {
        cnt++;
        m = (i + j) >> 1;
        if (ar[m] == key) {
            return cnt;
        }
        else if (ar[m] > key) {
            j = m - 1;
        }
        else {
            i = m + 1;
        }
    }
    return -1;
}

int main() {
    int tot;
    int ar[100];
    scanf("%d", &tot);
    while (tot-- > 0) {
        int key, length;
        scanf("%d %d", &key, &length);
        for (int i = 0; i < length; i++) {
            scanf("%d", &ar[i]);
        }
        int ans = find(ar, length, key);
        if (ans == -1) {
            puts("Not Found");
        } else {
            printf("%d\n", ans);
        }
    }
}