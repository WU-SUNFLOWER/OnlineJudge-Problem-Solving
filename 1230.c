#include <stdio.h>
#include <math.h>

//求某个数的因数个数
int getSubCount(int n) {
    int ans = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ans += n / i == i ? 1 : 2;
        }
    }
    return ans;
}

int main() {
    int num;
    int map[1000];
    //打表
    //其实这题在应试的时候打表并不是最佳选择
    //因为题目并没有提供测试数据的数据范围
    //若数据范围过大则不适合打表，可能会引发超时等问题
    for (int i = 1; i <= 1000; i++) {
        map[i] = getSubCount(i);
    }
    while (~scanf("%d", &num)) {
        int tempNum;
        int ans;
        int ansCount;
        for (int i = 0; i < num; i++) {
            scanf("%d", &tempNum);
            if (i == 0) {
                ans = tempNum;
                ansCount = map[ans];
            } 
            else if (map[tempNum] > ansCount || map[tempNum] == ansCount && tempNum < ans) {
                ans = tempNum;
                ansCount = map[ans];
            }
        }
        printf("%d\n", ans);
    }
}