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
    //查找节点
    scanf("%d", &id);
    curNode = headNode->next;
    while (curNode) {
        if (curNode->id == id) {
            printf("%d %s %d\n", id, curNode->name, curNode->score);
            break;
        }
        curNode = curNode->next;
    }
}