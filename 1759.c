#include <stdio.h>
#include <stdlib.h>

/* 链表模块开始 */

typedef struct node {
    int value;
    struct node* next;
} *Node, *List;

Node createNode(int value) {
    Node node = (Node)malloc(sizeof(node));
    node->value = value;
    node->next = NULL;
    return node;
}

List createList() {
    //链表应当拥有头部dummy节点
    List list = createNode(-1);  
    return list;
}

List addNode(List list, Node newNode) {
    Node curNode = list;
    Node nextNode = curNode->next;
    while (nextNode != NULL) {
        curNode = nextNode;
        nextNode = curNode->next;
    }
    curNode->next = newNode;
    newNode->next = NULL;
    return list;
}

List reverseList(List list) {
    Node lastNode = NULL;
    Node curNode = list->next;
    Node nextNode;
    while (curNode != NULL) {
        nextNode = curNode->next;
        curNode->next = lastNode;
        lastNode = curNode;
        curNode = nextNode;
    }
    list->next = lastNode;  //将原链表dummy节点的指针指向新链表
    return list;
}

void printList(List list) {
    Node node = list->next;
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
    putchar('\n');
}

/* 链表模块结束 */

int main() {
    int temp;
    int size;
    int target;
    List list = createList();
    //读入链表
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &temp);
        addNode(list, createNode(temp));
    }
    printList(reverseList(list));
}