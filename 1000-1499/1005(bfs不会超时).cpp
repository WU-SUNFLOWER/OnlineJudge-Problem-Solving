#include <cstdio>
#include <queue>
#include <utility>

char map[25][25];
bool vis[25][25];

int directions[][2] = {
    {-1, 0},  // 上
    {1, 0},  // 下
    {0, -1},  // 左
    {0, 1},  // 右
};

template<typename T>
bool inRange(T begin, T end, T elem) {
    return begin <= elem && elem <= end;
}

struct Pos {
    int i, j, rest;
};

int main() {
    int width;
    int height;
    int restTime;

    int start_i = -1, start_j = -1;

    while (~scanf("%d %d %d", &width, &height, &restTime)) {

        if (width == 0 || height == 0 || restTime == 0) break;

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                do {
                    map[i][j] = getchar();
                } while (map[i][j] == '\n');
                if (map[i][j] == 'S') {
                    start_i = i, start_j = j;
                    vis[i][j] = true;
                } else {
                    vis[i][j] = false;
                }
                
            }
        }

        bool successful = false;
        std::queue<Pos> queue;
        queue.push({start_i, start_j, restTime});
        while (!queue.empty()) {
            Pos currentPos = queue.front();
            queue.pop();

            int cur_i = currentPos.i;
            int cur_j = currentPos.j;
            int cur_rest = currentPos.rest;
            if (map[cur_i][cur_j] == 'P') {
                successful = true;
                break;
            }
            if (cur_rest <= 0) {
                continue;
            }

            for (int dir = 0; dir < 4; ++dir) {
                int next_i = currentPos.i + directions[dir][0];
                int next_j = currentPos.j + directions[dir][1];
             
                if (
                    !inRange(0, height - 1, next_i) ||
                    !inRange(0, width - 1, next_j) ||
                    vis[next_i][next_j] ||
                    map[next_i][next_j] == '*'
                ) {
                    continue;
                }

                vis[next_i][next_j] = true;
                queue.push({next_i, next_j, cur_rest - 1});
            }
        }
        puts(successful ? "YES" : "NO");
    }
    return 0;
}
