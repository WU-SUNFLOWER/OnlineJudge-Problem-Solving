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

// 检测节点是否是叶子节点
// 检测方法：和叶子节点连通的节点一定都被访问过了
bool isLeafNode(int node, int parent[], int num_node) {
    for (int i = 0; i < num_node; i++) {
        if (Graph[node][i] && parent[i] == -1) {
            return false;
        }
    }
    return true;
}

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
    int parent[N];  
    int idx_ans = 0;
    char ans[N];
    int flag = true;
    // 将parent数组元素的初始值设为-1
    // 该数组既可用于父节点记录，也可以作为节点有没有被收入生成树的判断依据
    memset(parent, 0xff, sizeof(parent));  
    // 对图进行广搜,生成广搜生成树
    Queue queue = createQueue();
    pushToQueue(queue, 0);
    while (queue->size > 0) {
        int cur = popFromQueue(queue);
        for (int i = 0; i < num_node; i++) {
            // 如果遍历到非邻接节点，或cur节点的父节点，则直接跳过
            if (!Graph[cur][i] || parent[cur] == i) continue;
            // 1.碰到一个已经被访问过的邻接节点，则检查是否是叶节点
            // 1.1 如果不是叶节点的话，则说明当前图不存在广搜生成树，退出循环并输出结果
            // 1.2 如果是叶节点的话，则当作没看见，继续执行循环
            // 2. 碰到一个还没被访问过的节点，则正常将其收入队列中，并标记为已访问过
            if (parent[i] == -1) {
                parent[i] = cur;
                pushToQueue(queue, i);
                ans[idx_ans++] = idToName[cur];
                ans[idx_ans++] = idToName[i];                
            }
            else if (!isLeafNode(i, parent, num_node)) {
                flag = false;
                break;
            }
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