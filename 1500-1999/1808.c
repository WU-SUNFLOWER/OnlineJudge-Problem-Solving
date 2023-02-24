#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 27

typedef struct trnode {
    char value;
    struct trnode* left;
    struct trnode* right;
} *TNode, *Tree;

Tree createTree(char* layerOrder, char* inOrder, int length) {
    if (length <= 0) {
        return NULL;
    }
    // 创建子树根节点
    TNode root = (TNode)malloc(sizeof(struct trnode));
    char rootValue = root->value = layerOrder[0];
    //确定根节点在中序遍历序列中的位置
    int rootIdx;
    for (int i = 0; i < length; i++) {
        if (inOrder[i] == rootValue) {
            rootIdx = i;
            break;
        }
    }
    // 生成左子树和右子树的层序遍历序列
    int k1 = 0; 
    int k2 = 0;
    char leftLayerOrder[N];
    char rightLayerOrder[N];
    for (int i = 1; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (j < rootIdx && layerOrder[i] == inOrder[j]) {
                leftLayerOrder[k1++] = inOrder[j];
                break;
            }
            else if (j > rootIdx && layerOrder[i] == inOrder[j]) {
                rightLayerOrder[k2++] = inOrder[j];
                break;
            }
        }
    }
    // 递归生成左右子树
    root->left = createTree(leftLayerOrder, inOrder, k1);
    root->right = createTree(rightLayerOrder, inOrder + k1 + 1, k2);
    return root;
}

void preOrderTraverse(Tree node) {
    if (node == NULL) {
        return;
    }
    printf("%c", node->value);
    preOrderTraverse(node->left);
    preOrderTraverse(node->right);
}

void postOrderTraverse(Tree node) {
    if (node == NULL) {
        return;
    }
    postOrderTraverse(node->left);
    postOrderTraverse(node->right);
    printf("%c", node->value);
}

void freeTree(Tree tree) {
    if (tree == NULL) {
        return;
    }
    freeTree(tree->left);
    freeTree(tree->right);
    free(tree);
}

int main() {
    int t;
    char layerOrder[N];
    char inOrder[N];
    scanf("%d", &t);
    while (t--) {
        scanf("%s %s", layerOrder, inOrder);
        Tree tree = createTree(layerOrder, inOrder, strlen(inOrder));
        preOrderTraverse(tree);
        putchar('\n');
        postOrderTraverse(tree);
        putchar('\n');
        freeTree(tree);
    }
}