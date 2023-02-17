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

void printList(List list) {
    Node node = list->next;
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
    putchar('\n');
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
    int size;
    int target;
    List list = createList();
    while (1) {
        scanf("%d", &temp);
        if (temp == -1) {
            break;
        }
        addNode(list, createNode(temp));
    }
    printList(sortList(list, 1));
}