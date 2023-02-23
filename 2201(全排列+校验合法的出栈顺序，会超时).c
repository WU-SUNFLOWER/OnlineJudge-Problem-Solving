#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

int Order[N];
int PushOrder[N];

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

int checkPopOrder(int pop[], int n) {
    int peek;
    int j = 0;
    Stack* stack = createStack(N, sizeof(int));
    for (int i = 0; i < n && j < n; i++) {
        pushToStack(stack, &PushOrder[i]);
        while (j < n && !isEmptyStack(stack) && getPeekFromStack(stack, &peek) && peek == pop[j]) {
            popFromStack(stack, &peek);
            j++;
        }
    }
    int ans = isEmptyStack(stack);
    freeStack(stack);
    return ans;
}

/* 栈模块 结束 */

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void dfs(int ar[], int start, int n) {
    if (start == n - 1 && checkPopOrder(ar, n)) {
        for (int j = 0; j < n; j++) {
            printf(j == n - 1 ? "%d\n" : "%d ", ar[j]);
        }
    } else {
        for (int i = start; i < n; i++) {
            swap(&ar[i], &ar[start]);
            dfs(ar, start + 1, n);
            swap(&ar[i], &ar[start]);
        }        
    }
}

int main() {
    int n;
    int tot;
    scanf("%d", &tot);
    for (int i = 0; i < N; i++) {
        Order[i] = i + 1;
        PushOrder[i] = i + 1;        
    }
    while (tot--) {
        int cnt = 0;
        scanf("%d", &n);
        dfs(Order, 0, n);
    } 
}