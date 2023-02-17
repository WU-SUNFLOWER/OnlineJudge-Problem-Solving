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
    int size1;
    int size2;
    List tempList;
    List list1 = createList();  //Ĭ�ϴ��������
    List list2 = createList();  //Ĭ�ϴ��泤����
    List list3 = createList();  //�鲢�������
    //��ȡ��������
    scanf("%d", &size1);
    for (int i = 0; i < size1; i++) {
        scanf("%d", &temp);
        addNode(list1, createNode(temp));
    }
    scanf("%d", &size2);
    for (int i = 0; i < size2; i++) {
        scanf("%d", &temp);
        addNode(list2, createNode(temp));
    }
    //�������Ҫ����Ҫ��������
    if (size1 > size2) {
        temp = size1;
        size1 = size2;
        size2 = temp;
        tempList = list1;
        list1 = list2;
        list2 = tempList;
    }
    Node nextNode1;
    Node nextNode2;
    Node curNode1 = list1->next;
    Node curNode2 = list2->next;
    while (curNode1 != NULL) {
        if (curNode1->value == curNode2->value) {
            nextNode1 = curNode1->next;
            nextNode2 = curNode2->next;
            addNode(list3, curNode1);
            addNode(list3, curNode2);
            curNode1 = nextNode1;
            curNode2 = nextNode2;
        }
        else if (curNode1->value < curNode2->value) {
            nextNode1 = curNode1->next;
            addNode(list3, curNode1);
            curNode1 = nextNode1;
        }
        else {
            nextNode2 = curNode2->next;
            addNode(list3, curNode2);
            curNode2 = nextNode2;
        }
    }
    while (curNode2 != NULL) {
        nextNode2 = curNode2->next;
        addNode(list3, curNode2);
        curNode2 = nextNode2;
    }
    printList(reverseList(list3));
}