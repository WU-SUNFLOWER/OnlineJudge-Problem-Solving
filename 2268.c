#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int id;
    int val;
    struct node* pre;
    struct node* next;
} *Node;

Node createNode(int val, int id, Node pre) {
    Node node = (Node)malloc(sizeof(struct node));
    node->id = id;
    node->val = val;
    node->pre = pre;
    node->next = NULL;
    return node;
}

int main() {
    int size = 0;
    Node head = createNode(-1, 0, NULL);
    while (scanf("%d", &size) && size > 0) {
        int start;
        int end;
        scanf("%d %d", &start, &end);
        // 建表
        Node lastNode = head;
        for (int i = 1; i <= size; i++) {
            Node node = createNode(-1, i, lastNode);
            scanf("%d", &node->val);
            lastNode->next = node;
            lastNode = node;
        }
        // 逆向输出
        Node curNode = lastNode;
        while (curNode != NULL) {
            if (curNode->id == end) {
                break;
            }
            curNode = curNode->pre;
        }
        while (curNode->id >= start) {
            printf(curNode->id == start ? "%d\n" : "%d ", curNode->val);
            curNode = curNode->pre;
        }
    }
}