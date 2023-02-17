#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int id;
    int score;
    struct node* next;
} *Node;

Node createNode(int id, int score) {
    Node p = (Node)malloc(sizeof(struct node));
    p->id = id;
    p->score = score;
    p->next = NULL;
    return p;
}

void sort(Node headNode) {
    Node firstNode = headNode->next;
    Node tailNode = NULL;
    Node preNode = headNode;
    Node curNode;
    Node nextNode;
    //�������ֻ��һ���ڵ��������Ҫ����
    if (!firstNode || !firstNode->next) {
        return;
    }
    //ȷ������β���ڵ�
    //����ʼ
    while (firstNode != tailNode) {
        curNode = firstNode;
        while (curNode->next != tailNode) {
            nextNode = curNode->next;
            if (curNode->id > nextNode->id) {
                preNode->next = nextNode;
                curNode->next = nextNode->next;
                nextNode->next = curNode;
                curNode = nextNode;
            }
            preNode = preNode->next;
            curNode = curNode->next;
        }
        //ÿ��ѭ������������ָ����й�λ
        tailNode = curNode;
        preNode = headNode;
        firstNode = headNode->next;
    }
}

int main() {
    int id;
    int score;
    Node headNode = createNode(-1, -1);
    Node lastNode = headNode;
    Node curNode;
    scanf("%d %d", &id, &score);
    //��������
    while (~scanf("%d %d", &id, &score)) {
        curNode = createNode(id, score);
        lastNode->next = curNode;
        lastNode = curNode;
    }
    //��������
    sort(headNode);
    //���
    curNode = headNode->next;
    while (curNode) {
        printf("%d %d\n", curNode->id, curNode->score);
        curNode = curNode->next;
    }
}