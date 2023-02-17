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
    scanf("%d", &target);
    //求解
    //第一步：求逆序链表
    List newList = createList();
    Node lastNode = NULL;
    Node curNode = list->next;
    Node nextNode;
    while (curNode != NULL && curNode->value < target) {
        nextNode = curNode->next;
        curNode->next = lastNode;
        lastNode = curNode;
        curNode = nextNode;
    }
    newList->next = lastNode;
    //第二步：确定比target大的数有几个
    int count = 0;
    while (curNode != NULL && curNode->value <= target) {
        curNode = curNode->next;
    }
    if (curNode != NULL) {
        int curValue = curNode->value;
        curNode = curNode->next;
        count = 1;
        while (curNode != NULL) {
            if (curNode->value != curValue) {
                count++;
                curValue = curNode->value;
            }
            curNode = curNode->next;
        }
    }
    //第三步：输出
    printf("%d\n", count);
    printList(newList);
}