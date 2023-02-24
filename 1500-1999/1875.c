#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    int size;
    int maxSize;
} Stack;

Stack* createStack(int maxSize) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(sizeof(int) * maxSize);
    stack->size = 0;
    stack->maxSize = maxSize;
    return stack;
}

void freeStack(Stack* stack) {
    free(stack->arr);
    free(stack);
}

Stack* pushToStack(Stack* stack, int ele) {
    if (stack->size < stack->maxSize) {
        stack->arr[stack->size] = ele;
        stack->size++;
    }
    return stack;
}

Stack* popFromStack(Stack* stack) {
    if (stack->size > 0) {
        stack->size--;
        stack->arr[stack->size] = -1;
    }
    return stack;
}

int isEmptyStack(Stack* stack) {
    return !(stack->size);
}

int getPeekFromStack(Stack* stack) {
    if (stack->size <= 0) {
        return -1;
    } else {
        return stack->arr[stack->size - 1];
    }
}

int checkPopOrder(int PushOrder[], int PopOrder[], int n) {
    int j = 0;
    Stack* stack = createStack(100);
    for (int i = 0; i < n; i++) {
        pushToStack(stack, PushOrder[i]);
        while (j < n && !isEmptyStack(stack) && PopOrder[j] == getPeekFromStack(stack)) {
            popFromStack(stack);
            j++;
        }
    }
    return isEmptyStack(stack);
}

int main() {
    int n;
    int PushOrder[100];
    int PopOrder[100];
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) {
            PushOrder[i] = i + 1;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &PopOrder[i]);
        }
        printf(checkPopOrder(PushOrder, PopOrder, n) ? "Yes" : "No");
        putchar('\n');
    }
}