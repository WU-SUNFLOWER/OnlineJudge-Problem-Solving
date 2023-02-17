#include <stdio.h>
#include <stdlib.h>

/* ��������ʼ */
typedef struct trnode {
    char value;
    struct trnode* left;
    struct trnode* right;
} *TNode, *Tree;
/* ���������� */

/*������ģ�鿪ʼ*/
Tree buildTree(char str[], int* offset) {
    char value = str[*offset];
    (*offset)++;
    if (value == ' ') {
        return NULL;
    } else {
        TNode node = (TNode)malloc(sizeof(struct trnode));
        node->value = value;
        node->left = buildTree(str, offset);
        node->right = buildTree(str, offset);
        return node;
    }
}

void freeTree(TNode node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

void preOrderTraverse(TNode node, int ansArr[], int* ansIdx, int depth) {
    if (node == NULL) {
        return;
    }
    if (node->left == NULL && node->right == NULL) {
        ansArr[(*ansIdx)++] = depth;
        return;
    }
    preOrderTraverse(node->left, ansArr, ansIdx, depth + 1);
    preOrderTraverse(node->right, ansArr, ansIdx, depth + 1);
}

/* ������ģ����� */

int compare(int* a, int* b) {
    return *b - *a;
}

int main() {
    int t;
    char str[1000];
    int ansArr[1000];  //��¼����Ҷ�ڵ�����
    scanf("%d", &t);
    getchar();
    while (t-- > 0) {
        int ans;
        int offset = 0;
        int ansIdx = 0;
        //����
        gets(str);
        Tree tree = buildTree(str, &offset);
        //������������Ҷ�ڵ㣬�����ÿ��Ҷ�ڵ����ȣ�����������
        preOrderTraverse(tree, ansArr, &ansIdx, 0);
        qsort(ansArr, ansIdx, sizeof(int), compare);
        //�����ǰ���г���һ����Ҷ�ڵ㣬���Ϊ���������Ҷ�ڵ����֮��
        //�����ǰ��ֻ��һ��Ҷ�ڵ㣬���ΪҶ�ڵ����+1
        if (ansIdx > 1) {
            ans = ansArr[0] + ansArr[ansIdx - 1];
        } else {
            ans = ansArr[0] + 1;
        }
        printf("%d\n", ans);
        freeTree(tree);
    }
}