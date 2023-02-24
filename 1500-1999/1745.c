#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* pre;
    struct node* next;
} *Node;

Node createNode(int val, Node pre) {
    Node node = (Node)malloc(sizeof(struct node));
    node->val = val;
    node->pre = pre;
    node->next = NULL;
    return node;
}

int main() {
    // ����
    int temp = 0;
    Node headNode = NULL;
    Node lastNode = NULL;
    while (~scanf("%d", &temp)) {
        Node node = createNode(temp, lastNode);
        lastNode && (lastNode->next = node);
        lastNode = node;
        !headNode && (headNode = node);     
    }
    // ������β�ڵ��ָ��
    headNode->pre = lastNode;
    lastNode->next = headNode;
    // ���
    Node curNode = headNode;
    do {
        printf("%d ", curNode->val);
        curNode = curNode->next;
    } while (curNode != headNode);
}