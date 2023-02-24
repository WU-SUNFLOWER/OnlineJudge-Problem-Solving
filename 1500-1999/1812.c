#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trnode {
    char value;
    struct trnode* left;
    struct trnode* right;
} *TNode, *Tree;

char preOrder[27];
char inOrder[27];

Tree createTree(int size, int preOrderIdx, int inOrderStart, int inOrderEnd) {
    if (inOrderStart >= size || inOrderEnd < 0 || inOrderStart > inOrderEnd) {
        return NULL;
    }
    //第一步：根据前序确定根节点
    char rootValue = preOrder[preOrderIdx];
    TNode root = (TNode)malloc(sizeof(struct trnode));
    int i;
    for (i = inOrderStart; i <= inOrderEnd; i++) {
        if (inOrder[i] == rootValue) {
            break;
        }
    }
    //第二步：根据中序确定左右子树
    root->value = rootValue;
    root->left = createTree(size, preOrderIdx + 1, inOrderStart, i - 1);
    root->right = createTree(size, preOrderIdx + i - inOrderStart + 1, i + 1, inOrderEnd);
    return root;
}

//后续遍历二叉树
void postOrderTraverse(TNode node) {
    if (node == NULL) {
        return;
    }
    postOrderTraverse(node->left);
    postOrderTraverse(node->right);
    printf("%c", node->value);
}

//销毁二叉树
void freeTree(TNode node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main() {
    while (~scanf("%s %s", preOrder, inOrder)) {
        int size = strlen(preOrder);
        Tree tree = createTree(size, 0, 0, size - 1);
        postOrderTraverse(tree);
        printf("\n");
        freeTree(tree);
    }
}