#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

Node* pollFirstFromQueue(Queue* queue) {
    Node* ans = queue->headNode;
    popFromQueue(queue, 0);
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

typedef enum {false, true} bool;

//AdjNum[i]��ʾ���Ϊi�Ľڵ������е������ڽ�����
int AdjNum[100];  
//AdjList[i][j]��ʾ���Ϊi�Ľڵ������еĵ�j�������ڽ�ָ��ڵ�ı��
int AdjList[100][99];
//InNum[i]��ʾͨ����Ϊi�ڵ������·�����������ýڵ���������
int InNum[100];

int main() {
    //�ܽڵ�����Ϊ�˷��㣬�ڵ㲻����0~nodeNum-1���б��
    int totalNode;  
    //�����ڽ�����
    int totalAdj;  
    while (~scanf("%d %d", &totalNode, &totalAdj)) {
        //��ȡ���������ڽ���Ϣ����������ͼ
        memset(AdjNum, 0, sizeof(AdjNum));
        memset(InNum, 0, sizeof(InNum));
        for (int i = 0; i < totalAdj; i++) {
            int start;
            int end;
            scanf("%d %d", &end, &start);
            AdjList[start][AdjNum[start]++] = end;
            InNum[end]++;
        }
        //�ҳ��������Ϊ0�Ľڵ㣬ѹ�����
        Queue* queue = createQueue();
        for (int i = 1; i <= totalNode; i++) {
            if (InNum[i] == 0) {
                pushToQueue(queue, createNode(i));
            }
        }
        //����bfs˼��ʵ�ֵ���������
        int cnt = 0;
        while (queue->size > 0) {
            Node* node = pollFirstFromQueue(queue);
            int id = node->id;
            cnt++;
            //�����ýڵ���ͨ�����нڵ�,���Ͽ�����֮�������·��
            for (int j = 0; j < AdjNum[id]; j++) {
                //��ĳһ���ڵ��Ϊ���Ϊ0�Ľڵ�ʱ
                //�ٽ���ѹ����У��Ա�����Ͽ��������ӽڵ������·��
                if (--InNum[AdjList[id][j]] == 0) {
                    pushToQueue(queue, createNode(AdjList[id][j]));
                }
            }
            free(node);
        }
        destroyQueue(queue);
        //���ͼ��û�л�·��
        //��ô����������������еĽڵ㶼���Ϊû����ͨ�����ڵ�Ĺ����ڵ�
        printf(cnt == totalNode ? "RIGHT\n" : "ERROR\n");
    }
}