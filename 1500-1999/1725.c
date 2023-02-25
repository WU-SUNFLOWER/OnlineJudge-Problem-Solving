#include <stdio.h>
#include <stdlib.h>

/* ����ģ�鿪ʼ */

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
    //����Ӧ��ӵ��ͷ��dummy�ڵ�
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
    list->next = lastNode;  //��ԭ����dummy�ڵ��ָ��ָ��������
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

/* ����ģ����� */

int main() {
    int temp;
    int size;
    int target;
    List list = createList();
    //��������
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &temp);
        addNode(list, createNode(temp));
    }
    scanf("%d", &target);
    //���
    //��һ��������������
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
    //�ڶ�����ȷ����target������м���
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
    //�����������
    printf("%d\n", count);
    printList(newList);
}