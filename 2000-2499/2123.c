#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b) {
    return b < a ? a : b;
}

/* 栈模块 开始 */
typedef struct {
    void* arr;
    int size;
    int maxSize;
    int elemSize;
} Stack;

Stack* createStack(int maxSize, int elemSize) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = malloc(elemSize * maxSize);
    stack->size = 0;
    stack->maxSize = maxSize;
    stack->elemSize = elemSize;
    return stack;
}

void freeStack(Stack* stack) {
    free(stack->arr);
    free(stack);
}

Stack* pushToStack(Stack* stack, void* elemAddr) {
    if (stack->size < stack->maxSize) {
        int elemSize = stack->elemSize;
        void* targetAddr = stack->arr + stack->size * elemSize;
        memcpy(targetAddr, elemAddr, elemSize);
        stack->size++;
    }
    return stack;
}

Stack* popFromStack(Stack* stack, void* elemAddr) {
    if (stack->size > 0) {
        stack->size--;
        int elemSize = stack->elemSize;
        void* targetAddr = stack->arr + stack->size * elemSize;
        memcpy(elemAddr, targetAddr, elemSize);
    }
    return stack;
}

int isEmptyStack(Stack* stack) {
    return !(stack->size);
}

Stack* getPeekFromStack(Stack* stack, void* elemAddr) {
    if (stack->size > 0) {
        int elemSize = stack->elemSize;
        void* targetAddr = stack->arr + (stack->size - 1) * elemSize;
        memcpy(elemAddr, targetAddr, elemSize);
    }
    return stack;
}
/* 栈模块 结束 */

/*队列模块开始*/

typedef struct queueNode {
    void* val;
    struct queueNode* __next__;
} QueueNode;

typedef struct {
    int size;
    int elemSize;
    QueueNode* headNode;
    QueueNode* tailNode;
} Queue;

QueueNode* createQueueNode(int elemSize, void* elemAddr) {
    QueueNode* p = (QueueNode*)malloc(sizeof(QueueNode));
    p->val = malloc(elemSize);
    p->__next__ = NULL;
    memcpy(p->val, elemAddr, elemSize);
    return p;
}

Queue* createQueue(int elemSize) {
    Queue* p = (Queue*)malloc(sizeof(Queue));
    p->size = 0;
    p->elemSize = elemSize;
    p->headNode = NULL;
    p->tailNode = NULL;
    return p;
}

//往队列末端添加元素
Queue* pushToQueue(Queue* queue, void* elemAddr) {
    // 创建新节点
    QueueNode* node = createQueueNode(queue->elemSize, elemAddr);
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
Queue* popFromQueue(Queue* queue, void* targetAddr) {
    QueueNode* oldNode = queue->headNode;
    if (queue->size) {
        if (queue->size > 1) {
            queue->headNode = oldNode->__next__;
        } else {
            queue->headNode = NULL;
            queue->tailNode = NULL;
        }
        memcpy(targetAddr, oldNode->val, queue->elemSize);
        free(oldNode);
        queue->size -= 1;    
    }
    return queue;
}

int isEmptyQueue(Queue* queue) {
    return !(queue->size);
}

//销毁整个队列及其中的元素
void freeQueue(Queue* queue) {
    if (queue->size <= 0) {
        return;
    }
    QueueNode* nextNode;
    QueueNode* curNode = queue->headNode;
    while (curNode != NULL) {
        nextNode = curNode->__next__;
        free(curNode->val);
        free(curNode);
        curNode = nextNode;
    };
    free(queue);
}

/* 队列模块结束 */

typedef char ElementType;

typedef struct trnode {
    ElementType val;
    struct trnode* left;
    struct trnode* right;
} *TNode;

TNode createTNode(ElementType val) {
    TNode node = (TNode)malloc(sizeof(struct trnode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TNode parseTreeExp(char exp[]) {
    TNode root = NULL;
    // 维护curRoot表示正在创建子树的父节点
    TNode curRoot = NULL;
    // flag用于标记创建子树为父节点的左子树还是右子树
    // flag=0表示要创建左子树，flag=1表示要创建右子树
    int flag = 0;
    char ch;
    Stack* stack = createStack(100, sizeof(TNode));
    for (int i = 0; ch = exp[i]; i++) {
        // 碰到左括号，flag复位
        // 同时，取出栈顶节点作为即将创建子树的根节点
        if (ch == '(') {
            flag = 0;
            getPeekFromStack(stack, &curRoot);
        }
        // 碰到右括号，说明当前子树创建完毕，删除栈顶节点
        // 同时需要访问新的栈顶元素，将curRoot更新为当前完成创建子树的父节点
        else if (ch == ')') {
            popFromStack(stack, &curRoot);
            getPeekFromStack(stack, &curRoot);
        }
        // 碰到分割逗号，更新flag，准备创建右子树
        else if (ch == ',') {
            flag = 1;
        }
        else if ('A' <= ch && ch <= 'Z') {
            TNode newNode = createTNode(ch);
            // 如果是根节点，就直接创建
            if (root == NULL) {
                root = newNode;
                pushToStack(stack, &newNode);
                continue;
            }
            // 否则把新创建的节点挂到父节点上
            if (flag) {
                //printf("为%c添加右节点%c\n", curRoot->val, newNode->val);
                curRoot->right = newNode;
            } else {
                //printf("为%c添加左节点%c\n", curRoot->val, newNode->val);
                curRoot->left = newNode;
            }
            // 判断新添加的节点是不是<省略左括号形式>的叶节点
            // 如果不是该种形式的叶节点的话，需要将其入栈
            if (exp[i + 1] == '(') {
                pushToStack(stack, &newNode);
            }
        }
    }
    freeStack(stack);
    return root;
}

void freeTree(TNode tree) {
    if (tree == NULL) return;
    freeTree(tree->left);
    freeTree(tree->right);
    free(tree);
}

void layerTraverseTree(TNode root) {
    int layer = 0;
    int width = 1;
    // curCnt表示当前层的节点数，初始值为根节点共1个
    int curCnt = 1;
    // nextCnt用于在将每层节点的子节点入栈的时候，顺便统计下一层的节点数
    int nextCnt = 0;
    // curLeftCnt用于计数当前层还未出队列的节点数
    // 当curLeftCnt归零时，表示当前层的所有节点都已遍历完成
    int curLeftCnt = curCnt;
    Queue* queue = createQueue(sizeof(TNode));
    pushToQueue(queue, &root);
    while (!isEmptyQueue(queue)) {
        TNode curNode;
        popFromQueue(queue, &curNode);
        if (curNode->left) {
            pushToQueue(queue, &curNode->left);
            nextCnt++;
        }
        if (curNode->right) {
            pushToQueue(queue, &curNode->right);
            nextCnt++;
        }
        if (--curLeftCnt == 0) {
            curCnt = curLeftCnt = nextCnt;
            nextCnt = 0;
            layer++;
            width = max(width, curCnt);
        }
    }
    printf("%d %d\n", layer, width);
}

int main() {
    char exp[100];
    scanf("%s", exp);
    TNode tree = parseTreeExp(exp);
    layerTraverseTree(tree);
}