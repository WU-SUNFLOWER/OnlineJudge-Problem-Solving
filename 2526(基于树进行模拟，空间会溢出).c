#include <stdio.h>
#define N 1000010

//本题采用数组的形式模拟树
//TreeNodeArr[i]的值表示，编号为i的节点所在树根节点的编号
int TreeNodeArr[N];

//搜索节点TreeNodeArr[i]隶属树的根节点
//并在搜索结束的回溯过程中，顺便更新途径的父节点
//亦将这些父节点指向树的根节点，实现路径压缩优化(否则会超时)
int findRoot(int i) {
    //根节点的判断方法：当TreeNodeArr[i] == i时，
    //表明该节点的父节点即为自身，说明该节点就是树的根节点
    if (TreeNodeArr[i] != i) {
        TreeNodeArr[i] = findRoot(TreeNodeArr[i]);
    }
    return TreeNodeArr[i];
}

int main() {
    int testNum;
    scanf("%d", &testNum);
    while (testNum-- > 0) {
        int n;  //原有的队伍总数
        int m;  //合并队伍命令总数
        int ans = 0;
        scanf("%d %d", &n, &m);
        //初始化，为每个队伍分配一棵独立的仅含一个节点的树
        for (int i = 1; i <= n; i++) {
            TreeNodeArr[i] = i;
        }
        //实现队伍合并
        //将队伍a所处的树的根节点指向队伍b所处的树的根节点
        int a, b;
        while (m--) {
            scanf("%d %d", &a, &b);
            TreeNodeArr[findRoot(a)] = findRoot(b);
        }
        //遍历所有的节点，通过统计根节点的方法，
        //统计出独立树的个数，即为合并后剩余队伍的总数
        for (int i = 1; i <= n; i++) {
            if (TreeNodeArr[i] == i) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}