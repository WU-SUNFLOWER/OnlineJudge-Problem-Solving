#include <stdio.h>
#define N 11

/*
参考资料：
https://blog.csdn.net/weixin_43272781/article/details/83095780
http://hzwer.com/453.html
*/

int self[N];
int enemy[N];
int ans = 0;

int max(int a, int b) {
    return a > b ? a : b;
}

void sort(int a[]) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j <= N - 2 - i; j++) {
            if (a[j] < a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

void dfs(int curAns, int s1, int t1, int s2, int t2) {
    //搜索结束，保存答案
    if (s1 > t1) {
        ans = max(ans, curAns);
        return;
    }
    //第一种情况：田忌的快马快于齐王的快马，则直接进行比赛
    if (self[s1] > enemy[s1]) {
        dfs(curAns + 1, s1 + 1, t1, s2 + 1, t2);
        return;
    }
    //第二种情况：当田忌的快马小于等于齐王的快马时，
    //先比较田忌的慢马和齐王的慢马，如果田忌的慢马比齐王的快，则直接比赛
    //否则则用田忌的慢马消耗掉齐王的快马
    if (self[t1] > enemy[t2]) {
        dfs(curAns + 1, s1, t1 - 1, s2, t2 - 1);
    } else {
        dfs(curAns, s1, t1 - 1, s2 + 1, t2);
    }
}

int main() {
    while (~scanf("%d", &self[0])) {
        for (int i = 1; i < N; i++) {
            scanf("%d", &self[i]);
        }
        for (int i = 0; i < N; i++) {
            scanf("%d", &enemy[i]);
        }
        //对双方的马进行降序排序
        sort(self);
        sort(enemy);
        //搜索最优解
        ans = 0;
        dfs(0, 0, N - 1, 0, N - 1);
        //输出答案
        printf("%d\n", ans);
    }
}