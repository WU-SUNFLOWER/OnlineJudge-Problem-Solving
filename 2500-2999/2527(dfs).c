#include <stdio.h>
#include <string.h>

typedef enum {false, true} bool;

//AdjNum[i]表示编号为i的节点所持有的有向邻接总数
int AdjNum[100];  
//AdjList[i][j]表示编号为i的节点所持有的第j个有向邻接指向节点的编号
int AdjList[100][99];
//flags[i]表示编号为i的节点的状态
//0表示未被搜索过；1表示正挂载在当前的dfs搜索树上；-1表示已被搜索过，但未发现回路
int flags[100];

bool dfs(int id) {
    if (flags[id] == 1) {
        return true;
    }
    if (flags[id] == -1) {
        return false;
    }
    flags[id] = 1;
    for (int i = 0; i < AdjNum[id]; i++) {
        if (dfs(AdjList[id][i])) {
            return true;
        }
    }
    flags[id] = -1;
    return false;
}

int main() {
    //总节点数，为了方便，节点不妨从0~nodeNum-1进行编号
    int totalNode;  
    //有向邻接总数
    int totalAdj;  
    while (~scanf("%d %d", &totalNode, &totalAdj)) {
        //读取所有有向邻接信息，构建有向图
        memset(AdjNum, 0, sizeof(AdjNum));
        memset(flags, 0, sizeof(flags));
        for (int i = 0; i < totalAdj; i++) {
            int start;
            int end;
            scanf("%d %d", &end, &start);
            AdjList[start][AdjNum[start]++] = end;
        }
        //以图中的每个节点为搜索树的节点，进行dfs搜索
        int ans = 0;
        for (int i = 0; i < totalNode; i++) {
            if (dfs(i)) {
                ans = 1;
                break;
            }
        }
        printf(ans ? "ERROR\n" : "RIGHT\n");
    }
}