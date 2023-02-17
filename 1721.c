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
    /* ��ʼ������ */
    //�����ڱ��ڵ�
    Node* DummyNode = createNode(0);
    //����ָ����һ���ڵ��ָ��
    Node* LastNode = DummyNode;
    Node* CurNode;
    Node* NextNode;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &value);
        //�����½ڵ�
        CurNode = createNode(value);
        //�޸���һ���ڵ��pointer
        LastNode->pointer = CurNode;
        //����LastNode
        LastNode = CurNode;
    }
    /* ��ת���� */
    CurNode = DummyNode;
    NextNode = CurNode->pointer;
    while (NextNode != NULL) {
        //��ԭ�ȵ�����ָ��ֱ������ԭ�ȵ���������ƶ�һλ
        LastNode = CurNode;
        CurNode = NextNode;
        NextNode = NextNode->pointer;
        //����ǰ�ڵ�CurNode��ԭ�ȵ���һ���ڵ�NextNode�ѹ�
        //��CurNode��ָ��ָ��LastNode
        CurNode->pointer = LastNode;
        //���⴦��ͷ���ڵ�,��ֹ����ѭ������
        if (LastNode->pointer == CurNode) {
            LastNode->pointer = NULL;
        }
    }
    /* ������ */
    while (CurNode->pointer != NULL) {
        printf("%d ", CurNode->value);
        CurNode = CurNode->pointer;
    }
}