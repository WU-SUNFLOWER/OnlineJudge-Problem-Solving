#include <stdio.h>
#include <string.h>
#define N 10000

const int Infinity = 1 << 30;

int min(int a, int b) {
    return a > b ? b : a;
}

int max(int a, int b) {
    return a < b ? b : a;
}

/*
 ��ʽǰ���ǽ�ͼ ��ʼ
 �ο����ϣ�https://zhuanlan.zhihu.com/p/343092172
*/

//��¼��ʼ��ÿ���ڵ���׸������id��
//Head[i]=-1��ʾid��Ϊi�Ľڵ����Ϊ0
int Heads[N];

//��¼�������Ϣ������
struct {
    //��¼��ǰ����߽�����ͬ��ʼ�ڵ���ڱ�id��
    //�����ǰ����ߺ���û���ڱߣ���next=-1
    int next;
    //��¼��ǰ����ߵ�ָ��ڵ�id��
    int to;
} Edges[N];


//ά������ʵʱ�������±ߵ�id��
int edgeId;

//���������
void addEdge(int u, int v) {
    if (u < 0 || v < 0) {
        return;
    }
    Edges[edgeId].next = Heads[u];
    Edges[edgeId].to = v;
    Heads[u] = edgeId++;
}

//ά������ʵʱ�������½ڵ��id��
int curId;

void __create__(int preId, char str[]) {
    //Ϊ���ڵ���´������ӽڵ���ӱ�
    addEdge(preId, curId);
    //�ݹ������һ�ִ���
    int tempPreId = curId;
    char ch = str[curId++];
    if (ch == '0') {
        return;
    } else if (ch == '1') {
        __create__(tempPreId, str);
    } else if (ch == '2') {
        __create__(tempPreId, str);
        __create__(tempPreId, str);
    }    
}

//���ݶ��������н�ͼ
void createGraph(char str[]) {
    edgeId = curId = 0;
    memset(Heads, -1, sizeof(Heads));
    __create__(-1, str);
}

/* ��ʽǰ���ǽ�ͼ ���� */

/* ����dp���� ��ʼ */

int dp_min[N][2];
int dp_max[N][2];

void dfs(int curId) {
    //��ʼ�������������ڵ��dp����
    dp_min[curId][1] = 1;
    dp_max[curId][1] = 1;
    //��1���������ǰ�ڵ�����ɫ���ӽڵ㶼������ɫ
    //������ǰ�ڵ���ӽڵ㣬�ݹ����dp����
    int cnt = 0;
    int sum1 = 0;
    int sum2 = 0;
    for (int i = Heads[curId]; i != -1; i = Edges[i].next) {
        int nextId = Edges[i].to;
        dfs(nextId);
        sum1 += dp_min[nextId][0];
        sum2 += dp_max[nextId][0];
        cnt++;
    }
    dp_min[curId][1] += sum1;
    dp_max[curId][1] += sum2;
    //��2���������ǰ�ڵ㲻����ɫ
    //  ��2-1����������ýڵ����1���ӽڵ㣬��ȡ���ӽڵ���/������ɫ����µ����Ž�
    //  ��2-2����������ýڵ㺬2���ӽڵ㣬�����б���1���ӽڵ�����ɫ���������ȡ���Ž⼴��
    int min_nonGreen = cnt == 2 ? Infinity : sum1;
    int max_nonGreen = cnt == 2 ? 0 : sum2;
    for (int i = Heads[curId]; i != -1; i = Edges[i].next) {
        int nextId = Edges[i].to;
        min_nonGreen = min(min_nonGreen, sum1 - dp_min[nextId][0] + dp_min[nextId][1]);
        max_nonGreen = max(max_nonGreen, sum2 - dp_max[nextId][0] + dp_max[nextId][1]);
    }
    dp_min[curId][0] = min_nonGreen;
    dp_max[curId][0] = max_nonGreen;
}

/* ����dp���� ���� */

int main() {
    char str[N];
    while (~scanf("%s", str)) {
        createGraph(str);
        dfs(0);
        printf("%d %d\n", max(dp_max[0][0], dp_max[0][1]), min(dp_min[0][0], dp_min[0][1]));
    }
}