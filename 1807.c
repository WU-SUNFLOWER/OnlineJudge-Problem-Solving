#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

typedef struct trnode {
    char value;
    bool leftTag;  // 0��ʾleftָ��ָ��ڵ����������1��ʾָ��ڵ��ǰ��
    bool rightTag;  // 0��ʾrightָ��ָ��ڵ����������1��ʾָ��ڵ�ĺ��
    struct trnode* left;
    struct trnode* right;
} *TNode, *Tree;

Tree createTree(char str[], int* offset) {
    char value = str[(*offset)++];
    if (value == ' ' || value == '\0') {
        return NULL;
    } else {
        TNode node = (TNode)malloc(sizeof(struct trnode));
        node->value = value;
        node->leftTag = 0;
        node->rightTag = 0;
        node->left = createTree(str, offset);
        node->right = createTree(str, offset);
        return node;
    }
}

int destroyTree(Tree tree) {
    if (tree == NULL) {
        return 1;
    }
    !tree->leftTag && destroyTree(tree->left);
    !tree->rightTag && destroyTree(tree->right);
    free(tree);
    return 1;
}

Tree createThreadedTree(TNode node, TNode* preNodePointer) {
    if (node == NULL) {
        return NULL;
    }
    //�ݹ����������
    createThreadedTree(node->left, preNodePointer);
    //Ϊ��ǰ�ڵ�����ǰ��
    TNode preNode = *preNodePointer;
    if (!node->left && !node->leftTag) {
        node->left = preNode;
        node->leftTag = 1;
    }
    //Ϊǰ���ڵ����ú��
    if (preNode && !preNode->right && !preNode->rightTag) {
        preNode->right = node;
        preNode->rightTag = 1;
    }
    //����������Ϊ��������õ���һ���ڵ��ǰ���ڵ�
    *preNodePointer = node;
    //�ݹ����������
    createThreadedTree(node->right, preNodePointer);
    return node;
}

void inOrderTraverse(Tree tree) {
    while (tree) {
        //����������,ֱ����������ߵ�Ҷ�ڵ�
        while (!tree->leftTag) {
            tree = tree->left;
        }
        putchar(tree->value);
        //�����������·���ϵĸ��ڵ�
        while (tree->rightTag) {
            tree = tree->right;
            putchar(tree->value);
        }
        //ת��������
        tree = tree->right;
    }
}

int main() {
    int t;
    char str[100];
    scanf("%d", &t);
    getchar();
    while (t--) {
        //����������������ת��������������
        gets(str);
        int offset = 0;
        TNode preNode = NULL;
        Tree tree = createThreadedTree(createTree(str, &offset), &preNode);
        //�������������������Խ����������
        inOrderTraverse(tree);
        putchar('\n');
        destroyTree(tree);
    }
}