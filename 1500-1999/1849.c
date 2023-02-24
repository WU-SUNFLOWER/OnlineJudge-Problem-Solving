#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    Stack* stack = createStack(100, sizeof(char));
    char ch;
    char str[100];
    int flag = 1;
    scanf("%s", str);
    for (int i = 0; ch = str[i]; i++) {
        pushToStack(stack, &ch);
    }
    for (int i = 0; ch = str[i]; i++) {
        char _ch;
        popFromStack(stack, &_ch);
        if (_ch != ch) {
            flag = 0;
            break;
        }
    }
    flag && (flag = isEmptyStack(stack));
    printf(flag ? "是回文" : "不是回文");
}