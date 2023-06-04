#include <stdio.h>
#include <stdlib.h>

typedef struct trnode {
    int value;
    struct trnode* left;
    struct trnode* right;
} *TNode;

TNode createTNode(int value) {
    TNode n = (TNode)malloc(sizeof(struct trnode));
    n->value = value;
    n->left = n->right = NULL;
    return n;
}

void Insert(TNode* root, TNode newNode) {
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    if (newNode->value < (*root)->value) {
        Insert(&(*root)->left, newNode);
    } else {
        Insert(&(*root)->right, newNode);
    }
}

void Search(TNode root, int value, int* cnt) {
    (*cnt)++;
    if (root->value == value) {
        return;
    }
    if (value < root->value && root->left != NULL) {
        printf("->%d", root->left->value);
        Search(root->left, value, cnt);
    }
    else if (value > root->value && root->right != NULL) {
        printf("->%d", root->right->value);
        Search(root->right, value ,cnt);
    }
}

void freeTree(TNode root) {
    if (root->left) freeTree(root->left);
    if (root->right) freeTree(root->right);
    free(root);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        int value;
        TNode tree = NULL;
        while (~scanf("%d", &value) && value != -1) {
            Insert(&tree, createTNode(value));
        }
        int target;
        int cnt = 0;
        scanf("%d", &target);
        printf("%d", tree->value);
        Search(tree, target, &cnt);
        printf("\n%d\n", cnt);
        freeTree(tree);
    }
}