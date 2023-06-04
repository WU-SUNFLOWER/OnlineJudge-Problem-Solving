#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct trnode {
    char value;
    struct trnode* left;
    struct trnode* right;
} *TNode;


typedef struct queue {
    int size;
    TNode data[100];
} *Queue;

Queue createQueue() {
    Queue q = (Queue)malloc(sizeof(struct queue));
    q->size = 0;
    return q;
}

void Push(Queue q, TNode ele) {
    q->data[q->size++] = ele;
}

TNode Pop(Queue q) {
    TNode ele = q->data[0];
    for (int i = 1; i <= q->size - 1; i++) {
        q->data[i - 1] = q->data[i];
    }
    q->size--;
    return ele;
}

bool isEmpty(Queue q) {
    return q->size == 0;
}


/*
按照前序遍历次序输入一棵二叉树，碰到空结点以"#"代替。

ab###
ab##c##
*/

TNode createTNode(char val) {
    TNode n = (TNode)malloc(sizeof(struct trnode));
    n->value = val;
    n->left = n->right = NULL;
    return n;
}

TNode BuildTree(char str[], int* idx) {
    char val = str[*idx];
    (*idx)++;
    if (*idx - 1 >= strlen(str) || val == '#') {
        return NULL;
    }
    TNode cur = createTNode(val);
    cur->left = BuildTree(str, idx);
    cur->right = BuildTree(str, idx);
    return cur;
}

void InOrderTraversal(TNode root) {
    if (root->left) InOrderTraversal(root->left);
    printf("%c", root->value);
    if (root->right) InOrderTraversal(root->right);
}

void PostOrderTraversal(TNode root) {
    if (root->left) InOrderTraversal(root->left);
    if (root->right) InOrderTraversal(root->right);
    printf("%c", root->value);
}

void LayerTraversal(TNode root) {
    Queue q = createQueue();
    Push(q, root);
    while (!isEmpty(q)) {
        TNode cur = Pop(q);
        printf("%c", cur->value);
        if (cur->left) Push(q, cur->left);
        if (cur->right) Push(q, cur->right);
    }
    free(q);
}

void FreeTree(TNode root) {
    if (root->left) FreeTree(root->left);
    if (root->right) FreeTree(root->right);
    free(root);
}

int main() {
    char str[100];
    while (~scanf("%s", str)) {
        int idx = 0;
        TNode root = BuildTree(str, &idx);
        InOrderTraversal(root);
        putchar(' ');
        PostOrderTraversal(root);
        putchar(' ');
        LayerTraversal(root);
        putchar('\n');
        FreeTree(root);
    }
}