#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

/* 哈夫曼树模块开始 */

typedef struct hnode {
    int value;
    struct hnode* left;
    struct hnode* right;
} *HNode;

//用于堆的比较函数
int HNodeCmp(HNode a, HNode b) {
    return a->value - b->value;
}

HNode createHNode(int value, HNode left, HNode right) {
    HNode node = (HNode)malloc(sizeof(struct hnode));
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

int getWPL(HNode node, int cnt) {
    //哈夫曼树中不存在度为1的节点，故不需要考虑node==NULL的情况
    //递归到叶节点，则结束递归
    if (node->left == NULL && node->right == NULL) {
        return cnt * node->value;
    }
    return getWPL(node->left, cnt + 1) + getWPL(node->right, cnt + 1);
}

/* 哈夫曼树模块结束 */

/* 堆模块开始 */

typedef HNode ElementType;

typedef struct heap {
    ElementType* data;
    int size;
    int maxSize;
    //cmp函数用于描述堆中两个元素的位置关系
    //cmp(a, b)=0, 表示保持a,b元素相对位置不变
    //cmp(a, b)>0, 表示a元素为b元素的子节点
    //cmp(a, b)<0, 表示a元素为b元素的父节点
    int (*cmp)(ElementType, ElementType);
} *Heap;

//建立空的堆
Heap createHeap(int (*cmp)(ElementType, ElementType), int maxSize, ElementType dummy) {
    Heap h = (Heap)malloc(sizeof(struct heap));
    h->size = 0;
    h->cmp = cmp;
    h->maxSize = maxSize;
    h->data = (ElementType*)malloc(sizeof(ElementType) * (maxSize + 1));
    //设置哨兵，便于堆中元素上滤至堆顶时及时退出循环
    h->data[0] = dummy;
    return h;
}

//下滤堆中的元素到合适位置
void shiftDown(Heap h, int idx) {
    int parent;
    int child;
    ElementType ele = h->data[idx];
    for (parent = idx; parent * 2 <= h->size; parent = child) {
        child = parent * 2;
        if (child < h->size && (*h->cmp)(h->data[child], h->data[child + 1]) > 0) {
            child = child + 1;
        }
        if ((*h->cmp)(h->data[child], ele) >= 0) {
            break;
        } else {
            h->data[parent] = h->data[child];
        }
    }
    h->data[parent] = ele;
}

//上滤堆中的元素到指定位置
void shiftUp(Heap h, int idx) {
    ElementType ele = h->data[idx];
    for (; (*h->cmp)(h->data[idx / 2], ele) > 0; idx /= 2) {
        h->data[idx] = h->data[idx / 2];
    }
    h->data[idx] = ele;
}

//初始化data数组已写入乱序内容的堆
Heap initHeap(Heap h) {
    for (int i = h->size / 2; i >= 1; i--) {
        shiftDown(h, i);
    }
    return h;
}

//往堆中插入元素
bool insertToHeap(Heap h, ElementType ele) {
    if (h->size >= h->maxSize) {
        return false;
    }
    h->data[++h->size] = ele;
    shiftUp(h, h->size);
    return true;
}

//弹出位于堆顶的元素
ElementType extractFromHeap(Heap h) {
    if (h->size <= 0) {
        return NULL;
    }
    ElementType minEle = h->data[1];
    h->data[1] = h->data[h->size--];
    shiftDown(h, 1);
    return minEle;
}

/* 堆模块结束 */

int main() {
    int nodeNum;
    scanf("%d", &nodeNum);
    //建堆
    Heap heap = createHeap(HNodeCmp, nodeNum, createHNode(-1, NULL, NULL));
    for (int i = 1; i <= nodeNum; i++) {
        int value;
        scanf("%d", &value);
        heap->data[i] = createHNode(value, NULL, NULL);
        heap->size++;
    }
    initHeap(heap);
    //生成哈夫曼树
    HNode nextNode, newNode;
    HNode curNode = extractFromHeap(heap);
    while (heap->size > 0) {
        nextNode = extractFromHeap(heap);
        newNode = createHNode(curNode->value + nextNode->value, curNode, nextNode);
        insertToHeap(heap, newNode);
        curNode = extractFromHeap(heap);
    }
    //计算哈夫曼树的WPL值
    printf("%d\n", getWPL(curNode, 0));
}