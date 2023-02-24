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
    // 建表
    int temp = 0;
    Node headNode = NULL;
    Node lastNode = NULL;
    while (~scanf("%d", &temp)) {
        Node node = createNode(temp, lastNode);
        lastNode && (lastNode->next = node);
        lastNode = node;
        !headNode && (headNode = node);     
    }
    // 设置首尾节点的指针
    headNode->pre = lastNode;
    lastNode->next = headNode;
    // 输出
    Node curNode = headNode;
    do {
        printf("%d ", curNode->val);
        curNode = curNode->next;
    } while (curNode != headNode);
}