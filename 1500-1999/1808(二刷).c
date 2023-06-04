#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 27

typedef struct trnode {
    char value;
    struct trnode* left;
    struct trnode* right;
} *TNode;

TNode createTNode(char value) {
    TNode n = (TNode)malloc(sizeof(struct trnode));
    n->value = value;
    n->left = n->right = NULL;
    return n;
}

TNode BuildTree(char* layerOrder, char* inOrder, int len) {
    // 层序遍历的第一个元素是根节点
    char rv = layerOrder[0];
    TNode root = createTNode(rv);
    // 根据根节点将中序遍历序列分成两半
    int pos;
    for (pos = 0; pos < len; pos++) {
        if (inOrder[pos] == rv) break;
    }
    // 从层序中收集位居左右子树的元素，生成子树的层序序列
    char layerOrder_l[N];
    char layerOrder_r[N];
    int idx_l = 0;
    int idx_r = 0;
    for (int i = 1; i < len; i++) {
        int j;
        char ele = layerOrder[i];
        for (j = 0; j < len; j++) {
            if (ele == inOrder[j]) break;
        }
        // 收集位居左子树的元素
        if (j < pos) {
            layerOrder_l[idx_l++] = ele;
        } 
        // 收集位居右子树的元素
        else {
            layerOrder_r[idx_r++] = ele;
        }
    }
    // 递归生成左右子树
    root->left = pos > 0 ? BuildTree(layerOrder_l, inOrder, pos) : NULL;
    root->right = len - pos - 1 > 0 ? BuildTree(layerOrder_r, inOrder + pos + 1, len - pos - 1) : NULL;
    return root;
}

void preOrderTraversal(TNode root) {
    putchar(root->value);
    if (root->left) preOrderTraversal(root->left);
    if (root->right) preOrderTraversal(root->right);
}

void postOrderTraversal(TNode root) {
    if (root->left) postOrderTraversal(root->left);
    if (root->right) postOrderTraversal(root->right);
    putchar(root->value);
}

void freeTree(TNode root) {
    if (root->left) freeTree(root->left);
    if (root->right) freeTree(root->right);
    free(root);
}

int main() {
    char layerOrder[N];
    char inOrder[N];
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%s %s", layerOrder, inOrder);
        TNode tree = BuildTree(layerOrder, inOrder, strlen(inOrder));
        preOrderTraversal(tree);
        putchar(' ');
        postOrderTraversal(tree);
        putchar('\n');
        freeTree(tree);
    }
    return 0;    
}