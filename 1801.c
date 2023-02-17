#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false, true} bool;

typedef struct trnode {
    char value;
    int left;
    int right;
} TNode;

void preOrderTraverse(TNode tree[], int curNodeIdx) {
    if (curNodeIdx == 0) {
        return;
    }
    TNode node = tree[curNodeIdx];
    printf("%c", node.value);
    preOrderTraverse(tree, node.left);
    preOrderTraverse(tree, node.right);
}

void inOrderTraverse(TNode tree[], int curNodeIdx) {
    if (curNodeIdx == 0) {
        return;
    }
    TNode node = tree[curNodeIdx];
    inOrderTraverse(tree, node.left);
    printf("%c", node.value);
    inOrderTraverse(tree, node.right);
}

void postOrderTraverse(TNode tree[], int curNodeIdx) {
    if (curNodeIdx == 0) {
        return;
    }
    TNode node = tree[curNodeIdx];
    postOrderTraverse(tree, node.left);
    postOrderTraverse(tree, node.right);
    printf("%c", node.value);
}

int main() {
    int total;
    // check[i]=0��ʾ��ǰ�ڵ㲻���κνڵ���ӽڵ㣬
    // ��֮��ʾ��ǰ�ڵ���ĳ���ڵ���ӽڵ㡣
    int check[1001];
    TNode tree[1001];
    scanf("%d", &total);
    for (int n = 1; n <= total; n++) {
        // ����
        int nodeNum;
        scanf("%d", &nodeNum);
        memset(check, 0, sizeof(check));
        for (int i = 1; i <= nodeNum; i++) {
            int left, right;
            getchar();
            scanf("%c %d %d", &tree[i].value, &left, &right);
            check[left] = 1;
            check[right] = 1;
            tree[i].left = left;
            tree[i].right = right;
        }
        // ȷ�����ڵ�
        int root = 1;
        while (check[root]) {
            root++;
        }
        //�����������򡢺�������
        printf("Case %d:\n", n);
        preOrderTraverse(tree, root);
        putchar('\n');
        inOrderTraverse(tree, root);
        putchar('\n');
        postOrderTraverse(tree, root);
        putchar('\n');
    }
}