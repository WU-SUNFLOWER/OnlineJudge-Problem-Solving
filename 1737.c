#include <stdio.h>
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

int main() {
    int size = 0;
    Node head = createNode(-1);
    // 建表
    Node lastNode = head;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        Node node = createNode(-1);
        scanf("%d", &node->val);
        lastNode->next = node;
        lastNode = node;
    }
    // 插入排序
    Node curNode = head->next;
    Node head_new = createNode(-1);
    while (curNode != NULL) {
        int targetVal = curNode->val;
        // 从头开始扫描新链表，寻找合适的插入位置
        Node lastNode_new = head_new;
        Node curNode_new = lastNode_new->next;
        while (curNode_new != NULL && curNode_new->val < targetVal) {
            lastNode_new = curNode_new;
            curNode_new = curNode_new->next;
        }
        // 将节点与新链表中的前驱节点连接
        lastNode_new->next = curNode;
        // 保存原先curNode的后继节点
        Node nextNode = curNode->next;
        // 将节点与新链表中的后继节点连接
        curNode->next = curNode_new;        
        // 更新遍历旧链表用的curNode节点
        curNode = nextNode;
    }
    // 打印链表
    curNode = head->next;
    while (curNode != NULL) {
        printf("%d ", curNode->val);
        curNode = curNode->next;
    }
}