#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100

typedef struct stack {
    int size;
    int data[N];
} *Stack;

Stack createStack() {
    Stack s = (Stack)malloc(sizeof(struct stack));
    s->size = 0;
    return s;
}

void Push(Stack s, int element) {
    s->data[s->size++] = element;
}

int Pop(Stack s) {
    return s->data[--s->size];
}

bool isEmpty(Stack s) {
    return s->size == 0;
}

int getPeak(Stack s) {
    return s->data[s->size - 1];
}

int main() {
    int n;
    int ar[N];
    int popOrder[N];
    while (~scanf("%d", &n) && n > 0) {
        // 初始化
        for (int i = 0; i < n; i++) {
            ar[i] = i + 1;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", popOrder + i);
        }
        Stack s = createStack();
        int idx_ar = 0;
        int idx_popOrder = 0;
        while (idx_ar < n) {
            Push(s, ar[idx_ar++]);
            while (!isEmpty(s) && getPeak(s) == popOrder[idx_popOrder]) {
                idx_popOrder++;
                Pop(s);
            }
        }
        puts(isEmpty(s) ? "Yes" : "No");
    }
}