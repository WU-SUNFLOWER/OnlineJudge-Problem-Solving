#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* pointer;
} Node;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->pointer = NULL;
    return node;
}

int main() {
    int value;
    int num;
    /* 初始化链表 */
    //创建哨兵节点
    Node* DummyNode = createNode(0);
    //创建指向上一个节点的指针
    Node* LastNode = DummyNode;
    Node* CurNode;
    Node* NextNode;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &value);
        //创建新节点
        CurNode = createNode(value);
        //修改上一个节点的pointer
        LastNode->pointer = CurNode;
        //更新LastNode
        LastNode = CurNode;
    }
    /* 翻转链表 */
    CurNode = DummyNode;
    NextNode = CurNode->pointer;
    while (NextNode != NULL) {
        //将原先的三个指针分别相对于原先的链表，向后移动一位
        LastNode = CurNode;
        CurNode = NextNode;
        NextNode = NextNode->pointer;
        //将当前节点CurNode与原先的下一个节点NextNode脱勾
        //将CurNode的指针指向LastNode
        CurNode->pointer = LastNode;
        //特殊处理头部节点,防止出现循环引用
        if (LastNode->pointer == CurNode) {
            LastNode->pointer = NULL;
        }
    }
    /* 输出结果 */
    while (CurNode->pointer != NULL) {
        printf("%d ", CurNode->value);
        CurNode = CurNode->pointer;
    }
}