#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 链表模块开始 */

typedef struct node {
    int value;
    char name[100];
    struct node* next;
} *Node, *List;

Node createNode(int value, char name[]) {
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->value = value;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

List createList() {
    //链表应当拥有头部dummy节点
    List list = createNode(-1, "dummy");  
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

void printList(List list) {
    Node node = list->next;
    while (node != NULL) {
        printf("%s %d\n", node->name, node->value);
        node = node->next;
    }
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

List sortList(List list, int k) {
    Node preNode;  //前卫节点
    Node leftNode;  //参与比较的左节点
    Node rightNode;  //参与比较的右节点
    Node tailNode;  //参与排序子链表的尾部节点
    Node headNode = list->next;  //链表首节点
    //如果为空链表，或者仅含一个节点的链表，则无需排序
    if (headNode == NULL || headNode->next == NULL) {
        return list;
    }
    //初始化tailNode
    for (tailNode = headNode; tailNode->next; tailNode = tailNode->next);
    //排序代码开始
    while (tailNode != headNode) {
        preNode = list;
        leftNode = preNode->next;
        while (leftNode != tailNode) {
            rightNode = leftNode->next;
            if (leftNode->value * k > rightNode->value * k) {
                preNode->next = rightNode;
                leftNode->next = rightNode->next;
                rightNode->next = leftNode;
                if (tailNode == rightNode) {
                    tailNode = leftNode;
                }
            }
            preNode = preNode->next;
            leftNode = preNode->next;
        }
        //由于链表原先的首节点可能被动过，所以需要重新更新headNode变量
        headNode = list->next;
        tailNode = preNode;
    }
    return list;
}


/* 链表模块结束 */

int main() {
    int temp;
    char tempString[100];
    List list = createList();
    //读取原链表
    while (~scanf("%s", tempString)) {
        if (strcmp(tempString, "#") == 0) { 
            break;
        }
        scanf("%d", &temp);
        addNode(list, createNode(temp, tempString));
    }
    //处理插入新节点
    Node newNode;
    Node preNode;
    Node curNode;
    while (~scanf("%s", tempString)) {
        if (strcmp(tempString, "#") == 0) { 
            break;
        }
        scanf("%d", &temp);
        preNode = list;
        curNode = list->next;
        newNode = createNode(temp, tempString);
        while (1) {
            if (curNode != NULL && curNode->value >= newNode->value) {
                preNode = curNode;
                curNode = curNode->next;
            } else {
                preNode->next = newNode;
                newNode->next = curNode;
                break;
            }
        }
    }
    while (~scanf("%s", tempString)) {
        if (strcmp(tempString, "#") == 0) { 
            break;
        }
        preNode = list;
        curNode = list->next;
        while (curNode != NULL) {
            if (strcmp(curNode->name, tempString) == 0) {
                preNode->next = curNode->next;
                free(curNode);
                curNode = preNode->next;
                break;
            } else {
                preNode = curNode;
                curNode = curNode->next;
            }
        }
    }
    printList(list);
}