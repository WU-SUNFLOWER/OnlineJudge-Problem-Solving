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
    // 建表
    int temp = 0;
    Node headNode = createNode(-1, NULL);
    Node lastNode = headNode;
    while (~scanf("%d", &temp)) {
        Node node = createNode(temp, lastNode);
        lastNode->next = node;
        lastNode = node;
    }
    // 就地逆置
    Node tailNode = lastNode;
    Node curNode = tailNode->pre;
    while (curNode != headNode) {
        Node nextNode = curNode->pre;
        // 更新前驱节点
        lastNode->next = curNode;
        curNode->pre = lastNode;
        // 初始化后驱节点
        curNode->next = NULL;
        // 更新lastNode
        lastNode = curNode;
        // 更新curNode
        curNode = nextNode;
    }
    // 重新设置头节点
    tailNode->pre = headNode;
    headNode->next = tailNode;
    // 输出
    curNode = headNode->next;
    while (curNode) {
        printf("%d ", curNode->val);
        curNode = curNode->next;
    }
}