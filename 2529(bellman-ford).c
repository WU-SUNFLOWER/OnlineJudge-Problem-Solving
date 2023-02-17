#include <stdio.h>

const int Infinity = 1 << 30;

struct edge {
    int start;
    int end;
    int weight;
} Edge[20000];

int min(int a, int b) {
    return a > b ? b : a;
}

int main() {
    int totalNode;
    int totalAdj;
    int dist[1001];  //记录某节点到编号为1的起点的最短距离
    while (~scanf("%d %d", &totalNode, &totalAdj)) {
        //构建有向图
        for (int i = 0; i < totalAdj; i++) {
            scanf("%d %d %d", &Edge[i].start, &Edge[i].end, &Edge[i].weight);
        }
        //初始化dist数组
        dist[1] = 0;
        for (int i = 2; i <= totalNode; i++) {
            dist[i] = Infinity;
        }
        int ans = 0;
        int cnt = 0;  //记录dist数组被更新的总次数
        int temp = Infinity;
        while (1) {
            cnt++;
            //遍历所有有向图的边，更新dist数组，即所谓的“对边进行放松操作”
            //这里需要注意，如果题目中对通过边数有具体限制的，不能直接对dist数组进行串联操作
            //需要使用bellman-ford算法的原始动态规划版本，引入滚动数组以配合控制外层循环次数
            //具体参考：https://blog.csdn.net/crabstew/article/details/89159942
            for (int j = 0; j < totalAdj; j++) {
                struct edge cur = Edge[j];
                dist[cur.end] = min(dist[cur.end], dist[cur.start] + cur.weight);
            }
            /*
                对所有边完成一次放松操作后，可能出现如下的几种情况：
                一、dist[totalNode] < 0，则求解结束，退出循环
                二、dist[totalNode] >= 0，且cnt < n - 1，则无条件继续循环
                三、dist[totalNode] = Infinity，且cnt = n - 1，则问题肯定无解，退出循环
                四、0 <= dist[totalNode] < Infinity，且cnt >= n - 1
                    此时需要检查图中是否存在会影响dist值的负权环出现。
                    我们引入变量temp记入当前的dist值，再观测在后续放松操作后，其值是否会进一步减小。
                    如果减小，则说明dist值收到负权环影响，问题一定有解，反之则问题一定无解。
            */
            if (dist[totalNode] < 0 || dist[totalNode] < temp && cnt > totalNode - 1) {
                ans = 1;
                break;
            }
            else if (dist[totalNode] >= temp && cnt >= totalNode - 1) {
                ans = 0;
                break;
            }
            else if (cnt >= totalNode - 1) {
                temp = dist[totalNode];
            }
        }
        //输出答案
        printf(ans ? "YES\n" : "NO\n");
    }
}