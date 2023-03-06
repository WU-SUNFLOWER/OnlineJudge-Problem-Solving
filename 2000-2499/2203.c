#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define N 5

bool vis[N][N];
char map[N][N + 1];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool dfs(int pos_x, int pos_y, int end_x, int end_y) {
    if (
        map[pos_x][pos_y] == '*'
        || vis[pos_x][pos_y] 
        || pos_x < 0 
        || pos_x >= N 
        || pos_y < 0 
        || pos_y >= N
    ) {
        return false;
    }
    vis[pos_x][pos_y] = true;
    if (pos_x == end_x && pos_y == end_y) {
        return true;
    }
    for (int i = 0; i < 4; i++) {
        if (dfs(pos_x + dir[i][0], pos_y + dir[i][1], end_x, end_y)) {
            return true;
        }
    }
    vis[pos_x][pos_y] = false;
    return false;
}

int main() {
    int tot;
    scanf("%d", &tot);
    while (tot-- > 0) {
        int s1, s2, e1, e2;
        scanf("%d %d %d %d", &s1, &s2, &e1, &e2);
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < N; i++) {
            scanf("%s", map[i]);
        }
        puts(dfs(s1, s2, e1, e2) ? "YES" : "NO");
    }
}