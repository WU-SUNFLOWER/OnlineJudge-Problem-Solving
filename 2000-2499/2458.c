#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 100

int nameToId[0x7f];

char idToName[N];

int Graph[N][N];

char minChar(char c1, char c2) {
    return c1 > c2 ? c2 : c1;
}

char maxChar(char c1, char c2) {
    return c1 < c2 ? c2 : c1;
}

void dfs(int cur, int num_node, bool vis[], int* idx_ans, char ans[]) {
    vis[cur] = true;
    for (int i = 0; i < num_node; i++) {
        if (Graph[cur][i] && !vis[i]) {
            ans[(*idx_ans)++] = minChar(idToName[cur], idToName[i]);
            ans[(*idx_ans)++] = maxChar(idToName[cur], idToName[i]);
            dfs(i, num_node, vis, idx_ans, ans);       
        }
    }
}

int main() {
    char buf[N];
    int num_node;
    int num_edge;
    scanf("%d", &num_node);
    // 建立节点编号和节点数据的映射关系
    for (int i = 0; i < num_node; i++) {
        char name;
        scanf("%s", buf);
        name = buf[0];
        nameToId[name] = i;
        idToName[i] = name;
    }
    // 邻接矩阵建图
    scanf("%d", &num_edge);
    for (int i = 0; i < num_edge; i++) {
        char from, to;
        int from_id, to_id;
        scanf("%s", buf);
        sscanf(buf, "%c,%c", &from, &to);
        from_id = nameToId[from];
        to_id = nameToId[to];
        Graph[from_id][to_id] = 1;
        Graph[to_id][from_id] = 1;
    }
    bool vis[N];  
    int idx_ans = 0;
    char ans[N];
    memset(vis, false, sizeof(vis));  
    // 对图进行dfs,生成dfs生成树
    dfs(0, num_node, vis, &idx_ans, ans);
    // 判断是否是连通图
    int isConnected = true;
    for (int i = 0; i < num_node; i++) {
        if (!vis[i]) {
            isConnected = false;
            break;
        }
    }
    if (isConnected) {
        for (int i = 0; i < idx_ans; i += 2) {
            printf("%c,%c\n", ans[i], ans[i + 1]);
        }        
    } else {
        puts("ERROR");
    }
}