#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    char name[30];
    int id;
    int score;
    struct node* next;
} *Node;


Node createNode(int id, char* name, int score) {
    Node p = (Node)malloc(sizeof(struct node));
    p->id = id;
    p->score = score;
    p->next = NULL;
    name && strcpy(p->name, name);
    return p;
}

int main() {
    int id;
    int score;
    char tempString[30];
    //创建链表
    Node headNode = createNode(-1, NULL, -1);
    Node curNode = headNode;
    while (scanf("%d", &id) && id) {
        scanf("%s %d", tempString, &score);
        curNode->next = createNode(id, tempString, score);
        curNode = curNode->next;
    }
    //插入节点
    scanf("%d %s %d", &id, tempString, &score);
    Node newNode = createNode(id, tempString, score);
    Node preNode = headNode;
    int flag = 1;
    curNode = headNode->next;
    while (curNode) {
        if (curNode->id > id && flag) {
            preNode->next = newNode;
            newNode->next = curNode;
            curNode = newNode;
            flag = 0;
        }
        printf("%d %s %d\n", curNode->id, curNode->name, curNode->score);
        curNode = curNode->next;
        preNode = preNode->next;
    }
}