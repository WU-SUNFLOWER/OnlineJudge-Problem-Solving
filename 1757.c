#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
} *Node;

Node createNode(int val) {
    Node node = (Node)malloc(sizeof(struct node));
    node->val = val;
    node->next = NULL;
    return node;
}

int main() {
    int size;
    Node headNode = createNode(-1);
    Node headNode_odd = createNode(-1);
    Node headNode_even = createNode(-1);
    // 读取链表
    scanf("%d", &size);
    Node lastNode = headNode;
    for (int i = 0; i < size; i++) {
        Node curNode = createNode(-1);
        scanf("%d", &curNode->val);
        lastNode->next = curNode;
        lastNode = curNode;
    }
    // 拆分链表
    Node nextNode;
    Node lastNode_odd = headNode_odd;
    Node lastNode_even = headNode_even;
    Node curNode = headNode->next;
    for (int i = 1; i <= size; i++) {
        if (i % 2) {
            lastNode_odd->next = curNode;
            lastNode_odd = curNode;
        } else {
            lastNode_even->next = curNode;
            lastNode_even = curNode;
        }
        nextNode = curNode->next;
        curNode->next = NULL;
        curNode = nextNode;
    }
    // 输出链表
    Node curNode_odd = headNode_odd->next;
    Node curNode_even = headNode_even->next;
    while (curNode_odd != NULL) {
        printf("%d ", curNode_odd->val);
        curNode_odd = curNode_odd->next;
    }
    putchar('\n');
    while (curNode_even != NULL) {
        printf("%d ", curNode_even->val);
        curNode_even = curNode_even->next;
    }
    putchar('\n');
}