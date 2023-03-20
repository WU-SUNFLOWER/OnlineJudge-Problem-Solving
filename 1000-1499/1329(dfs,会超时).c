#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 101

int EdgeCnt[N];
int Edges[N][N];

bool vis[N];

bool check(int num_node) {
    for (int i = 1; i <= num_node; i++) {
        if (!vis[i]) return false;
    }
    return true;
}

bool dfs(int curNode, int startNode, int num_node) {
    if (curNode == startNode && check(num_node)) {
        return true;
    }
    for (int i = 0; i < EdgeCnt[curNode]; i++) {
        int nextNode = Edges[curNode][i];
        if (!vis[nextNode]) {
            vis[nextNode] = true;
            if (dfs(nextNode, startNode, num_node)) {
                return true;
            }
            vis[nextNode] = false;
        }
    }
    return false;
}

int main() {
    int total;
    int num_edge;
    int num_node;
    scanf("%d", &total);
    while (total--) {
        memset(EdgeCnt, 0, sizeof(EdgeCnt));
        memset(vis, false, sizeof(vis));
        scanf("%d %d", &num_node, &num_edge);
        for (int i = 0; i < num_edge; i++) {
            int from, to;
            scanf("%d %d", &from, &to);
            int idx1 = EdgeCnt[from]++;
            int idx2 = EdgeCnt[to]++;
            Edges[from][idx1] = to;
            Edges[to][idx2] = from;
        }
        puts(dfs(1, 1, num_node) ? "YES" : "NO");
    }
}