#include <stdio.h>
#include <stdlib.h>

typedef struct trnode {
    int val;
    struct trnode* left;
    struct trnode* right;
} *Tree, *TNode;

TNode createTNode(int val) {
    TNode t = (Tree)malloc(sizeof(struct trnode));
    t->val = val;
    t->left = t->right = NULL;
    return t;
}

void insertTNode(Tree root, TNode node) {
    int val = node->val;
    int curVal = root->val;
    if (val < curVal) {
        if (!root->left) {
            root->left = node;
        } else {
            insertTNode(root->left, node);
        }
    } else {
        if (!root->right) {
            root->right = node;
        } else {
            insertTNode(root->right, node);
        }
    }
}

int search(Tree root, int target, int cnt) {
    int curVal = root->val;
    printf(cnt++ ? "->%d" : "%d", curVal);
    if (curVal < target && root->right) {
        return search(root->right, target, cnt);
    }
    else if (curVal > target && root->left) {
        return search(root->left, target, cnt);
    }
    return cnt;
}

void freeTree(Tree root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int total;
    scanf("%d", &total);
    while (total--) {
        int num;
        int target;
        Tree tree = NULL;
        while (~scanf("%d", &num)) {
            if (num == -1) break;
            if (!tree) {
                tree = createTNode(num);
            } else {
                insertTNode(tree, createTNode(num));
            }
        }
        scanf("%d", &target);
        //printf("The path of the comparison:");
        int cnt = search(tree, target, 0);
        //printf("\nThe number of the comparison:%d\n", cnt);
        printf("\n%d\n", cnt);
        freeTree(tree);
    }
}