#include <stdio.h>
#include <math.h>

void preOrderTraverse(int tree[], int size, int idx) {
    int value = tree[idx];
    if (idx >= size || value == 0) {
        return;
    }
    preOrderTraverse(tree, size, 2 * idx + 1);
    preOrderTraverse(tree, size, 2 * idx + 2);
    printf(" %d", value);
}

int main() {
    int tree[1000];
    int t;
    while (~scanf("%d", &t)) {
        while (t-- > 0) {
            int value;
            int i = 0;
            int layerCnt = 0;
            while (scanf("%d", &value) && value != -1) {
                tree[i++] = value;
                if (i >= pow(2, layerCnt) - 1) {
                    layerCnt++;
                }
            }
            printf("%d", layerCnt);
            preOrderTraverse(tree, i, 0);
            printf("\n");
        }
    }
}