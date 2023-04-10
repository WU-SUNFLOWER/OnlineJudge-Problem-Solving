#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100

/* 二叉树模块 开始 */
typedef struct trnode {
    int val;
    struct trnode* left;
    struct trnode* right;
} *TNode;

TNode createTNode(int val) {
    TNode node = (TNode)malloc(sizeof(struct trnode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

/* 二叉树模块 结束 */

/* 堆模块 开始 */
typedef TNode ElementType;

typedef struct heap {
    int size;
    ElementType data[N];
    int (*cmp)(const void*, const void*);
} *Heap;

Heap createHeap(int (*cmp)(const void*, const void *)) {
    Heap heap = (Heap)malloc(sizeof(struct heap));
    heap->size = 0;
    heap->cmp = cmp;
    return heap;
}

Heap updateHeap(Heap heap) {
    qsort(heap->data, heap->size, sizeof(ElementType), heap->cmp);
    return heap;
}

Heap pushToHeap(Heap heap, ElementType element, bool needUpdate) {
    heap->data[heap->size++] = element;
    needUpdate && updateHeap(heap);
    return heap;
}

ElementType popFromHeap(Heap heap) {
    ElementType* data = heap->data;
    ElementType ele = data[0];
    for (int i = 1; i < heap->size; i++) {
        data[i - 1] = data[i];
    }
    heap->size--;
    return ele;
}

bool isEmptyHeap(Heap heap) {
    return !heap->size;
}

void freeHeap(Heap heap) {
    free(heap);
}

int cmp(const void* node1, const void* node2) {
    TNode n1 = *(TNode*)node1;
    TNode n2 = *(TNode*)node2;
    return n1->val - n2->val;
}
/* 堆模块 结束 */

/* 哈夫曼树模块 开始 */
TNode buildHuffmanTree(int cnt_node) {
    TNode root = NULL;
    Heap heap = createHeap(cmp);
    // 构造初始节点,并存入最小堆中
    for (int i = 0; i < cnt_node; i++) {
        int temp;
        TNode node;
        scanf("%d", &temp);
        pushToHeap(heap, createTNode(temp), false);
    }
    updateHeap(heap);
    // 构造哈夫曼树
    while (heap->size > 1) {
        TNode node1, node2;
        // 从堆中取出两个节点
        node1 = popFromHeap(heap);
        node2 = popFromHeap(heap);
        // 生成新节点
        root = createTNode(-1);
        root->left = node1;
        root->right = node2;
        root->val = node1->val + node2->val;
        // 将新节点重新压入堆中
        pushToHeap(heap, root, true);
    }
    // 释放堆
    freeHeap(heap);
    // 返回哈夫曼树的根节点
    return root;
}

// 计算带权路径长度和
int getWPL(TNode root, int cnt) {
    if (root->left == NULL && root->right == NULL) {
        return cnt * root->val;
    } else {
        return getWPL(root->left, cnt + 1) + getWPL(root->right, cnt + 1);
    }
}

int getSumCodeLength(TNode root, int cnt) {
    // 碰到根节点
    if (root->left == NULL && root->right == NULL) {
        return cnt;
    }
    // 非根节点
    else {
        return getSumCodeLength(root->left, cnt + 1) + getSumCodeLength(root->right, cnt + 1);
    }
}

// 计算平均编码长度
double getAverageCodeLength(TNode root, int num_leaf) {
    return getSumCodeLength(root, 0) * 1.0 / num_leaf;
}
/* 哈夫曼树模块 结束 */

int main() {
    int t;
    int cnt_node;
    scanf("%d", &t);
    while (t--) {
        int cnt_node;
        TNode tree;
        // 获取节点数
        scanf("%d", &cnt_node);
        // 构造哈夫曼树
        tree = buildHuffmanTree(cnt_node);
        // 计算平均编码长度
        printf("%.3lf\n", getAverageCodeLength(tree, cnt_node));
    }
}