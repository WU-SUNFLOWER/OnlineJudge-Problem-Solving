#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
    char code[100];
    char ch;
    Stack* stack = createStack(100, sizeof(char));
    scanf("%s", code);
    for (int i = 0; ch = code[i]; i++) {
        if (ch == '#') {
            popFromStack(stack, &ch);
        }
        else if (ch == '@') {
            clearStack(stack);
        }
        else {
            pushToStack(stack, &ch);
        }
    }
    int idx = 0;
    char ans[100];
    while (!isEmptyStack(stack)) {
        popFromStack(stack, &ans[idx++]);
    }
    for (int i = idx - 1; i >= 0; i--) {
        putchar(ans[i]);
    }
}