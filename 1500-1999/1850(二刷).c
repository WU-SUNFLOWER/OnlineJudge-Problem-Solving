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

void dfs(Stack s, int queue[], int ans[], int n, int idx_queue, int idx_ans) {
    // 当所有元素都已经出过栈了,则输出答案并结束递归
    if (idx_ans == n) {
        for (int i = 0; i < n; i++) {
            printf(i == n - 1 ? "%d\n" : "%d ", ans[i]);
        }
        return;
    }
    // 第一种情况：栈为空，则只能入栈
    if (isEmpty(s)) {
        Push(s, queue[idx_queue]);
        dfs(s, queue, ans, n, idx_queue + 1, idx_ans);
        Pop(s);
    }
    // 第二种情况：所有元素都已经入栈，则只能出栈
    else if (idx_queue == n) {
        int temp = ans[idx_ans] = Pop(s);
        dfs(s, queue, ans, n, idx_queue, idx_ans + 1);
        Push(s, temp);
    }
    // 第三种情况：入栈和出栈都尝试一下
    else {
        // 出栈
        int temp = ans[idx_ans] = Pop(s);
        dfs(s, queue, ans, n, idx_queue, idx_ans + 1);
        Push(s, temp);
        // 入栈
        Push(s, queue[idx_queue]);
        dfs(s, queue, ans, n, idx_queue + 1, idx_ans);
        Pop(s);
    }
}

int main() {
    int n;
    int queue[N];
    int ans[N];
    Stack s = createStack();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", queue + i);
    }
    // Stack s, int queue[], int ans[], int n, int idx_queue, int idx_ans
    dfs(s, queue, ans, n, 0, 0);
    return 0;
}