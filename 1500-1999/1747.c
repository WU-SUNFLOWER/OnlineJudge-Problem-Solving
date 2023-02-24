#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node* next;  
} *Node;

Node createNode(int value) {
    Node node = (Node)malloc(sizeof(struct node));
    node->value = value;
    node->next = NULL;
    return node;
}

void printList(Node headNode) {
    Node curNode = headNode->next;
    while (curNode != NULL) {
        printf("%d ", curNode->value);
        curNode = curNode->next;
    }
}

int main() {
    int size;
    scanf("%d", &size);
    // 建表
    Node newNode;
    Node headNode = createNode(-1);  // dummy节点
    Node lastNode = headNode;
    for (int i = 0; i < size; i++) {
        newNode = createNode(-1);
        scanf("%d", &newNode->value);
        lastNode = lastNode->next = newNode;
    }
    // 链表排序
    Node preNode = headNode;
    Node startNode = headNode->next;
    while (startNode != NULL) {
        Node lastNode = preNode;
        Node curNode = startNode;
        Node nextNode = curNode->next;
        while (nextNode != NULL) {
            // 交换节点
            if (curNode->value > nextNode->value) {
                // 修改前驱节点的next指针
                lastNode->next = nextNode;
                // 缓存原来的后驱节点
                Node newNextNode = nextNode->next;
                // 更新原来nextNode的next指针
                nextNode->next = curNode;
                // 更新原来的curNode指针
                nextNode = curNode->next = newNextNode;
            } else {
                curNode = nextNode;
                nextNode = curNode->next;
            }
            lastNode = lastNode->next;
        }
        preNode = preNode->next;
        startNode = startNode->next;
    }
    // 输出排序好的链表
    printList(headNode);
}