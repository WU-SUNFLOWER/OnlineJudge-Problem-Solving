#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
    struct node* pre;
} *Node;

Node createNode(int val, Node preNode) {
    Node node = (Node)malloc(sizeof(struct node));
    node->val = val;
    node->next = NULL;
    node->pre = preNode;
    return node;
}

int main() {
    // ����
    int temp = 0;
    Node headNode = createNode(-1, NULL);
    Node lastNode = headNode;
    while (~scanf("%d", &temp)) {
        Node node = createNode(temp, lastNode);
        lastNode->next = node;
        lastNode = node;
    }
    // �͵�����
    Node tailNode = lastNode;
    Node curNode = tailNode->pre;
    while (curNode != headNode) {
        Node nextNode = curNode->pre;
        // ����ǰ���ڵ�
        lastNode->next = curNode;
        curNode->pre = lastNode;
        // ��ʼ�������ڵ�
        curNode->next = NULL;
        // ����lastNode
        lastNode = curNode;
        // ����curNode
        curNode = nextNode;
    }
    // ��������ͷ�ڵ�
    tailNode->pre = headNode;
    headNode->next = tailNode;
    // ���
    curNode = headNode->next;
    while (curNode) {
        printf("%d ", curNode->val);
        curNode = curNode->next;
    }
}