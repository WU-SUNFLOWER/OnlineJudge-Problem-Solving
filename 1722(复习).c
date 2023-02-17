#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
} *Node;

Node createNode(int value) {
    Node p = (Node)malloc(sizeof(struct node));
    p->value = value;
    p->next = NULL;
    return p;
}

void reverse(Node headNode) {
    Node lastNode = NULL;  //新生成的逆序链表
    Node curNode = headNode->next;
    Node nextNode;
    while (curNode) {
        nextNode = curNode->next;
        //将原链表的当前节点插到临时链表中
        curNode->next = lastNode;
        lastNode = curNode;
        curNode = nextNode;
    }
    headNode->next = lastNode;
}

int main() {
    int size1;
    int size2;
    Node headNode = createNode(-1);
    Node curNode = headNode;
    //接收第一个链表
    scanf("%d", &size1);
    while (size1--) {
        curNode->next = createNode(-1);
        curNode = curNode->next;
        scanf("%d", &curNode->value);
    }
    //接收第二个链表
    Node preNode = headNode;
    curNode = headNode->next;
    scanf("%d", &size2);
    while (size2--) {
        Node newNode = createNode(-1);
        scanf("%d", &newNode->value);
        while (curNode && curNode->value < newNode->value) {
            curNode = curNode->next;
            preNode = preNode->next;
        }
        preNode->next = newNode;
        newNode->next = curNode;
        curNode = newNode;
    }
    //输出
    reverse(headNode);
    curNode = headNode->next;
    while (curNode) {
        printf("%d ", curNode->value);
        curNode = curNode->next;
    }
}