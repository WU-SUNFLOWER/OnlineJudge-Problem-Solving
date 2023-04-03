#include <stdio.h>
#include <string.h>

/*
参考资料：
https://blog.csdn.net/seagal890/article/details/94845465
https://zh.wikipedia.org/zh-cn/%E4%B8%80%E7%AC%94%E7%94%BB%E9%97%AE%E9%A2%98
*/

int main() {
    int total;
    int num_node;
    int num_edge;
    int edges[1005] = {0};
    while (1) {
        memset(edges, 0, sizeof(edges));
        scanf("%d %d", &num_node, &num_edge);
        if (!num_node) break;
        for (int i = 0; i < num_edge; i++) {
            int from, to;
            scanf("%d %d", &from, &to);
            edges[from]++;
            edges[to]++;
        }
        int flag = 1;
        // 无向图存在欧拉回路的充要条件：
        // 图连通，所有顶点都是偶数度  （也就是说所有的节点全是偶点，没有奇点）
        for (int i = 1; i <= num_node; i++) {
            if (edges[i] == 0 || edges[i] % 2 != 0) {
                flag = 0;
                break;
            }
        }
        puts(flag ? "YES" : "NO");
    }
}