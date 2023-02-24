#include <stdio.h>
#include <string.h>

typedef enum {false, true} bool;

//AdjNum[i]表示编号为i的节点所持有的有向邻接总数
int AdjNum[1000];  

//AdjList[i][j]表示编号为i的节点所持有的第j个有向邻接指向节点的编号
int AdjList[1000][300];

//记录无向路径的输入顺序，0表示小数在前，1表示大数在前
int AdjOrder[1000][300];

//记录无向路径的价值
int AdjValue[1000][300];

//dfn[i]表示编号为i的节点的深度优先数
//若dfn[i]=-1，则表示节点i从未被访问过
int dfn[1000];

//minAncestor[i]表示节点i的最小可达祖先节点的dfn值
int minAncestor[1000];

int max(int a, int b) {
    return a < b ? b : a;
}

int min(int a, int b) {
    return a > b ? b : a;
}

void tarjan(int node, int fatherNode, int depth) {
    dfn[node] = minAncestor[node] = depth;
    //从当前节点出发，继续向其除了原父节点外的各个相邻节点搜索
    for (int i = 0; i < AdjNum[node]; i++) {
        int nextNode = AdjList[node][i];
        //第一种情况：该节点未被访问过，即该节点为当前节点的子节点
        if (dfn[nextNode] == -1) {
            tarjan(nextNode, node, depth + 1);
            minAncestor[node] = min(minAncestor[node], minAncestor[nextNode]);
        }
        //第二种情况：该节点已被访问过，且该节点非当前节点的父节点
        //即该节点为当前节点的祖先节点
        else if (nextNode != fatherNode) {
            //这里不能写作minAncestor[node] = dfn[nextNode];
            //因为经过前面的搜索minAncestor[node]可能已经被更新，不再等于depth，所以必须加上min取两者最小值
            minAncestor[node] = min(minAncestor[node], dfn[nextNode]);
        }
    }
}

int main() {
    int totalNode;
    int totalAdj;
    while (~scanf("%d %d", &totalNode, &totalAdj)) {
        //读取无向路径的信息,建立无向图
        memset(AdjNum, 0, sizeof(AdjNum));
        memset(dfn, -1, sizeof(dfn));
        for (int i = 0; i < totalAdj; i++) {
            int a, b, value;
            scanf("%d %d %d", &a, &b, &value);
            a--;
            b--;
            //记录输入顺序
            AdjOrder[a][AdjNum[a]] = a > b;
            AdjOrder[b][AdjNum[b]] = a > b;
            //记录无向路径价值
            AdjValue[a][AdjNum[a]] = value;
            AdjValue[b][AdjNum[b]] = value;
            //记录无向路径连接关系
            AdjList[a][AdjNum[a]++] = b;
            AdjList[b][AdjNum[b]++] = a;
            
        }
        //以第一个节点为起点走一遍无向图
        tarjan(0, -1, 0);
        //遍历所有节点，寻找桥
        bool isAllConnected = true;
        for (int i = 0; i < totalNode; i++) {
            if (dfn[i] == -1) {
                isAllConnected = false;
                break;
            }
        }
        if (isAllConnected) {
            int ansA, ansB, ansValue = 0;
            for (int i = 0; i < totalNode; i++) {
                for (int j = 0; j < AdjNum[i]; j++) {
                    int nextNode = AdjList[i][j];
                    int value = AdjValue[i][j];
                    int order = AdjOrder[i][j];
                    if (
                        dfn[i] == minAncestor[nextNode] - 1 &&
                        ansValue < value
                    ) {
                        ansA = order ? max(i, nextNode) : min(i, nextNode);
                        ansB = order ? min(i, nextNode) : max(i, nextNode);
                        ansValue = value;
                    }
                }
            }
            ansValue ? 
                printf("%d %d\n", ansA + 1, ansB + 1) :
                printf("-1\n");
        } else {
            printf("-1\n");
        }
    }
}