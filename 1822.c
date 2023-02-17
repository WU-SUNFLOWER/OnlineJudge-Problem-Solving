#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

/* ��������ģ�鿪ʼ */

typedef struct hnode {
    int value;
    struct hnode* left;
    struct hnode* right;
} *HNode;

//���ڶѵıȽϺ���
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
    //���������в����ڶ�Ϊ1�Ľڵ㣬�ʲ���Ҫ����node==NULL�����
    //�ݹ鵽Ҷ�ڵ㣬������ݹ�
    if (node->left == NULL && node->right == NULL) {
        return cnt * node->value;
    }
    return getWPL(node->left, cnt + 1) + getWPL(node->right, cnt + 1);
}

/* ��������ģ����� */

/* ��ģ�鿪ʼ */

typedef HNode ElementType;

typedef struct heap {
    ElementType* data;
    int size;
    int maxSize;
    //cmp��������������������Ԫ�ص�λ�ù�ϵ
    //cmp(a, b)=0, ��ʾ����a,bԪ�����λ�ò���
    //cmp(a, b)>0, ��ʾaԪ��ΪbԪ�ص��ӽڵ�
    //cmp(a, b)<0, ��ʾaԪ��ΪbԪ�صĸ��ڵ�
    int (*cmp)(ElementType, ElementType);
} *Heap;

//�����յĶ�
Heap createHeap(int (*cmp)(ElementType, ElementType), int maxSize, ElementType dummy) {
    Heap h = (Heap)malloc(sizeof(struct heap));
    h->size = 0;
    h->cmp = cmp;
    h->maxSize = maxSize;
    h->data = (ElementType*)malloc(sizeof(ElementType) * (maxSize + 1));
    //�����ڱ������ڶ���Ԫ���������Ѷ�ʱ��ʱ�˳�ѭ��
    h->data[0] = dummy;
    return h;
}

//���˶��е�Ԫ�ص�����λ��
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

//���˶��е�Ԫ�ص�ָ��λ��
void shiftUp(Heap h, int idx) {
    ElementType ele = h->data[idx];
    for (; (*h->cmp)(h->data[idx / 2], ele) > 0; idx /= 2) {
        h->data[idx] = h->data[idx / 2];
    }
    h->data[idx] = ele;
}

//��ʼ��data������д���������ݵĶ�
Heap initHeap(Heap h) {
    for (int i = h->size / 2; i >= 1; i--) {
        shiftDown(h, i);
    }
    return h;
}

//�����в���Ԫ��
bool insertToHeap(Heap h, ElementType ele) {
    if (h->size >= h->maxSize) {
        return false;
    }
    h->data[++h->size] = ele;
    shiftUp(h, h->size);
    return true;
}

//����λ�ڶѶ���Ԫ��
ElementType extractFromHeap(Heap h) {
    if (h->size <= 0) {
        return NULL;
    }
    ElementType minEle = h->data[1];
    h->data[1] = h->data[h->size--];
    shiftDown(h, 1);
    return minEle;
}

/* ��ģ����� */

int main() {
    int nodeNum;
    scanf("%d", &nodeNum);
    //����
    Heap heap = createHeap(HNodeCmp, nodeNum, createHNode(-1, NULL, NULL));
    for (int i = 1; i <= nodeNum; i++) {
        int value;
        scanf("%d", &value);
        heap->data[i] = createHNode(value, NULL, NULL);
        heap->size++;
    }
    initHeap(heap);
    //���ɹ�������
    HNode nextNode, newNode;
    HNode curNode = extractFromHeap(heap);
    while (heap->size > 0) {
        nextNode = extractFromHeap(heap);
        newNode = createHNode(curNode->value + nextNode->value, curNode, nextNode);
        insertToHeap(heap, newNode);
        curNode = extractFromHeap(heap);
    }
    //�������������WPLֵ
    printf("%d\n", getWPL(curNode, 0));
}