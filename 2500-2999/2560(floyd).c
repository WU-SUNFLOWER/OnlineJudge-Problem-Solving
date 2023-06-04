#include <stdio.h>
#include <string.h>
#define N 205
#define Infinity 1 << 10

int Graph[N][N];

int dist[N][N]; 

int path[N][N];

int main() {
    int num_node;
    int num_edge;
    
    while (~scanf("%d %d", &num_node, &num_edge)) {
        memset(Graph, 0, sizeof(Graph));
        for (int i = 0; i < num_edge; i++) {
            int from, to, len;
            scanf("%d %d %d", &from, &to, &len);
            Graph[from][to] = Graph[to][from] = len;
        }
        int start, end;
        scanf("%d %d", &start, &end);
        for (int i = 1; i <= num_node; i++) {
            for (int j = 1; j <= num_node; j++) {
                if (Graph[i][j] != 0) {
                    dist[i][j] = Graph[i][j];
                    path[i][j] = i;
                } else {
                    dist[i][j] = Infinity;
                    path[i][j] = -1;
                }
            }
        }
        for (int k = 1; k <= num_node; k++) {
            for (int i = 1; i <= num_node; i++) {
                for (int j = 1; j <= num_node; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        int cur = end;
        while (path[start][cur] != -1) {
            cur = path[start][cur];
        }
        printf("%d\n", cur == start ? dist[start][end] : -1);
    }
}