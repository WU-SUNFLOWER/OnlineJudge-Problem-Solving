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
    Node nextNode;
    Node curNode = headNode->next;
    while (curNode != NULL) {
        nextNode = curNode->next;
        printf(nextNode ? "%d " : "%d\n", curNode->value);
        curNode = nextNode;
    }
}

void freeList(Node headNode) {
    Node curNode = headNode;
    Node nextNode;
    while (curNode != NULL) {
        nextNode = curNode->next;
        free(curNode);
        curNode = nextNode;
    }
}

int main() {
    int size;
    while (~scanf("%d", &size)) {
        // 建表
        Node newNode;
        Node headNode = createNode(-1);  // dummy节点
        Node lastNode = headNode;
        Node tailNode;
        for (int i = 0; i < size; i++) {
            newNode = createNode(-1);
            scanf("%d", &newNode->value);
            lastNode = lastNode->next = newNode;
            if (i == size - 1) tailNode = newNode;
        }
        // 链表排序
        while (tailNode != headNode->next) {
            Node lastNode = headNode;
            // 冒泡排序中，每轮排序的开始起点是保持不动的
            Node curNode = headNode->next;
            Node nextNode = curNode->next;
            while (curNode != tailNode) {
                // 交换节点
                if (curNode->value > nextNode->value) {
                    // 修改前驱节点的next指针
                    lastNode->next = nextNode;
                    // 缓存原来的后驱节点
                    Node newNextNode = nextNode->next;
                    // 更新原来nextNode的next指针
                    nextNode->next = curNode;
                    // 如果原来的tail节点被换到前面来了，需要更新tail指针
                    if (nextNode == tailNode) {
                        tailNode = curNode;
                    }
                    // 更新原来的curNode指针
                    nextNode = curNode->next = newNextNode;
                } else {
                    curNode = nextNode;
                    nextNode = curNode->next;
                }
                lastNode = lastNode->next;
            }
            // 更新tail指针
            tailNode = lastNode;
        }
        // 输出排序好的链表
        printList(headNode);
        // 销毁链表
        freeList(headNode);      
    }
}