#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int id;
    int score;
    struct node* next;
} *Node;

Node createNode(int id, int score) {
    Node p = (Node)malloc(sizeof(struct node));
    p->id = id;
    p->score = score;
    p->next = NULL;
    return p;
}

void sort(Node headNode) {
    Node firstNode = headNode->next;
    Node tailNode = NULL;
    Node preNode = headNode;
    Node curNode;
    Node nextNode;
    //空链表或只有一个节点的链表不需要排序
    if (!firstNode || !firstNode->next) {
        return;
    }
    //确定链表尾部节点
    //排序开始
    while (firstNode != tailNode) {
        curNode = firstNode;
        while (curNode->next != tailNode) {
            nextNode = curNode->next;
            if (curNode->id > nextNode->id) {
                preNode->next = nextNode;
                curNode->next = nextNode->next;
                nextNode->next = curNode;
                curNode = nextNode;
            }
            preNode = preNode->next;
            curNode = curNode->next;
        }
        //每轮循环结束后对相关指针进行归位
        tailNode = curNode;
        preNode = headNode;
        firstNode = headNode->next;
    }
}

int main() {
    int id;
    int score;
    Node headNode = createNode(-1, -1);
    Node lastNode = headNode;
    Node curNode;
    scanf("%d %d", &id, &score);
    //构建链表
    while (~scanf("%d %d", &id, &score)) {
        curNode = createNode(id, score);
        lastNode->next = curNode;
        lastNode = curNode;
    }
    //链表排序
    sort(headNode);
    //输出
    curNode = headNode->next;
    while (curNode) {
        printf("%d %d\n", curNode->id, curNode->score);
        curNode = curNode->next;
    }
}