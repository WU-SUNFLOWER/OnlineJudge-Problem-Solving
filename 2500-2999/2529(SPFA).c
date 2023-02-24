#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int pollFirstFromQueue(Queue* queue) {
    int ans = queue->headNode->id;
    popFromQueue(queue, 1);
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

const int Infinity = 1 << 30;

//AdjNum[i]表示编号为i的节点所持有的有向邻接总数
int AdjNum[1000];  

//AdjList[i][j]表示编号为i的节点所持有的第j个有向邻接指向节点的编号
int AdjList[1000][300];

//记录无向路径的权重
int AdjWeight[1000][300];

//标记当前图节点是否处于队列中
int InQueue[1000] = {0};

int min(int a, int b) {
    return a > b ? b : a;
}

/*
Warining: 
这种方法虽然提交能过，但是存在bug。
当有向图中存在不影响目标节点的负权环时，此种方法失效。
如以下反例：
4 4
1 2 3
2 3 1
3 2 -2
1 4 5

若要修复可以开辟新的空间用以记录路径，
并实时监测路径是否出现不含目标节点环路
可参考：https://dandelioncloud.cn/article/details/1528000157417488386

但即使这样进行强行修复，也会极大拉低程序的性能和代码简洁程度
因此仍应将标准的bellman-ford算法作为首选！
*/

int main() {
    int totalNode;
    int totalAdj;
    int dist[1001];  //记录某节点到编号为1的起点的最短距离
    while (~scanf("%d %d", &totalNode, &totalAdj)) {
        //构建有向图
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
        //初始化dist数组
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
            //对curNode指向的所有节点进行放松操作
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
        //输出答案
        destroyQueue(queue);
        printf(ans ? "YES\n" : "NO\n");
    }
}