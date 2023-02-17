#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*����ģ�鿪ʼ*/

typedef struct node {
    int id;  //���ڱ���ڵ���
    struct node* __next__;
} Node;

typedef struct {
    int size;
    Node* headNode;
    Node* tailNode;
} Queue;

Node* createNode(int id) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;
    p->__next__ = NULL;
    return p;
}

Queue* createQueue() {
    Queue* p = (Queue*)malloc(sizeof(Queue));
    p->size = 0;
    p->headNode = NULL;
    p->tailNode = NULL;
    return p;
}

//������ĩ�����Ԫ��
Queue* pushToQueue(Queue* queue, Node* node) {
    //��Ϊ�ǿն���
    if (queue->size > 0) {
        queue->tailNode->__next__ = node;  
    } else {
        queue->headNode = node;
    }
    queue->tailNode = node;
    node->__next__ = NULL;
    queue->size += 1;
    return queue;
}

//����Ԫ�س�����
Queue* popFromQueue(Queue* queue, int deep) {
    Node* oldNode = queue->headNode;
    if (queue->size > 1) {
        queue->headNode = oldNode->__next__;
    } else {
        queue->headNode = NULL;
        queue->tailNode = NULL;
    }
    if (deep) {
        free(oldNode);
    }
    queue->size -= 1;
    return queue;
}

int pollFirstFromQueue(Queue* queue) {
    int ans = queue->headNode->id;
    popFromQueue(queue, 1);
    return ans;
}

//�����������м����е�Ԫ��
void destroyQueue(Queue* queue) {
    if (queue->size <= 0) {
        return;
    }
    Node* nextNode;
    Node* curNode = queue->headNode;
    while (curNode != NULL) {
        nextNode = curNode->__next__;
        free(curNode);
        curNode = nextNode;
    };
    free(queue);
}

/* ����ģ����� */

const int Infinity = 1 << 30;

//AdjNum[i]��ʾ���Ϊi�Ľڵ������е������ڽ�����
int AdjNum[1000];  

//AdjList[i][j]��ʾ���Ϊi�Ľڵ������еĵ�j�������ڽ�ָ��ڵ�ı��
int AdjList[1000][300];

//��¼����·����Ȩ��
int AdjWeight[1000][300];

//��ǵ�ǰͼ�ڵ��Ƿ��ڶ�����
int InQueue[1000] = {0};

int min(int a, int b) {
    return a > b ? b : a;
}

/*
Warining: 
���ַ�����Ȼ�ύ�ܹ������Ǵ���bug��
������ͼ�д��ڲ�Ӱ��Ŀ��ڵ�ĸ�Ȩ��ʱ�����ַ���ʧЧ��
�����·�����
4 4
1 2 3
2 3 1
3 2 -2
1 4 5

��Ҫ�޸����Կ����µĿռ����Լ�¼·����
��ʵʱ���·���Ƿ���ֲ���Ŀ��ڵ㻷·
�ɲο���https://dandelioncloud.cn/article/details/1528000157417488386

����ʹ��������ǿ���޸���Ҳ�Ἣ�����ͳ�������ܺʹ�����̶�
�����Ӧ����׼��bellman-ford�㷨��Ϊ��ѡ��
*/

int main() {
    int totalNode;
    int totalAdj;
    int dist[1001];  //��¼ĳ�ڵ㵽���Ϊ1��������̾���
    while (~scanf("%d %d", &totalNode, &totalAdj)) {
        //��������ͼ
        int start;
        int end;
        int weight;
        int hasAns = 0;
        memset(AdjNum, 0, sizeof(AdjNum));
        memset(InQueue, 0, sizeof(AdjNum));
        for (int i = 0; i < totalAdj; i++) {
            scanf("%d %d %d", &start, &end, &weight);
            end == totalNode && (hasAns = 1);
            start--;
            end--;
            AdjWeight[start][AdjNum[start]] = weight;
            AdjList[start][AdjNum[start]++] = end;
        }
        if (!hasAns) {
            printf("NO\n");
            continue;
        }
        //��ʼ��dist����
        dist[0] = 0;
        for (int i = 1; i < totalNode; i++) {
            dist[i] = Infinity;
        }
        
        int ans = 0;
        int temp = Infinity;
        Queue* queue = createQueue();
        pushToQueue(queue, createNode(0));
        InQueue[0] = 1;
        while (queue->size) {
            int startNode = pollFirstFromQueue(queue);
            InQueue[startNode] = 0;
            //��curNodeָ������нڵ���з��ɲ���
            for (int i = 0; i < AdjNum[startNode]; i++) {
                int nextNode = AdjList[startNode][i];
                int weight = AdjWeight[startNode][i];
                int newDist = dist[startNode] + weight;
                if (newDist < dist[nextNode]) {
                    dist[nextNode] = dist[startNode] + weight;
                    if (!InQueue[nextNode]) {
                        InQueue[nextNode] = 1;
                        pushToQueue(queue, createNode(nextNode));
                    }
                }
            }
            if (dist[totalNode - 1] < 0) {
                ans = 1;
                break;
            }
        }
        //�����
        destroyQueue(queue);
        printf(ans ? "YES\n" : "NO\n");
    }
}