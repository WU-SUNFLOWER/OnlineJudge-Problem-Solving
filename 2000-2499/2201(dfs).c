#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

/* 栈模块 开始 */
typedef struct {
    void* arr;
    int size;
    int maxSize;
    int elemSize;
} Stack;

Stack* createStack(int maxSize, int elemSize) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = malloc(elemSize * maxSize);
    stack->size = 0;
    stack->maxSize = maxSize;
    stack->elemSize = elemSize;
    return stack;
}

void freeStack(Stack* stack) {
    free(stack->arr);
    free(stack);
}

Stack* pushToStack(Stack* stack, void* elemAddr) {
    if (stack->size < stack->maxSize) {
        int elemSize = stack->elemSize;
        void* targetAddr = stack->arr + stack->size * elemSize;
        memcpy(targetAddr, elemAddr, elemSize);
        stack->size++;
    }
    return stack;
}

Stack* popFromStack(Stack* stack, void* elemAddr) {
    if (stack->size > 0) {
        stack->size--;
        int elemSize = stack->elemSize;
        void* targetAddr = stack->arr + stack->size * elemSize;
        memcpy(elemAddr, targetAddr, elemSize);
    }
    return stack;
}

int isEmptyStack(Stack* stack) {
    return !(stack->size);
}

Stack* getPeekFromStack(Stack* stack, void* elemAddr) {
    if (stack->size > 0) {
        int elemSize = stack->elemSize;
        void* targetAddr = stack->arr + (stack->size - 1) * elemSize;
        memcpy(elemAddr, targetAddr, elemSize);
    }
    return stack;
}

Stack* clearStack(Stack* stack) {
    stack->size = 0;
    return stack;
}

/* 栈模块 结束 */

int PushOrder[N];
int PopOrder[N];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/*
    每层dfs需要考虑两种情况：
    1. 让一个元素入栈
    2. 让一个元素出栈

    i指针用于指向PushOrder中即将入栈的元素
    j指针用于指向PushOrder中即将存放入栈元素的位置
*/

void dfs(Stack* stack, int i, int j, int n) {
    // 退出dfs
    // 为了确保有足够的机会让程序尝试pop
    // 结束dfs的条件i>=n和j>=n缺一不可！！！
    if (i >= n && j >= n) {
        if (isEmptyStack(stack)) {
            for (int k = 0; k < n; k++) {
                printf(k == n - 1 ? "%d\n" : "%d ", PopOrder[k]);
            }
        }
        return;
    }
    // 尝试出栈一个元素
    int temp;
    if (!isEmptyStack(stack) && j < n) {
        popFromStack(stack, &temp);
        PopOrder[j] = temp;
        dfs(stack, i, j + 1, n);
        // 回溯
        pushToStack(stack, &temp);
    }
    // 尝试入栈一个元素
    if (i < n) {
        temp = PushOrder[i];
        pushToStack(stack, &temp);
        dfs(stack, i + 1, j, n);
        // 回溯
        popFromStack(stack, &temp);        
    }
}

int main() {
    int n;
    int tot;
    scanf("%d", &tot);
    for (int i = 0; i < N; i++) {
        PushOrder[i] = i + 1;
    }
    while (tot--) {
        int cnt = 0;
        Stack* stack = createStack(N, sizeof(int));
        scanf("%d", &n);
        dfs(stack, 0, 0, n);
        freeStack(stack);
    }
}