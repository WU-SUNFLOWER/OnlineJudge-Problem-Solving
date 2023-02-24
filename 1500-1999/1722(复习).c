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
    Node lastNode = NULL;  //�����ɵ���������
    Node curNode = headNode->next;
    Node nextNode;
    while (curNode) {
        nextNode = curNode->next;
        //��ԭ����ĵ�ǰ�ڵ�嵽��ʱ������
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
    //���յ�һ������
    scanf("%d", &size1);
    while (size1--) {
        curNode->next = createNode(-1);
        curNode = curNode->next;
        scanf("%d", &curNode->value);
    }
    //���յڶ�������
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
    //���
    reverse(headNode);
    curNode = headNode->next;
    while (curNode) {
        printf("%d ", curNode->value);
        curNode = curNode->next;
    }
}