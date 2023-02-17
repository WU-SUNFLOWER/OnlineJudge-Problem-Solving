#include <stdio.h>
#include <string.h>

typedef enum {false, true} bool;

//AdjNum[i]��ʾ���Ϊi�Ľڵ������е������ڽ�����
int AdjNum[1000];  

//AdjList[i][j]��ʾ���Ϊi�Ľڵ������еĵ�j�������ڽ�ָ��ڵ�ı��
int AdjList[1000][300];

//��¼����·��������˳��0��ʾС����ǰ��1��ʾ������ǰ
int AdjOrder[1000][300];

//��¼����·���ļ�ֵ
int AdjValue[1000][300];

//dfn[i]��ʾ���Ϊi�Ľڵ�����������
//��dfn[i]=-1�����ʾ�ڵ�i��δ�����ʹ�
int dfn[1000];

//minAncestor[i]��ʾ�ڵ�i����С�ɴ����Ƚڵ��dfnֵ
int minAncestor[1000];

int max(int a, int b) {
    return a < b ? b : a;
}

int min(int a, int b) {
    return a > b ? b : a;
}

void tarjan(int node, int fatherNode, int depth) {
    dfn[node] = minAncestor[node] = depth;
    //�ӵ�ǰ�ڵ�����������������ԭ���ڵ���ĸ������ڽڵ�����
    for (int i = 0; i < AdjNum[node]; i++) {
        int nextNode = AdjList[node][i];
        //��һ��������ýڵ�δ�����ʹ������ýڵ�Ϊ��ǰ�ڵ���ӽڵ�
        if (dfn[nextNode] == -1) {
            tarjan(nextNode, node, depth + 1);
            minAncestor[node] = min(minAncestor[node], minAncestor[nextNode]);
        }
        //�ڶ���������ýڵ��ѱ����ʹ����Ҹýڵ�ǵ�ǰ�ڵ�ĸ��ڵ�
        //���ýڵ�Ϊ��ǰ�ڵ�����Ƚڵ�
        else if (nextNode != fatherNode) {
            //���ﲻ��д��minAncestor[node] = dfn[nextNode];
            //��Ϊ����ǰ�������minAncestor[node]�����Ѿ������£����ٵ���depth�����Ա������minȡ������Сֵ
            minAncestor[node] = min(minAncestor[node], dfn[nextNode]);
        }
    }
}

int main() {
    int totalNode;
    int totalAdj;
    while (~scanf("%d %d", &totalNode, &totalAdj)) {
        //��ȡ����·������Ϣ,��������ͼ
        memset(AdjNum, 0, sizeof(AdjNum));
        memset(dfn, -1, sizeof(dfn));
        for (int i = 0; i < totalAdj; i++) {
            int a, b, value;
            scanf("%d %d %d", &a, &b, &value);
            a--;
            b--;
            //��¼����˳��
            AdjOrder[a][AdjNum[a]] = a > b;
            AdjOrder[b][AdjNum[b]] = a > b;
            //��¼����·����ֵ
            AdjValue[a][AdjNum[a]] = value;
            AdjValue[b][AdjNum[b]] = value;
            //��¼����·�����ӹ�ϵ
            AdjList[a][AdjNum[a]++] = b;
            AdjList[b][AdjNum[b]++] = a;
            
        }
        //�Ե�һ���ڵ�Ϊ�����һ������ͼ
        tarjan(0, -1, 0);
        //�������нڵ㣬Ѱ����
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