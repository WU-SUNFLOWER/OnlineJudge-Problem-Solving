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
    // ����
    Node lastNode = head;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        Node node = createNode(-1);
        scanf("%d", &node->val);
        lastNode->next = node;
        lastNode = node;
    }
    // ��������
    Node curNode = head->next;
    Node head_new = createNode(-1);
    while (curNode != NULL) {
        int targetVal = curNode->val;
        // ��ͷ��ʼɨ��������Ѱ�Һ��ʵĲ���λ��
        Node lastNode_new = head_new;
        Node curNode_new = lastNode_new->next;
        while (curNode_new != NULL && curNode_new->val < targetVal) {
            lastNode_new = curNode_new;
            curNode_new = curNode_new->next;
        }
        // ���ڵ����������е�ǰ���ڵ�����
        lastNode_new->next = curNode;
        // ����ԭ��curNode�ĺ�̽ڵ�
        Node nextNode = curNode->next;
        // ���ڵ����������еĺ�̽ڵ�����
        curNode->next = curNode_new;        
        // ���±����������õ�curNode�ڵ�
        curNode = nextNode;
    }
    // ��ӡ����
    curNode = head->next;
    while (curNode != NULL) {
        printf("%d ", curNode->val);
        curNode = curNode->next;
    }
}