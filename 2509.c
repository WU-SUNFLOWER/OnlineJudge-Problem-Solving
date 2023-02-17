#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*队列模块开始*/

typedef struct node {
    int i;
    int j;
    int step;
    struct node* __next__;
} Node;

typedef struct {
    int size;
    Node* headNode;
    Node* tailNode;
} Queue;

Node* createNode(int i, int j, int step) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->i = i;
    p->j = j;
    p->step = step;
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

int Width;

int Height;

char Map[51][51];

int Visited[51][51];

int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int isLegalNode(Node* node) {
    int i = node->i;
    int j = node->j;
    return i >= 0 &&
           j >= 0 &&
           i < Height &&
           j < Width &&
           Map[i][j] != '#' &&
           Visited[i][j] != 1;
}

int bfs(int startI, int startJ) {
    //当前迷宫无解，则返回-1
    int ans = -1;
    //创建队列，并将初始位置入栈
    Queue* queue = createQueue();
    pushToQueue(queue, createNode(startI, startJ, 0));
    //立足于当前队列首元素对应的位置
    //开始尝试往四个方向走，即移除首元素，并往队列中添加新的节点
    while (queue->size > 0 && ans == -1) {
        Node* curNode = queue->headNode;
        for (int k = 0; k < 4; k++) {
            Node* nextNode = createNode(
                curNode->i + direction[k][0],
                curNode->j + direction[k][1],
                curNode->step + 1
            );
            //首先校验是否搜索到终点
            if (Map[nextNode->i][nextNode->j] == 'G') {
                ans = nextNode->step;
                free(nextNode);
                break;
            }
            //如果新节点可行，则将其添加进队列中，并标记当前位置已走过
            
            if (isLegalNode(nextNode)) {
                pushToQueue(queue, nextNode);
                Visited[nextNode->i][nextNode->j] = 1;
            } else {
                free(nextNode);
            }
        }
        popFromQueue(queue, 1);
    }
    destroyQueue(queue);
    return ans;
}

int main() {
    while (~scanf("%d %d", &Height, &Width)) {
        int startI;
        int startJ;
        //输入迷宫数据
        for (int i = 0; i < Height; i++) {
            scanf("%s", Map[i]);
            for (int j = 0; j < Width; j++) {
                if (Map[i][j] == 'W') {
                    startI = i;
                    startJ = j;
                    Visited[i][j] = 1;
                } else {
                    Visited[i][j] = 0;
                }
            }
        }
        //输出
        int ans = bfs(startI, startJ);
        ans >= 0 ? printf("%d", ans) : printf("Mission Failed");
        putchar('\n');
    }
}