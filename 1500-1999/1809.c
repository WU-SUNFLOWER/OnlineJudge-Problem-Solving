#include <stdio.h>
#include <string.h>
#define N 10000

const int Infinity = 1 << 30;

int min(int a, int b) {
    return a > b ? b : a;
}

int max(int a, int b) {
    return a < b ? b : a;
}

/*
 链式前向星建图 开始
 参考资料：https://zhuanlan.zhihu.com/p/343092172
*/

//记录起始于每个节点的首个有向边id号
//Head[i]=-1表示id号为i的节点出度为0
int Heads[N];

//记录有向边信息的数组
struct {
    //记录当前有向边接于相同起始节点的邻边id号
    //如果当前有向边后已没有邻边，记next=-1
    int next;
    //记录当前有向边的指向节点id号
    int to;
} Edges[N];


//维护变量实时更新最新边的id号
int edgeId;

//创建有向边
void addEdge(int u, int v) {
    if (u < 0 || v < 0) {
        return;
    }
    Edges[edgeId].next = Heads[u];
    Edges[edgeId].to = v;
    Heads[u] = edgeId++;
}

//维护变量实时更新最新节点的id号
int curId;

void __create__(int preId, char str[]) {
    //为父节点和新创建的子节点添加边
    addEdge(preId, curId);
    //递归进行下一轮创建
    int tempPreId = curId;
    char ch = str[curId++];
    if (ch == '0') {
        return;
    } else if (ch == '1') {
        __create__(tempPreId, str);
    } else if (ch == '2') {
        __create__(tempPreId, str);
        __create__(tempPreId, str);
    }    
}

//根据二叉树序列建图
void createGraph(char str[]) {
    edgeId = curId = 0;
    memset(Heads, -1, sizeof(Heads));
    __create__(-1, str);
}

/* 链式前向星建图 结束 */

/* 树上dp代码 开始 */

int dp_min[N][2];
int dp_max[N][2];

void dfs(int curId) {
    //初始化最新搜索到节点的dp数组
    dp_min[curId][1] = 1;
    dp_max[curId][1] = 1;
    //第1种情况：当前节点填绿色，子节点都不填绿色
    //遍历当前节点的子节点，递归更新dp数组
    int cnt = 0;
    int sum1 = 0;
    int sum2 = 0;
    for (int i = Heads[curId]; i != -1; i = Edges[i].next) {
        int nextId = Edges[i].to;
        dfs(nextId);
        sum1 += dp_min[nextId][0];
        sum2 += dp_max[nextId][0];
        cnt++;
    }
    dp_min[curId][1] += sum1;
    dp_max[curId][1] += sum2;
    //第2种情况：当前节点不填绿色
    //  第2-1种情况：若该节点仅含1个子节点，则取该子节点填/不填绿色情况下的最优解
    //  第2-2种情况：若该节点含2个子节点，则其中必有1个子节点填绿色，逐个尝试取最优解即可
    int min_nonGreen = cnt == 2 ? Infinity : sum1;
    int max_nonGreen = cnt == 2 ? 0 : sum2;
    for (int i = Heads[curId]; i != -1; i = Edges[i].next) {
        int nextId = Edges[i].to;
        min_nonGreen = min(min_nonGreen, sum1 - dp_min[nextId][0] + dp_min[nextId][1]);
        max_nonGreen = max(max_nonGreen, sum2 - dp_max[nextId][0] + dp_max[nextId][1]);
    }
    dp_min[curId][0] = min_nonGreen;
    dp_max[curId][0] = max_nonGreen;
}

/* 树上dp代码 结束 */

int main() {
    char str[N];
    while (~scanf("%s", str)) {
        createGraph(str);
        dfs(0);
        printf("%d %d\n", max(dp_max[0][0], dp_max[0][1]), min(dp_min[0][0], dp_min[0][1]));
    }
}