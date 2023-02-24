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
    int n;  //原有小朋友的总数
    int m;  //报数间隔
    int p;  //需要求第p个出列的是哪位小朋友
    scanf("%d,%d,%d", &n, &m, &p);
    int size = n;  //统计当前队伍的总规模
    //构建包含头哨兵和尾哨兵的链表
    Node head = createNode(-1, NULL);
    Node lastNode = head;
    Node newNode;
    for (int i = 1; i <= n; i++) {
        newNode = createNode(i, lastNode);
        lastNode = newNode;
    }
    createNode(-2, lastNode);
    //模拟报数过程
    int ansId;  //第p位离队的小朋友的编号
    int hasLeftCnt = 0;  //统计已离队的人数
    while (size > m - 1) {
        int cnt = -1;
        Node tempNode;
        Node curNode = head;
        //正向报数,报到m出列
        while (curNode->id != -2) {
            if (++cnt == m) {
                cnt = 0;
                size--;
                hasLeftCnt++;
                hasLeftCnt == p && (ansId = curNode->id);
                //移除节点
                tempNode = curNode;
                curNode->last->next = curNode->next;
                curNode->next->last = curNode->last;
                curNode = curNode->next;
                free(tempNode);
            } else {
                curNode = curNode->next;
            }
        }
        //反向报数，报到m出列
        cnt = -1;
        while (curNode->id != -1) {
            if (++cnt == m) {
                cnt = 0;
                size--;
                hasLeftCnt++;
                hasLeftCnt == p && (ansId = curNode->id);
                //移除节点
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
    //输出答案
    Node curNode = head->next;
    while (curNode->id != -2) {
        printf("%d ", curNode->id);
        curNode = curNode->next;
    }
    putchar('\n');
    printf("%d\n", ansId);
}