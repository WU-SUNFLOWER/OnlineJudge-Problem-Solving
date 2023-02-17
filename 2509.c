#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*����ģ�鿪ʼ*/

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
    //��ǰ�Թ��޽⣬�򷵻�-1
    int ans = -1;
    //�������У�������ʼλ����ջ
    Queue* queue = createQueue();
    pushToQueue(queue, createNode(startI, startJ, 0));
    //�����ڵ�ǰ������Ԫ�ض�Ӧ��λ��
    //��ʼ�������ĸ������ߣ����Ƴ���Ԫ�أ���������������µĽڵ�
    while (queue->size > 0 && ans == -1) {
        Node* curNode = queue->headNode;
        for (int k = 0; k < 4; k++) {
            Node* nextNode = createNode(
                curNode->i + direction[k][0],
                curNode->j + direction[k][1],
                curNode->step + 1
            );
            //����У���Ƿ��������յ�
            if (Map[nextNode->i][nextNode->j] == 'G') {
                ans = nextNode->step;
                free(nextNode);
                break;
            }
            //����½ڵ���У�������ӽ������У�����ǵ�ǰλ�����߹�
            
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
        //�����Թ�����
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
        //���
        int ans = bfs(startI, startJ);
        ans >= 0 ? printf("%d", ans) : printf("Mission Failed");
        putchar('\n');
    }
}