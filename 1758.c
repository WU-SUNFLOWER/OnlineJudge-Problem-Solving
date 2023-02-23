#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} *Node;

Node createNode(int val) {
    Node node = (Node)malloc(sizeof(struct node));
    node->val = val;
    node->next = NULL;
    return node;
}

void clear(Node head) {
    Node nextNode;
    Node curNode = head->next;
    while (curNode != NULL) {
        nextNode = curNode->next;
        free(curNode);
        curNode = nextNode;
    }
    head->next = NULL;
    head->val = 0;
}

int getElem(Node head, int pos) {
    Node curNode = head;
    for (int cnt = 0; cnt < pos; cnt++) {
        curNode = curNode->next;
    }
    return curNode->val;
}

int deleteElem(Node head, int pos) {
    Node curNode = head;
    Node lastNode = NULL;
    for (int cnt = 0; cnt < pos; cnt++) {
        lastNode = curNode;
        curNode = curNode->next;
    }
    int ans = curNode->val;
    lastNode->next = curNode->next;
    free(curNode);
    head->val--;
    return ans;
}

void insertElem(Node head, int pos, Node node) {
    Node curNode = head;
    Node lastNode = NULL;
    for (int cnt = 0; cnt < pos; cnt++) {
        lastNode = curNode;
        curNode = curNode->next;
    }
    lastNode->next = node;
    node->next = curNode;
    head->val++;
}

int main() {
    int size = 0;
    Node headNode = createNode(0);  // 这里直接借助头节点储存链表规模
    char command[10];
    while (~scanf("%s", command)) {
        // 退出程序
        if (strcmp(command, "exit") == 0) {
            break;
        }
        // 清除线性表
        else if (strcmp(command, "clear") == 0) {
            clear(headNode);
        }
        // 获取元素
        else if (strcmp(command, "getelem") == 0) {
            int pos;
            scanf("%d", &pos);
            printf("%d\n", getElem(headNode, pos));
        }
        // 删除元素
        else if (strcmp(command, "delete") == 0) {
            int pos;
            scanf("%d", &pos);
            printf("%d\n", deleteElem(headNode, pos));
        }
        // 插入元素
        else if (strcmp(command, "insert") == 0) {
            int tot, pos, val;
            scanf("%d", &tot);
            for (int i = 0; i < tot; i++) {
                scanf("%d %d", &pos, &val);
                insertElem(headNode, pos, createNode(val));
            }
        }
    }
}