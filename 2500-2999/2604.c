#include <stdio.h>

char* inorder_traversal(char* tree) {
    char* p = tree;
    // 如果当前节点为根节点
    if (*tree == '#') {
        return tree;
    } else {
        // 遍历左子树
        p = inorder_traversal(tree + 1);
        // 中序输出
        putchar(*tree);
        // 遍历右子树
        p = inorder_traversal(p + 1);
        return p;
    }
}

int main() {
    char tree[100];
    gets(tree);
    inorder_traversal(tree);
}