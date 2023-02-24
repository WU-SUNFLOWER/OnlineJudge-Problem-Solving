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
    Node curNode = headNode->next;
    while (curNode != NULL) {
        printf("%d ", curNode->value);
        curNode = curNode->next;
    }
}

int main() {
    int size;
    scanf("%d", &size);
    // ����
    Node newNode;
    Node headNode = createNode(-1);  // dummy�ڵ�
    Node lastNode = headNode;
    for (int i = 0; i < size; i++) {
        newNode = createNode(-1);
        scanf("%d", &newNode->value);
        lastNode = lastNode->next = newNode;
    }
    // ��������
    Node preNode = headNode;
    Node startNode = headNode->next;
    while (startNode != NULL) {
        Node lastNode = preNode;
        Node curNode = startNode;
        Node nextNode = curNode->next;
        while (nextNode != NULL) {
            // �����ڵ�
            if (curNode->value > nextNode->value) {
                // �޸�ǰ���ڵ��nextָ��
                lastNode->next = nextNode;
                // ����ԭ���ĺ����ڵ�
                Node newNextNode = nextNode->next;
                // ����ԭ��nextNode��nextָ��
                nextNode->next = curNode;
                // ����ԭ����curNodeָ��
                nextNode = curNode->next = newNextNode;
            } else {
                curNode = nextNode;
                nextNode = curNode->next;
            }
            lastNode = lastNode->next;
        }
        preNode = preNode->next;
        startNode = startNode->next;
    }
    // �������õ�����
    printList(headNode);
}