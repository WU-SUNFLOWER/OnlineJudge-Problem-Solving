#include <stdio.h>
#include <stdlib.h>

/* ��������ʼ */
typedef struct trnode {
    char value;
    struct trnode* left;
    struct trnode* right;
} *TNode, *Tree, *ElementType;

typedef struct qnode {
    ElementType value;
    struct qnode* next;
} *QNode;

typedef struct queue {
    int size;
    QNode head;
    QNode tail;
} *Queue;
/* ���������� */

/* ����ģ�鿪ʼ */
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
    if (q->size <= 0) {
        return NULL;
    }
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
/* ����ģ����� */

/*������ģ�鿪ʼ*/
Tree BuildTree(char str[], int* offset) {
    char value = str[*offset];
    (*offset)++;
    if (value == '#') {
        return NULL;
    } else {
        TNode node = (TNode)malloc(sizeof(struct trnode));
        node->value = value;
        node->left = BuildTree(str, offset);
        node->right = BuildTree(str, offset);
        return node;
    }
}

void FreeTree(TNode node) {
    if (node == NULL) {
        return;
    }
    FreeTree(node->left);
    FreeTree(node->right);
    free(node);
}

//�������������
void InOrderTraverse(TNode node) {
    if (node == NULL) {
        return;
    }
    InOrderTraverse(node->left);
    printf("%c", node->value);
    InOrderTraverse(node->right);
}

//��������������
void PostOrderTraverse(TNode node) {
    if (node == NULL) {
        return;
    }
    PostOrderTraverse(node->left);
    PostOrderTraverse(node->right);
    printf("%c", node->value);
}

//�������������
void LevelOrderTraverse(Tree tree) {
    Queue q = createQueue();
    pushToQueue(q, tree);
    while (q->size) {
        TNode curNode = popFromQueue(q);
        if (curNode != NULL) {
            printf("%c", curNode->value);
            pushToQueue(q, curNode->left);
            pushToQueue(q, curNode->right);
        }
    }
    freeQueue(q);
}
/* ������ģ����� */

int main() {
    char str[2001];
    while (~scanf("%s", str)) {
        int offset = 0;
        Tree tree = BuildTree(str, &offset);
        InOrderTraverse(tree);
        printf(" ");
        PostOrderTraverse(tree);
        printf(" ");
        LevelOrderTraverse(tree);
        printf("\n");
        FreeTree(tree);
    }
}