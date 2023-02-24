#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*队列模块开始*/

typedef struct node {
    int id;  //用于保存节点编号
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

//往队列末端添加元素
Queue* pushToQueue(Queue* queue, Node* node) {
    //若为非空队列
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

//队首元素出队列
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

//销毁整个队列及其中的元素
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

/* 队列模块结束 */

typedef enum {false, true} bool;

//AdjNum[i]表示编号为i的节点所持有的有向邻接总数
int AdjNum[100];  
//AdjList[i][j]表示编号为i的节点所持有的第j个有向邻接指向节点的编号
int AdjList[100][99];
//InNum[i]表示通向编号为i节点的有向路径总数，即该节点的入度总数
int InNum[100];

int main() {
    //总节点数，为了方便，节点不妨从0~nodeNum-1进行编号
    int totalNode;  
    //有向邻接总数
    int totalAdj;  
    while (~scanf("%d %d", &totalNode, &totalAdj)) {
        //读取所有有向邻接信息，构建有向图
        memset(AdjNum, 0, sizeof(AdjNum));
        memset(InNum, 0, sizeof(InNum));
        for (int i = 0; i < totalAdj; i++) {
            int start;
            int end;
            scanf("%d %d", &end, &start);
            AdjList[start][AdjNum[start]++] = end;
            InNum[end]++;
        }
        //找出所有入度为0的节点，压入队列
        Queue* queue = createQueue();
        for (int i = 1; i <= totalNode; i++) {
            if (InNum[i] == 0) {
                pushToQueue(queue, createNode(i));
            }
        }
        //借助bfs思想实现的拓扑排序
        int cnt = 0;
        while (queue->size > 0) {
            Node* node = pollFirstFromQueue(queue);
            int id = node->id;
            cnt++;
            //遍历该节点联通的所有节点,并断开它们之间的有向路径
            for (int j = 0; j < AdjNum[id]; j++) {
                //当某一个节点成为入度为0的节点时
                //再将它压入队列，以便后续断开和它连接节点的有向路径
                if (--InNum[AdjList[id][j]] == 0) {
                    pushToQueue(queue, createNode(AdjList[id][j]));
                }
            }
            free(node);
        }
        destroyQueue(queue);
        //如果图中没有环路，
        //那么经历拓扑排序后所有的节点都会成为没有联通其他节点的孤立节点
        printf(cnt == totalNode ? "RIGHT\n" : "ERROR\n");
    }
}