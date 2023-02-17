#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ����ģ�鿪ʼ */

typedef struct node {
    int value;
    char name[100];
    struct node* next;
} *Node, *List;

Node createNode(int value, char name[]) {
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->value = value;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

List createList() {
    //����Ӧ��ӵ��ͷ��dummy�ڵ�
    List list = createNode(-1, "dummy");  
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

void printList(List list) {
    Node node = list->next;
    while (node != NULL) {
        printf("%s %d\n", node->name, node->value);
        node = node->next;
    }
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

List sortList(List list, int k) {
    Node preNode;  //ǰ���ڵ�
    Node leftNode;  //����Ƚϵ���ڵ�
    Node rightNode;  //����Ƚϵ��ҽڵ�
    Node tailNode;  //���������������β���ڵ�
    Node headNode = list->next;  //�����׽ڵ�
    //���Ϊ���������߽���һ���ڵ����������������
    if (headNode == NULL || headNode->next == NULL) {
        return list;
    }
    //��ʼ��tailNode
    for (tailNode = headNode; tailNode->next; tailNode = tailNode->next);
    //������뿪ʼ
    while (tailNode != headNode) {
        preNode = list;
        leftNode = preNode->next;
        while (leftNode != tailNode) {
            rightNode = leftNode->next;
            if (leftNode->value * k > rightNode->value * k) {
                preNode->next = rightNode;
                leftNode->next = rightNode->next;
                rightNode->next = leftNode;
                if (tailNode == rightNode) {
                    tailNode = leftNode;
                }
            }
            preNode = preNode->next;
            leftNode = preNode->next;
        }
        //��������ԭ�ȵ��׽ڵ���ܱ�������������Ҫ���¸���headNode����
        headNode = list->next;
        tailNode = preNode;
    }
    return list;
}


/* ����ģ����� */

int main() {
    int temp;
    char tempString[100];
    List list = createList();
    //��ȡԭ����
    while (~scanf("%s", tempString)) {
        if (strcmp(tempString, "#") == 0) { 
            break;
        }
        scanf("%d", &temp);
        addNode(list, createNode(temp, tempString));
    }
    //��������½ڵ�
    Node newNode;
    Node preNode;
    Node curNode;
    while (~scanf("%s", tempString)) {
        if (strcmp(tempString, "#") == 0) { 
            break;
        }
        scanf("%d", &temp);
        preNode = list;
        curNode = list->next;
        newNode = createNode(temp, tempString);
        while (1) {
            if (curNode != NULL && curNode->value >= newNode->value) {
                preNode = curNode;
                curNode = curNode->next;
            } else {
                preNode->next = newNode;
                newNode->next = curNode;
                break;
            }
        }
    }
    while (~scanf("%s", tempString)) {
        if (strcmp(tempString, "#") == 0) { 
            break;
        }
        preNode = list;
        curNode = list->next;
        while (curNode != NULL) {
            if (strcmp(curNode->name, tempString) == 0) {
                preNode->next = curNode->next;
                free(curNode);
                curNode = preNode->next;
                break;
            } else {
                preNode = curNode;
                curNode = curNode->next;
            }
        }
    }
    printList(list);
}