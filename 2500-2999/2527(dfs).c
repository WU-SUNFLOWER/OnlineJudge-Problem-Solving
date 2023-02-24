#include <stdio.h>
#include <string.h>

typedef enum {false, true} bool;

//AdjNum[i]��ʾ���Ϊi�Ľڵ������е������ڽ�����
int AdjNum[100];  
//AdjList[i][j]��ʾ���Ϊi�Ľڵ������еĵ�j�������ڽ�ָ��ڵ�ı��
int AdjList[100][99];
//flags[i]��ʾ���Ϊi�Ľڵ��״̬
//0��ʾδ����������1��ʾ�������ڵ�ǰ��dfs�������ϣ�-1��ʾ�ѱ�����������δ���ֻ�·
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
    //�ܽڵ�����Ϊ�˷��㣬�ڵ㲻����0~nodeNum-1���б��
    int totalNode;  
    //�����ڽ�����
    int totalAdj;  
    while (~scanf("%d %d", &totalNode, &totalAdj)) {
        //��ȡ���������ڽ���Ϣ����������ͼ
        memset(AdjNum, 0, sizeof(AdjNum));
        memset(flags, 0, sizeof(flags));
        for (int i = 0; i < totalAdj; i++) {
            int start;
            int end;
            scanf("%d %d", &end, &start);
            AdjList[start][AdjNum[start]++] = end;
        }
        //��ͼ�е�ÿ���ڵ�Ϊ�������Ľڵ㣬����dfs����
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