#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
参考资料：
https://blog.csdn.net/qq_33369979/article/details/109127673
*/

/* 栈模块开始 */
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
    } else {
        printf("error\n");
    }
    return stack;
}

int isEmptyStack(Stack* stack) {
    return !(stack->size);
}

void getPeekFromStack(Stack* stack) {
    if (stack->size <= 0) {
        printf("empty\n");
    } else {
        printf("%d\n", stack->arr[stack->size - 1]);
    }
}

int main() {
    int num;
    char command[100];
    while (~scanf("%d", &num)) {
        int temp;
        Stack* stack = createStack(1000);
        for (int i = 0; i < num; i++) {
            scanf("%s", command);
            if (strcmp(command, "push") == 0) {
                scanf("%d", &temp);
                pushToStack(stack, temp);
            }
            else if (strcmp(command, "pop") == 0) {
                popFromStack(stack);
            }
            else {
                getPeekFromStack(stack);
            }
        }
        freeStack(stack);
        putchar('\n');
    }
}