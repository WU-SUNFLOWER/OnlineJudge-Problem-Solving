#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 110

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
/* 栈模块 结束 */

int main() {
    char ch;
    char str[N];
    Stack* stack = createStack(N, sizeof(char)); 
    gets(str);
    for (int i = 0; ch = str[i]; i++) {
        if (ch == '(') {
            ch = ')';
        } else if (ch == ')') {
            ch = '(';
        }
        pushToStack(stack, &ch);
    }
    while (!isEmptyStack(stack)) {
        popFromStack(stack, &ch);
        putchar(ch);
    }
}