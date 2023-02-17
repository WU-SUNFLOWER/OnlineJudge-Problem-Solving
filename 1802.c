#include <stdio.h>
#define N 25

//����ֱ�Ӳ����ڽӾ����¼ͼ����ͨ��ϵ
int Graph[N][N];
//��¼ͼ�е�ÿ���ڵ��Ƿ��ѱ����ʹ�
int Visited[N];
//��¼ͼ��ÿ���ڵ��Ȩֵ
int Values[N];

int max(int a, int b) {
    return a > b ? a : b;
}

int dfs(int nodeIdx, int nodeNum, int* ans) {
    int sum = Values[nodeIdx];
    Visited[nodeIdx] = 1;
    for (int i = 1; i <= nodeNum; i++) {
        if (Graph[nodeIdx][i] && !Visited[i]) {
            //̰�ģ������ͼ�����Ȩ�غ�Ϊ����������µ�ǰ�ڵ�����Ȩ�غ�
            sum = max(sum, sum + dfs(i, nodeNum, ans));
        }
    }
    *ans = max(*ans, sum);
    return sum;
}

int main() {
    int nodeNum;
    scanf("%d", &nodeNum);
    //��ȡ�ڵ�Ȩֵ
    for (int i = 1; i <= nodeNum; i++) {
        scanf("%d", &Values[i]);
    }
    //��ȡͼ����ʼ���ڽӾ���
    for (int i = 0; i < nodeNum - 1; i++) {
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        Graph[n1][n2] = 1;
        Graph[n2][n1] = 1;
    }
    //��ȡһ���ڵ���Ϊdfs����㣬����Ϊ�˷���ֱ��ȡ���Ϊ1�Ľڵ�
    int ans = 0;
    dfs(1, nodeNum, &ans);
    printf("%d\n", ans);
}