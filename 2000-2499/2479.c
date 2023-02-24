#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int id;
    struct node* last;
    struct node* next;
} *Node;

Node createNode(int id, Node last) {
    Node p = (Node)malloc(sizeof(struct node));
    last && (last->next = p);
    p->id = id;
    p->last = last;
    p->next = NULL;
    return p;
}

int main() {
    int n;  //ԭ��С���ѵ�����
    int m;  //�������
    int p;  //��Ҫ���p�����е�����λС����
    scanf("%d,%d,%d", &n, &m, &p);
    int size = n;  //ͳ�Ƶ�ǰ������ܹ�ģ
    //��������ͷ�ڱ���β�ڱ�������
    Node head = createNode(-1, NULL);
    Node lastNode = head;
    Node newNode;
    for (int i = 1; i <= n; i++) {
        newNode = createNode(i, lastNode);
        lastNode = newNode;
    }
    createNode(-2, lastNode);
    //ģ�ⱨ������
    int ansId;  //��pλ��ӵ�С���ѵı��
    int hasLeftCnt = 0;  //ͳ������ӵ�����
    while (size > m - 1) {
        int cnt = -1;
        Node tempNode;
        Node curNode = head;
        //������,����m����
        while (curNode->id != -2) {
            if (++cnt == m) {
                cnt = 0;
                size--;
                hasLeftCnt++;
                hasLeftCnt == p && (ansId = curNode->id);
                //�Ƴ��ڵ�
                tempNode = curNode;
                curNode->last->next = curNode->next;
                curNode->next->last = curNode->last;
                curNode = curNode->next;
                free(tempNode);
            } else {
                curNode = curNode->next;
            }
        }
        //������������m����
        cnt = -1;
        while (curNode->id != -1) {
            if (++cnt == m) {
                cnt = 0;
                size--;
                hasLeftCnt++;
                hasLeftCnt == p && (ansId = curNode->id);
                //�Ƴ��ڵ�
                tempNode = curNode;
                curNode->last->next = curNode->next;
                curNode->next->last = curNode->last;
                curNode = curNode->last;
                free(tempNode);
            } else {
                curNode = curNode->last;
            }
        }
    }
    //�����
    Node curNode = head->next;
    while (curNode->id != -2) {
        printf("%d ", curNode->id);
        curNode = curNode->next;
    }
    putchar('\n');
    printf("%d\n", ansId);
}