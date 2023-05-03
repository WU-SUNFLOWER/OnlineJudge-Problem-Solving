#include <stdio.h>
#include <stdlib.h>
#define N 500

// 将数组调整成最大堆
void percDown(int ar[], int root, int n) {
    int child;
    int parent = root;
    int val = ar[root];
    // 自上而下遍历整棵树，直到访问到倒数第二层的相应节点
    while (parent * 2 + 1 < n) {
        // 先访问左子树
        child = parent * 2 + 1;
        // 如果右子树存在，且右子树根节点携带的值更大，则转向右子树
        // 这一步操作可以找出左右子树根节点携带的最大值
        if (child != n - 1 && ar[child] < ar[child + 1]) {
            child++;
        }
        // 如果子树携带的值比正在下沉的数据更大，则将子树的值移动到根节点
        // 这里相当于交换了根节点和子树的值，
        // 但是由于循环退出后能够一次性安置下沉数据，并且后续的比较都是与val之间比，与当前ar[child]的值无关
        // 所以只需要将ar[parent]的值进行覆盖即可，并不需要真的进行
        if (val < ar[child]) {
            ar[parent] = ar[child];
        }
        // 否则已找到下沉数据的安放位置，停止调整
        else {
            break;
        }
        parent = child;
    }
    // 将下沉数据安放到正确的位置
    ar[parent] = val;
}

void printAr(int ar[], int n) {
    for (int i = 0; i < n; i++) {
        printf(i == n - 1 ? "%d\n" : "%d ", ar[i]);
    }
}

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    int tot;
    int ar[N];
    while (~scanf("%d", &tot)) {
        // 读取数组元素
        for (int i = 0; i < tot; i++) {
            scanf("%d", &ar[i]);
        }
        // 初始化一个最大堆
        for (int i = tot / 2 - 1; i >= 0; i--) {
            percDown(ar, i, tot);
        }
        printAr(ar, tot);
        // 调整堆
        for (int i = tot - 1; i > 0; i--) {
            swap(&ar[0], &ar[i]);
            percDown(ar, 0, i);
            printAr(ar, tot);
        }
    }
}