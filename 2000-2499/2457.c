#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 100

/* 队列模块开始 */
typedef int ElementType;

typedef struct qnode {
    ElementType value;
    struct qnode* next;
} *QNode;

typedef struct queue {
    int size;
    QNode head;
    QNode tail;
} *Queue;

Queue createQueue() {
    Queue q = (Queue)malloc(sizeof(struct queue));
    q->size = 0;
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void freeQueue(Queue q) {
    QNode nextNode;
    while (q->head) {
        nextNode = q->head->next;
        free(q->head);
        q->head = nextNode;
    }
    free(q);
}

ElementType popFromQueue(Queue q) {
    QNode oldHead = q->head;
    ElementType ele = oldHead->value;
    if (--q->size == 0) {
        q->tail = NULL;
    }
    q->head = oldHead->next;
    free(oldHead);
    return ele;
}

ElementType pushToQueue(Queue q, ElementType ele) {
    QNode newNode = (QNode)malloc(sizeof(struct qnode));
    newNode->next = NULL;
    newNode->value = ele;
    if (++q->size == 1) {
        q->head = newNode;
    } else {
        q->tail->next = newNode;
    }
    q->tail = newNode;
    return ele;
}
/* 队列模块结束 */

int nameToId[0x7f];

char idToName[N];

int Graph[N][N];

int main() {
    char buf[N];
    int num_node;
    int num_edge;
    scanf("%d", &num_node);
    // 建立节点编号和节点数据的映射关系
    for (int i = 0; i < num_node; i++) {
        char name;
        scanf("%s", buf);
        name = buf[0];
        nameToId[name] = i;
        idToName[i] = name;
    }
    // 邻接矩阵建图
    scanf("%d", &num_edge);
    for (int i = 0; i < num_edge; i++) {
        char from, to;
        int from_id, to_id;
        scanf("%s", buf);
        sscanf(buf, "%c,%c", &from, &to);
        from_id = nameToId[from];
        to_id = nameToId[to];
        Graph[from_id][to_id] = 1;
        Graph[to_id][from_id] = 1;
    }
    int vis[N] = {1, 0};  
    int idx_ans = 0;
    char ans[N];
    // 对图进行广搜,生成广搜生成树
    Queue queue = createQueue();
    pushToQueue(queue, 0);
    while (queue->size > 0) {
        int cur = popFromQueue(queue);
        for (int i = 0; i < num_node; i++) {
            if (!vis[i] && Graph[cur][i]) {
                vis[i] = 1;
                pushToQueue(queue, i);
                ans[idx_ans++] = idToName[cur];
                ans[idx_ans++] = idToName[i];                
            }
        }
    }
    bool flag = true;
    for (int i = 0; i < num_node; i++) {
        if (!vis[i]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        for (int i = 0; i < idx_ans; i += 2) {
            printf("%c,%c\n", ans[i], ans[i + 1]);
        }        
    } else {
        puts("ERROR");
    }
}