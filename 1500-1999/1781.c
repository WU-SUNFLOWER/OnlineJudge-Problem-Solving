#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
   int val;
   struct node* next; 
} *Node;

Node createNode(int val) {
    Node n = (Node)malloc(sizeof(struct node));
    n->val = val;
    n->next = NULL;
    return n;
}

void update(Node head) {
    Node lastNode = head;
    Node beginNode;
    Node curNode = lastNode->next;
    int cnt = -1;
    int curVal = -1;
    while (curNode != NULL) {
        // 第一种情况，计数器还在持续计数
        if (curNode->val == curVal) {
            cnt++;
        }
        // 第二种情况，碰到了新数字
        else {
            // 如果计数器已经满3了，则执行清除操作
            if (cnt >= 3) {
                Node lastNode_beCleared;
                Node curNode_beCleared = beginNode->next;
                while (curNode_beCleared != curNode) {
                    lastNode_beCleared = curNode_beCleared;
                    curNode_beCleared = lastNode_beCleared->next;
                    free(lastNode_beCleared);
                }
                beginNode->next = curNode;
            } 
            // 如果计数器没满3，别忘了重新定位beginNode
            else {
                beginNode = lastNode;
            }
            curVal = curNode->val;
            cnt = 1;
        }
        lastNode = curNode;
        curNode = curNode->next;
    }
    // 特判需要清除表尾元素的情况
    if (cnt >= 3) {
        Node lastNode_beCleared;
        Node curNode_beCleared = beginNode->next;
        while (curNode_beCleared != NULL) {
            lastNode_beCleared = curNode_beCleared;
            curNode_beCleared = lastNode_beCleared->next;
            free(lastNode_beCleared);
        }
        beginNode->next = NULL;
    }
}

void insert(Node head, int pos, int val) {
    int cnt = 0;
    Node lastNode = head;
    Node curNode = lastNode->next;
    while (cnt < pos && curNode != NULL) {
        lastNode = curNode;
        curNode = curNode->next;
        cnt++;
    }
    Node newNode = createNode(val);
    lastNode->next = newNode;
    newNode->next = curNode;
}

void printList(Node head) {
    Node curNode = head->next;
    while (curNode != NULL) {
        printf("%d", curNode->val);
        curNode = curNode->next;
    }
    putchar('\n');
}

int main() {
    char str[100];
    Node headNode = createNode(-1);
    Node lastNode = headNode;
    Node curNode;
    scanf("%s", str);
    for (int i = 0; str[i]; i++) {
        curNode = createNode(str[i] - '0');
        lastNode->next = curNode;
        lastNode = curNode;
    }
    int val, pos;
    while (~scanf("%d %d", &val, &pos)) {
        insert(headNode, pos, val);
        update(headNode);
        if (headNode->next == NULL) {
            puts("You win!");
            break;
        } else {
            printList(headNode);
            putchar('\n');
        }
    }
}