#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

typedef struct trnode {
    char value;
    bool leftTag;  // 0表示left指针指向节点的左子树，1表示指向节点的前驱
    bool rightTag;  // 0表示right指针指向节点的右子树，1表示指向节点的后继
    struct trnode* left;
    struct trnode* right;
} *TNode, *Tree;

Tree createTree(char str[], int* offset) {
    char value = str[(*offset)++];
    if (value == '#' || value == '\0') {
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
    //递归遍历左子树
    createThreadedTree(node->left, preNodePointer);
    //为当前节点设置前驱
    TNode preNode = *preNodePointer;
    if (!node->left && !node->leftTag) {
        node->left = preNode;
        node->leftTag = 1;
    }
    //为前驱节点设置后继
    if (preNode && !preNode->right && !preNode->rightTag) {
        preNode->right = node;
        preNode->rightTag = 1;
    }
    //将自身设置为中序遍历得到下一个节点的前驱节点
    *preNodePointer = node;
    //递归遍历右子树
    createThreadedTree(node->right, preNodePointer);
    return node;
}

void inOrderTraverse(Tree tree) {
    while (tree) {
        //遍历左子树,直至碰到最左边的叶节点
        while (!tree->leftTag) {
            tree = tree->left;
        }
        putchar(tree->value);
        //回溯输出遍历路径上的父节点
        while (tree->rightTag) {
            tree = tree->right;
            putchar(tree->value);
        }
        //转向右子树
        tree = tree->right;
    }
}

int main() {
    int t;
    char str[100];
    scanf("%d", &t);
    getchar();
    while (t--) {
        //创建二叉树，并且转换成线索二叉树
        gets(str);
        int offset = 0;
        TNode preNode = NULL;
        Tree tree = createThreadedTree(createTree(str, &offset), &preNode);
        //利用线索二叉树的特性进行中序遍历
        inOrderTraverse(tree);
        putchar('\n');
        destroyTree(tree);
    }
}