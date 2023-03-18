#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {
    char val;
    struct tree* left;
    struct tree* right;
} *Tree;

Tree createTNode(char val) {
    Tree t = (Tree)malloc(sizeof(struct tree));
    t->val = val;
    t->left = NULL;
    t->right = NULL;
    return t;
}

Tree parseTree(char* exp_pre, char* exp_in, int size) {
    if (size <= 0) {
        return NULL;
    }
    char val = exp_pre[0];
    Tree root = createTNode(val);
    // 从中序序列中找到root节点
    int i;
    for (i = 0; i < size; i++) {
        if (exp_in[i] == val) break;
    }
    // 递归创建左右子树
    root->left = parseTree(exp_pre + 1, exp_in, i);
    root->right = parseTree(exp_pre + i + 1, exp_in + i + 1, size - i - 1);
    return root;
}

void traversalTree(Tree tree) {
    if (!tree) return;
    traversalTree(tree->left);
    traversalTree(tree->right);
    putchar(tree->val);
}

void freeTree(Tree tree) {
    if (!tree) return;
    freeTree(tree->left);
    freeTree(tree->right);
    free(tree);
}

int main() {
    int length;
    Tree tree;
    char exp_pre[100];
    char exp_in[100];
    while (~scanf("%d", &length)) {
        scanf("%s %s", exp_pre, exp_in);
        tree = parseTree(exp_pre, exp_in, strlen(exp_in));
        traversalTree(tree);
        freeTree(tree);
        putchar('\n');
    }
}