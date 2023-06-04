#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trnode {
    char value;
    struct trnode* left;
    struct trnode* right;
} *TNode;

TNode createTNode(char val) {
    TNode n = (TNode)malloc(sizeof(struct trnode));
    n->value = val;
    n->left = n->right = NULL;
    return n;
}

/*
现在给你一棵二叉树的前序和中序遍历，请你求出这棵二叉树的后序遍历结果

样例输入
BCAD CBAD
ABDGKLRVWSXCEHMNFIOTUJPYQZ KGVRWLSXDBAMHNECTOUIFPYJZQ

样例输出
CDAB
KVWRXSLGDBMNHETUOIYPZQJFCA

*/

TNode BuildTree(char* preOrder, char* inOrder, int len) {
    // 从中序遍历中找出先序遍历的第一个元素，把中序遍历分成两段
    int i;
    for (i = 0; i < len; i++) {
        if (inOrder[i] == preOrder[0]) break;
    }
    TNode curNode = createTNode(preOrder[0]);
    curNode->left = i > 0 ? BuildTree(preOrder + 1, inOrder, i) : NULL;
    curNode->right = len - 1 - i > 0 ? BuildTree(preOrder + 1 + i, inOrder + 1 + i, len - 1 - i) : NULL;
    return curNode;
}

void PostOrderTraversal(TNode root) {
    if (root->left) PostOrderTraversal(root->left);
    if (root->right) PostOrderTraversal(root->right);
    printf("%c", root->value);
}

void FreeTree(TNode root) {
    if (root->left) FreeTree(root->left);
    if (root->right) FreeTree(root->right);
    free(root);
}

int main() {
    char preOrder[100];
    char inOrder[100];
    while (~scanf("%s %s", preOrder, inOrder)) {
        TNode tree = BuildTree(preOrder, inOrder, strlen(preOrder));
        PostOrderTraversal(tree);
        putchar('\n');
        FreeTree(tree);
    }
}