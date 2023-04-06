#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 22

typedef struct node {
    char name[N];
    int Llink;
    int Rlink;
} *Node;

struct DB {
    int size;  // 链表规模
    Node datas[N];  // 存节点用的数组，这里首个节点就不存东西了，和题目保持一致
} DataBase;

void initDataBase() {
    DataBase.size = 0;
    DataBase.datas[0] = (Node)malloc(sizeof(struct node));
    DataBase.datas[0]->Llink = 0;
    DataBase.datas[0]->Rlink = 0;
}

void AddDataBase(char arg[]) {
    int cur = DataBase.datas[0]->Rlink;
    Node node = DataBase.datas[cur];
    while (cur != 0) {
        // 如果新插入节点的字典序比当前节点大，访问下一个节点
        // 如果新插入节点的字典序比当前字典序小，直接退出
        if (strcmp(arg, node->name) > 0) {
            // 如果已经是最后一个节点了，就不往下访问了
            if (!node->Rlink) {
                break;
            }
            // 否则继续访问下一个节点
            cur = node->Rlink;
            node = DataBase.datas[cur];
        } else {
            // 把cur和node回溯到前一个节点
            cur = node->Llink;
            node = DataBase.datas[cur];
            break;
        }
    }
    // 安置新节点，将其插入到cur指向的节点node后边
    int newIdx = ++DataBase.size;
    Node newNode = DataBase.datas[newIdx] = (Node)malloc(sizeof(struct node));
    // 拷贝乘客名
    strcpy(newNode->name, arg);
    // 更新新节点的指针
    newNode->Rlink = node->Rlink;
    newNode->Llink = cur;
    // 更新后继节点的指针
    DataBase.datas[node->Rlink]->Llink = newIdx;
    // 更新前驱节点的指针
    node->Rlink = newIdx;
}

void DeleteDataBase(char arg[]) {
    Node node;
    for (int i = 1; i <= DataBase.size; i++) {
        node = DataBase.datas[i];
        if (strcmp(node->name, arg) == 0) {
            int last = node->Llink;
            int right = node->Rlink;
            DataBase.datas[last]->Rlink = right;
            DataBase.datas[right]->Llink = last;
            break;
        }
    }
}

bool queryDataBase(char arg[]) {
    Node node;
    for (int i = 1; i <= DataBase.size; i++) {
        node = DataBase.datas[i];
        if (strcmp(node->name, arg) == 0) return true;
    }
    return false;
}

void printDataBase() {
    int cur = DataBase.datas[0]->Rlink;
    Node node;
    while (cur != 0) {
        node = DataBase.datas[cur];
        puts(node->name);
        cur = node->Rlink;
    }
}

int main() {
    char command[N];
    char argument[N];  // 存操作携带的参数（如果有的话）
    initDataBase();  // 初始化链表
    while (~scanf("%s", command)) {
        if (strcmp(command, "Add") == 0) {
            scanf("%s", argument);
            AddDataBase(argument);
        }
        else if (strcmp(command, "Delete") == 0) {
            scanf("%s", argument);
            DeleteDataBase(argument);
        }
        else if (strcmp(command, "Query") == 0) {
            scanf("%s", argument);
            bool ans = queryDataBase(argument);
            puts(ans ? "Yes" : "No");
        }
        else if (strcmp(command, "Print") == 0) {
            printDataBase();
        }
    }
}