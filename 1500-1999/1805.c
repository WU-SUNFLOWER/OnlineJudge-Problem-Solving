#include <stdio.h>
#include <stdlib.h>

typedef struct trnode {
    // ��������ڵ��ʾ����ǰ��Ʒ���뱳��������
    struct trnode* left;
    // �������ҽڵ��ʾ������ǰ��Ʒ���뱳��������
    struct trnode* right;
    // ��ǰ��������Ʒ���ܼ�ֵ
    int value;
    // ��ǰ������ʣ������
    int capcity;
    // ���ö����Ƽ�¼���ž��ߵ�·��,
    // �����λ1Ϊ�ڱ�λ֮�⣬������λ0��ʾ��ǰ��Ʒ���ţ�1��ʾ��ǰ��Ʒ��
    int path;
} *TNode, *Tree;

int productNum;
int totalCapcity;
int values[100];
int weights[100];

TNode createNode(int value, int capcity, int path) {
    TNode node = (TNode)malloc(sizeof(struct trnode));
    node->value = value;
    node->capcity = capcity;
    node->path = path;
    return node;
}

int solve(TNode node, int idx) {
    if (idx >= productNum) {
        return node->value;
    }
    int ans1 = 0;
    int ans2 = 0;
    //���۵�ǰ��Ʒ���뱳��������
    if (node->capcity >= weights[idx]) {
        node->left = createNode(node->value + values[idx], node->capcity - weights[idx], node->path * 2 + 1);
        ans1 = solve(node->left, idx + 1);
    } else {
        node->left = NULL;
    }
    // ���۵�ǰ���������뱳��������
    node->right = createNode(node->value, node->capcity, node->path * 2);
    ans2 = solve(node->right, idx + 1);
    // �������������е����Ž⣬�����ݸ��¾�����
    if (ans1 > ans2) {
        node->value = ans1;
        node->path = node->left->path;
    } else {
        node->value = ans2;
        node->path = node->right->path;
    }
    return node->value;
}

int main() {
    scanf("%d %d", &productNum, &totalCapcity);
    //��ȡ��Ʒ�ļ�ֵ
    for (int i = 0; i < productNum; i++) {
        scanf("%d", &values[i]);
    }
    //��ȡ��Ʒ������
    for (int i = 0; i < productNum; i++) {
        scanf("%d", &weights[i]);
    }
    //��ʼ�����������ݹ����
    TNode root = createNode(0, totalCapcity, 1);
    solve(root, 0);
    //������Ž�
    printf("Optimal value is\n%d\n", root->value);
    //��������Ƶ�·�����ݣ����
    int i = 0;
    int pathArr[100];
    int path = root->path;
    while (path) {
        pathArr[productNum - i] = path % 2;
        path /= 2;
        i++;
    }
    for (int i = 1; i <= productNum; i++) {
        printf(i == productNum ? "%d\n" : "%d ", pathArr[i]);
    }
}