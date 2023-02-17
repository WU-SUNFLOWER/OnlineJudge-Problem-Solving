#include <stdio.h>
#include <stdlib.h>

/* 声明区开始 */
typedef struct trnode {
    char value;
    struct trnode* left;
    struct trnode* right;
} *TNode, *Tree;
/* 声明区结束 */

/*二叉树模块开始*/
Tree buildTree(char str[], int* offset) {
    char value = str[*offset];
    (*offset)++;
    if (value == ' ') {
        return NULL;
    } else {
        TNode node = (TNode)malloc(sizeof(struct trnode));
        node->value = value;
        node->left = buildTree(str, offset);
        node->right = buildTree(str, offset);
        return node;
    }
}

void freeTree(TNode node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

void preOrderTraverse(TNode node, int ansArr[], int* ansIdx, int depth) {
    if (node == NULL) {
        return;
    }
    if (node->left == NULL && node->right == NULL) {
        ansArr[(*ansIdx)++] = depth;
        return;
    }
    preOrderTraverse(node->left, ansArr, ansIdx, depth + 1);
    preOrderTraverse(node->right, ansArr, ansIdx, depth + 1);
}

/* 二叉树模块结束 */

int compare(int* a, int* b) {
    return *b - *a;
}

int main() {
    int t;
    char str[1000];
    int ansArr[1000];  //记录所有叶节点的深度
    scanf("%d", &t);
    getchar();
    while (t-- > 0) {
        int ans;
        int offset = 0;
        int ansIdx = 0;
        //建树
        gets(str);
        Tree tree = buildTree(str, &offset);
        //遍历树的所有叶节点，计算出每个叶节点的深度，并进行排序
        preOrderTraverse(tree, ansArr, &ansIdx, 0);
        qsort(ansArr, ansIdx, sizeof(int), compare);
        //如果当前树有超过一个的叶节点，则答案为最深的两个叶节点深度之和
        //如果当前树只有一个叶节点，则答案为叶节点深度+1
        if (ansIdx > 1) {
            ans = ansArr[0] + ansArr[ansIdx - 1];
        } else {
            ans = ansArr[0] + 1;
        }
        printf("%d\n", ans);
        freeTree(tree);
    }
}