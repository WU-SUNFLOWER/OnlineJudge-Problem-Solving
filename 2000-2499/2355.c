#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct {
    int r;
    int c;
    int val;
} TripleNode;

typedef struct matrix {
    int row;
    int col;
    int size;
    TripleNode data[10];
} *Matrix;

Matrix createMatrix(int row, int col) {
    Matrix m = (Matrix)malloc(sizeof(struct matrix));
    m->row = row;
    m->col = col;
    m->size = 0;
    return m;
}

Matrix addToMatrix(Matrix m, int r, int c, int val) {
    TripleNode* node = m->data + m->size;
    node->r = r;
    node->c = c;
    node->val = val;
    m->size++;
    return m;
}

int main() {
    Matrix m1 = createMatrix(1000, 1000);
    Matrix m2 = createMatrix(1000, 1000);
    Matrix m3 = createMatrix(1000, 1000);
    int r, c, v;
    while (~scanf("%d,%d,%d", &r, &c, &v) && r >= 0) {
        addToMatrix(m1, r, c, v);
    }
    while (~scanf("%d,%d,%d", &r, &c, &v) && r >= 0) {
        addToMatrix(m2, r, c, v);
    }
    TripleNode *node1, *node2, *node3;
    for (int i = 0; i < m1->size; i++) {
        node1 = m1->data + i;
        for (int j = 0; j < m2->size; j++) {
            node2 = m2->data + j;
            if (node1->c != node2->r) continue;
            int mul = node1->val * node2->val;
            int flag = 1;
            for (int k = 0; k < m3->size; k++) {
                node3 = m3->data + k;
                if (node3->r == node1->r && node3->c == node2->c) {
                    node3->val += mul;
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                addToMatrix(m3, node1->r, node2->c, mul);
            }
        }
    }
    if (m3->size) {
        TripleNode node;
        for (int i = 0; i < m3->size; i++) {
            node = m3->data[i];
            printf("%d,%d,%d\n", node.r, node.c, node.val);
        }
    } else {
        puts("No non-zero number exists!");
    }
}